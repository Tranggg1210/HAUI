create database QLBanHang
go
use QLBanHang

create table HangSX (
	MaHangSX nchar(10) primary key,
	TenHang nvarchar(30) not null,
	DiaChi nvarchar(40) not null,
	SoDT nchar(20) not null,
	Email varchar(40) not null
)

create table Sanpham (
	MaSP nchar(10) primary key, 
	MaHangSX nchar(10),
	foreign key(MaHangSX) references HangSX(MaHangSX),
	TenSP nvarchar(30) not null,
	SoLuong int not null,
	MauSac nvarchar(20) not null,
	GiaBan money not null,
	DonViTinh nvarchar(30) not null,
	MoTa nvarchar(40) not null
)



create table NhanVien (
	MaNV nchar(10) primary key,
	TenNV nvarchar(30) not null,
	GioiTinh nvarchar(40) not null,
	DiaChi nvarchar(40) not null,
	SoDT nchar(20) not null,
	Email varchar(40) not null,
	TenPhong nvarchar(30) not null,
)

create table PNhap (
	SoHDN nchar(10) primary key,
	NgayNhap date not null,
	MaNV nchar(10),
	foreign key(MaNV) references NhanVien(MaNV)
)

create table Nhap (
	SoHDN nchar(10),
	foreign key(SoHDN) references PNhap(SoHDN),
	MaSP nchar(10),
	foreign key(MaSP) references SanPham(MaSP),
	SoLuongN int not null,
	DonGiaN money not null,
	constraint pk_Nhap
	primary key (SoHDN, MaSP)
)

create table PXuat (
	SoHDX nchar(10) primary key,
	NgayXuat date not null,
	MaNV nchar(10),
	foreign key(MaNV) references NhanVien(MaNV)
)

create table Xuat (
	SoHDX nchar(10),
	foreign key(SoHDX) references PXuat(SoHDX),
	MaSP nchar(10),
	foreign key(MaSP) references SanPham(MaSP),
	SoLuongX int not null,
	constraint pk_Xuat
	primary key (SoHDX, MaSP)
)

insert into HangSX 
values('SX_01', 'Samsung', N'Hà Nội', '0123456789', 'ss@gmail.com.vn'),
	  ('SX_02', 'Viettel', N'Hà Tây', '0123456987', 'vt@gmail.com.vn'),
	  ('SX_03', 'Oppo', N'Hà Nam', '0456789123', 'oppo@gmail.com.vn')

insert into Sanpham
values('SP01', 'SX_02', N'Bánh táo', 15, N'Vàng', 200000, N'Chiếc', N'Hàng cao cấp loại 1'),
	  ('SP02', 'SX_03', N'Bánh cam', 25, N'Cam', 456200, N'Chiếc', N'Hàng cao cấp loại 3'),
	  ('SP03', 'SX_01', N'Bánh quy', 23, N'Hồng', 18000, N'Chiếc', N'Hàng cao cấp loại 2'),
	  ('SP04', 'SX_03', N'Bánh mít', 42, N'Vàng', 1250000, N'Chiếc', N'Hàng cao cấp loại 4'),
	  ('SP05', 'SX_02', N'Bánh dứa', 12, N'Vàng chanh', 80000, N'Chiếc', N'Hàng cao cấp loại 6'),
	  ('SP06', 'SX_02', N'Bánh mì', 10, N'Vàng đậm', 70000, N'Chiếc', N'Hàng cao cấp loại 9'),
	  ('SP07', 'SX_01', N'Bánh trứng', 11, N'Vàng tây', 160000, N'Chiếc', N'Hàng phổ thông'),
	  ('SP09', 'SX_01', N'Bánh gato', 29, N'Trắng', 205000, N'Chiếc', N'Hàng loại thấp'),
	  ('SP10', 'SX_01', N'Bánh chanh', 30, N'Trắng xanh', 210000, N'Chiếc', N'Hàng cao cấp loại 5')

insert into Sanpham
values('SP08', 'SX_02', N'Bánh hoa', 16, N'Vàng', 2007000, N'Chiếc', N'Hàng cao cấp loại 1'),
	  ('SP11', 'SX_01', N'Bánh canh', 22, N'Cam', 456600, N'Chiếc', N'Hàng cao cấp loại 4')
	

