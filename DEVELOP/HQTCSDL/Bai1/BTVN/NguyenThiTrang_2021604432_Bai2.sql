create database QLBanHang
go
use QLBanHang

create table CongTy (
	MaCT nchar(10) primary key,
	TenCT nvarchar(40) not null,
	TrangThai nvarchar(20) not null,
	ThanhPho nvarchar(40) not null
)

create table SamPham(
	MaSP nchar(10) primary key,
	TenSP nvarchar(40) not null,
	unique(TenSP),
	MauSac nvarchar(20) default(N'đỏ'),
	Gia money not null,
	SoluongCo int not null
)

create table Cungung (
	MaCT nchar(10),
	MaSP nchar(10),
	constraint fk_ct_cu foreign key(MaCT)
	references CongTy(MaCT),
	constraint fk_sp_cu 
	foreign key(MaSP)
	references SamPham(MaSP),
	SoLuongBan int not null,
	check(SoLuongBan > 0),
	constraint pk_cu primary key(MaCT, MaSP)
)

insert into CongTy 
values('D01', 'SamSung1', '100', N'Hà Nội'),
	  ('D02', 'FPT', '200', N'TP Hồ Chí Minh'),
	  ('D03', 'Viettel', '50', N'Hà Nội')



insert into SamPham
values('SP01',N'Bánh Mì', N'Đỏ', 15, 20),
	  ('SP02',N'Quần áo', N'Đỏ', 20, 5),
	  ('SP03', N'Giày', N'Tím', 15, 21)




insert into Cungung
values('D01','SP01',50),
	  ('D01','SP02',60),
	  ('D02','SP03',15),
	  ('D02','SP01',42),
	  ('D03','SP02',18),
	  ('D03','SP03',16)


select * from CongTy
select * from SamPham
select * from Cungung