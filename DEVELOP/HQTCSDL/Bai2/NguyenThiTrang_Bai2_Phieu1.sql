create database QLBH
go
use QLBH

create table HangSX(
	MaHangSX nchar(10) primary key,
	TenHang nvarchar(20) not null,
	DiaChi nvarchar(30) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(30) not null
)

create table SanPham(
	MaSP nchar(10) primary key,
	MaHangSX nchar(10) not null,
	constraint fk_HangSX_SP
	foreign key(MaHangSX)
	references HangSx(MaHangSX),
	TenSP nvarchar(20) not null,
	SoLuong int not null,
	MauSac nvarchar(20) not null,
	GiaBan money not null,
	DonViTinh nchar(10) not null,
	MoTa nvarchar(max) not null
)

create table NhanVien (
	MaNV nchar(10) primary key,
	TenNV nvarchar(20) not null,
	GioiTinh nchar(10) not null,
	DiaChi nvarchar(30) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(30) not null,
	TenPhong nvarchar(30) not null
)

create table PNhap (
	SoHDN nchar(10) primary key,
	NgayNhap date not null,
	MaNV nchar(10) not null,
	constraint fk_NV_PNhap
	foreign key (MaNV)
	references NhanVien(MaNV)
)

create table Nhap (
	SoHDN nchar(10),
	constraint fk_Pnhap_Nhap
	foreign key (SoHDN)
	references PNhap(SoHDN),
	MaSP nchar(10),
	constraint fk_SP_Nhap
	foreign key (MaSP)
	references SanPham(MaSP),
	constraint pk_Nhap
	primary key (SoHDN, MaSP),
	SoLuongN int not null,
	DonGiaN money not null
)

create table PXuat (
	SoHDX nchar(10) primary key,
	NgayXuat Date not null,
	MaNV nchar(10) not null,
	constraint fk_NV_PXuat
	foreign key (MaNV)
	references NhanVien(manv)
)

create table Xuat (
	SoHDX nchar(10) ,
	constraint fk_PXuat_Xuat
	foreign key (SoHDX)
	references PXuat(SoHDX),
	MaSP nchar(10),
	constraint fk_SP_Xuat
	foreign key(MaSP)
	references SanPham(MaSP),
	SoLuongX int not null
)

insert into HangSX 
values ('HSX01', N'Samsung', N'Hà Nội', '0123456789', 'ss.@gmail.com'),
	   ('HSX02', N'FPT', N'Hà Tây', '0123478965', 'fpt.@gmail.com'),
	   ('HSX03', N'MISA', N'Hải Dương', '0451236789', 'ss.@gmail.com')

insert into SanPham
values ('SP01','HSX01', N'Kẹo',15, N'Đỏ','20', 'kg', N'ngọt'),
	   ('SP02','HSX01', N'Bánh',10, N'Trắng','105', 'cái', N'ngọt'),
	   ('SP03','HSX03', N'Táo',35, N'Xanh','28', 'kg', N'ngọt')

insert into NhanVien
values ('NV01', N'Trang', N'nữ', N'Hà Nội', '0123456789', 'ss.@gmail.com', N'Kế toán'),
	   ('NV02', N'Lan',N'nữ', N'Hà Tây', '0123478965', 'fpt.@gmail.com', N'Tài Chính'),
	   ('NV03', N'Anh', N'nam',N'Hải Dương', '0451236789', 'ss.@gmail.com', N'sale')

insert into PNhap
values ('PN01', '10-12-2022', 'NV01'),
	   ('PN02', '02-30-2022', 'NV03'),
	   ('PN03', '09-28-2022', 'NV02')

insert into Nhap
values ('PN01','SP01',19, '20'),
	   ('PN03','SP02',19, '12'),
	   ('PN02','SP03',39, '25')

insert into PXuat
values ('PX01', '10-12-2022', 'NV01'),
	   ('PX02', '02-30-2022', 'NV03'),
	   ('PX03', '09-28-2022', 'NV02')

insert into Xuat
values ('PX01', 'SP01', 20),
	   ('PX02', 'SP03',12),
	   ('PX03', 'SP02',23)


select * from HangSX
select * from SanPham
select * from NhanVien
select * from PNhap
select * from Nhap
select * from PXuat
select * from Xuat