insert into NhanVien
values('NV01', N'Hà Phương Lan', N'Nữ', N'Hà Nội', '0123587964','pl@gmail.com', N'Phòng bếp'),
	  ('NV02', N'Nguyễn Thị Phương', N'Nữ', N'Hà Tây', '01235845678','np@gmail.com', N'Phòng sales'),
	  ('NV03', N'Nguyễn Văn Anh', N'Nam', N'Hà Nam', '01234565678','na@gmail.com', N'Phòng quản lý')

insert into PNhap 
values('PN01','08-20-2020','NV02'),
	  ('PN02','06-18-2018','NV01'),
	  ('PN03','01-01-2019','NV02'),
	  ('PN04','10-12-2019','NV03'),
	  ('PN05','07-15-2019','NV03')

insert into Nhap
values('PN01', 'SP03', 56, 200000),
	  ('PN02', 'SP10', 125, 140000),
	  ('PN03', 'SP02', 565, 2560000),
	  ('PN04', 'SP09', 69, 500000),
	  ('PN05', 'SP07', 70, 10000000)

insert into PXuat
values('PX01','05-24-2020','NV02'),
	  ('PX02','06-14-2018','NV01'),
	  ('PX03','09-01-2020','NV03'),
	  ('PX04','03-12-2020','NV02'),
	  ('PX05','12-1-2020','NV01')

insert into PXuat
values('PX06','06-14-2020','NV02'),
	  ('PX07','06-14-2020','NV01')

insert into PXuat
values('PX08','02-03-2020','NV02'),
	  ('PX09','02-03-2020','NV02')
	 

insert into Xuat
values('PX01', 'SP03', 3),
	  ('PX02', 'SP05', 14),
	  ('PX03', 'SP02', 12),
	  ('PX03', 'SP09', 20),
	  ('PX02', 'SP07', 9)


insert into Xuat
values('PX06', 'SP03', 3),
	  ('PX07', 'SP05', 14),
	  ('PX07', 'SP02', 12)

insert into Xuat
values('PX06', 'SP04', 30000),
	  ('PX07', 'SP06', 14000),
	  ('PX07', 'SP03', 12000)

insert into Xuat
values('PX08', 'SP02', 30000),
	  ('PX09', 'SP02', 14000)

/*a (2.5đ). Đưa ra 10 mặt hàng có SoLuongN nhiều nhất trong năm 2019*/
select top 10 Sanpham.MaSP, MaHangSX, TenSP, SoLuong, MauSac, GiaBan, 
			  DonViTinh, MoTa, SoLuongN
from Sanpham inner join Nhap
				   on Nhap.MaSP = Sanpham.MaSP
			 inner join PNhap
				   on PNhap.SoHDN = Nhap.SoHDN

where year(NgayNhap) = 2019

/*b (2.5đ). Đưa ra MaSP,TenSP của các sản phẩm do công ty ‘Samsung’ sản xuất do nhân
viên có mã ‘NV01’ nhập.*/
select Nhap.MaSP,TenSP
from Nhap inner join PNhap
				on PNhap.SoHDN = Nhap.SoHDN
		  inner join Sanpham
				on Sanpham.MaSP = Nhap.MaSP
		  inner join HangSX
				on HangSX.MaHangSX = Sanpham.MaHangSX
where MaNV = 'NV01' and TenHang = 'Samsung'

/*c (2.5đ). Đưa ra SoHDN,MaSP,SoLuongN,ngayN của mặt hàng có MaSP là ‘SP02’,
được nhân viên ‘NV02’ nhập.*/
select Nhap.SoHDN,MaSP,SoLuongN,NgayNhap
from Nhap inner join PNhap
				on PNhap.SoHDN = Nhap.SoHDN
where MaNV = 'NV02' and MaSP = 'SP02'

/*d (2.5đ). Đưa ra manv,TenNV đã xuất mặt hàng có mã ‘SP02’ ngày ‘03-02-2020’*/
select NhanVien.MaNV,TenNV
from NhanVien inner join PXuat
					on PXuat.MaNV = NhanVien.MaNV
			  inner join Xuat
					on Xuat.SoHDX = PXuat.SoHDX
where MaSP = 'SP02' and NgayXuat = '02-03-2020'
