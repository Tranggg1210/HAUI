create database QLKHO
go
use QLKHO

create table Ton (
	MaVT nchar(10) primary key,
	TenVT nvarchar(40) not null,
	SoLuongT int not null
)

create table Nhap (
	SoHDN nchar(10),
	MaVT nchar(10),
	SoLuongN int not null,
	DonGiaN money not null,
	NgayN datetime not null,
	foreign key(MaVT) references Ton(MaVT),
	constraint pk_Nhap
	primary key(SoHDN, MaVT)
)

create table Xuat (
	SoHDX nchar(10),
	MaVT nchar(10),
	SoLuongX int not null,
	DonGiaX money not null,
	NgayX datetime not null,
	foreign key(MaVT) references Ton(MaVT),
	constraint pk_Xuat
	primary key(SoHDX, MaVT)
)

insert into Ton
values('VT01', N'Bút bi',125),
	  ('VT02', N'Bút chì',15),
	  ('VT03', N'Bút máy',1025),
	  ('VT04', N'Bút dạ',255),
	  ('VT05', N'Bút nhớ',365)

insert into Nhap
values('PN01','VT03', 150, 15000, '02-04-2022'),
	  ('PN02','VT05', 789, 10500, '08-22-2020'),
	  ('PN03','VT01', 456, 6000, '09-12-2022')

insert into Xuat
values('PX01','VT02', 10, 56000, '08-10-2022'),
	  ('PX02','VT03', 35, 20500, '09-12-2021')



/*Bài 2 (2đ). Thống kê tiền bán theo mã vật tư gồm MaVT, TenVT, TienBan
(TienBan=SoLuongX*DonGiaX) */

create view TK_tienban
as
select Ton.MaVT, TenVT, sum(SoLuongX * DonGiaX) TienBan
from Ton inner join Xuat
				on Xuat.MaVT = Ton.MaVT
group by Ton.MaVT, TenVT


select * from TK_tienban



/*Bài 3 (2đ). Thống kê soluongxuat theo tên vattu*/
create view bai3
as
select TenVT vattu, sum(SoLuongX) soluongxuat
from Ton inner join Xuat
				on Xuat.MaVT = Ton.MaVT
group by TenVT


--Test
select * from bai3


/*Bài 4 (2đ). Thống kê soluongnhap theo tên vật tư*/
create view bai4
as
select TenVT, sum(SoLuongN) soluongnhap
from Ton inner join Nhap
				on Nhap.MaVT = Ton.MaVT
group by TenVT

-- test
select * from bai4


/*Bài 5 (2đ). Đưa ra tổng soluong còn trong kho biết còn = nhap – xuất + tồn theo
từng nhóm vật tư*/
create view bai5
as
select Ton.MaVT,TenVT, 
	   (sum(SoLuongN) - sum(SoLuongX) + sum(SoLuongT)) soluong
from Ton inner join Xuat
				on Xuat.MaVT = Ton.MaVT
		 inner join Nhap
				on Nhap.MaVT = Ton.MaVT
group by Ton.MaVT,TenVT


--test
select * from bai5
