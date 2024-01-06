create database QLKHO
go
use QLKHO

create table Ton (
	MaVT nchar(10) primary key,
	TenVT nvarchar(40) not null,
	SoLuongT int not null
)


create table Nhap(
	SoHDN nchar(10),
	MaVT nchar(10),
	SoLuongN int not null,
	DonGiaN money not null,
	NgayN date not null,
	primary key(SoHDN,MaVT)
)

create table Xuat(
	SoHDX nchar(10),
	MaVT nchar(10),
	SoLuongX int not null,
	DonGiaX money not null,
	NgayX date not null,
	primary key(SoHDX,MaVT)
)

/*
b (2đ). ở bảng nhập hãy nhập 3 phiếu nhập, ở bảng xuất nhập 2 phiếu xuất.
c (2đ). bảng Ton nhập 5 vật tư khác nhau.

*/

insert into Ton 
values('VT01', N'Ti Vi', 15),
	  ('VT02', N'Tủ lạnh', 2),
	  ('VT03', N'Máy giặt', 9),
	  ('VT04', N'Lò vi sóng', 18),
	  ('VT05', N'Máy sấy', 32)

insert into Nhap
values('HDN01','VT01', 18, 200000, '03-02-2017'),
	  ('HDN02','VT03', 20, 2500000, '05-12-2018'),
	  ('HDN03','VT01', 165, 200000, '08-30-2019')

insert into Xuat
values('HDX01','VT01', 6, 300000, '05-09-2017'),
	  ('HDX02','VT03', 5, 3500000, '11-6-2018')


select * from Ton
select * from Nhap
select * from Xuat

--Câu 2 (1đ). đưa ra tên vật tư số lượng tồn nhiều nhất
select TenVT
from Ton
where SoLuongT = (
					select MAX(SoLuongT)
					from Ton
)

--Câu 3 (1đ). đưa ra các vật tư có tổng số lượng xuất lớn hơn 100
select Ton.MaVT, TenVT, SoLuongT
from Ton inner join Xuat
			   on Xuat.MaVT = Ton.MaVT
group by Ton.MaVT, TenVT, SoLuongT
having sum(SoLuongX) > 100

/*
Câu 4 (1đ). Tạo view đưa ra tháng xuất, năm xuất, tổng số lượng xuất thống kê theo
tháng và năm xuất
*/

create view cau4
as
select MONTH(NgayX) as N'Tháng xuất', YEAR(NgayX) as N'Năm xuất', sum(SoLuongX) as N'Số lượng xuất '
from Xuat
group by MONTH(NgayX), YEAR(NgayX)

drop view cau4

select * from cau4

/*
Câu 5 (2đ). Tạo view đưa ra mã vật tư. tên vật tư. số lượng nhập. số lượng xuất. đơn
giá N. đơn giá X. ngày nhập. Ngày xuất.
*/

create view cau5
as
select Nhap.MaVT, TenVT, SoLuongN, SoLuongX, DonGiaN,
	   DonGiaX, NgayN, NgayX
from Ton inner join Nhap on Nhap.MaVT = Ton.MaVT
		 inner join Xuat on Xuat.MaVT = Ton.MaVT

select * from cau5

/*
Câu 6 (2đ). Tạo view đưa ra mã vật tư. tên vật tư và tổng số lượng còn lại trong kho.
biết còn lại = SoluongN-SoLuongX+SoLuongT theo từng loại Vật tư trong năm
2015
*/

create view cau6 
as
select Xuat.MaVT, TenVT, sum(SoLuongN - SoLuongX + SoLuongT) as N'Tổng số lượng trong kho'
from Ton inner join Nhap on Nhap.MaVT = Ton.MaVT
		 inner join Xuat on Xuat.MaVT = Ton.MaVT
where Year(NgayX) = 2015 and Year(NgayN) =  2015
group by Xuat.MaVT, TenVT

select * from cau6