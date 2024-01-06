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

/*d (2đ). Xóa các vật tư có DonGiaX < DonGiaN*/
delete Ton 
where MaVT in (
	select Xuat.MaVT
	from Nhap inner join Xuat
					on Xuat.MaVT = Nhap.MaVT
	where DonGiaX < DonGiaN
)

select * from Ton
select * from Nhap
select * from Xuat

--e (2đ). Cập nhật NgayX = NgayN nếu NgayX < NgayN của các mặt hàng có MaVT
--giống nhau.

update Xuat
set NgayX = Nhap.NgayN
from Xuat inner join Nhap 
				on Nhap.MaVT = Xuat.MaVT
where Xuat.NgayX < Nhap.NgayN
