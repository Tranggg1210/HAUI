create database QLBanHang
go
use QLBanHang

create table HangSX (
	MaHangSX nchar(10) primary key,
	TenHang nvarchar(30) not null,
	DiaChi nvarchar(40) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(40) not null
)



create table SanPham (
	MaSP nchar(10) primary key,
	MaHangSX nchar(10),
	foreign key(MaHangSX) references HangSX(MaHangSX),
	TenSP nvarchar(30) not null,
	SoLuong int not null,
	MauSac nvarchar(15) not null,
	GiaBan money not null,
	DonViTinh nvarchar(20),
	MoTa nvarchar(40)
)


create table NhanVien (
	MaNV nchar(10) primary key,
	TenNV nvarchar(40) not null,
	GioiTinh nvarchar(10) not null,
	DiaChi nvarchar(40) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(40) not null,
	TenPhong nvarchar(40) not null
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
	primary key(SoHDN, MaSP)
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
	primary key(SoHDX, MaSP)
)

insert into HangSX
values('H01','SamSung',N'Hà Nội', '0123456789', 'ss@gmail.com.vn'),
      ('H02','Oppo',N'Hà Tây', '0456123789', 'oppo@gmail.com.vn'),
	  ('H03','Viettel',N'Hà Nam', '0123789456', 'vt@gmail.com.vn')

insert into SanPham
values('SP01', 'H01', N'Bánh mì', 15, N'vàng', 125000, N'Chiếc', N'Hàng cao cấp loại 1'),
	  ('SP02', 'H02', N'Bánh táo', 20, N'cam', 125600, N'Chiếc', N'Hàng cao cấp  loại 3'),
	  ('SP03', 'H02', N'Bánh trứng', 16, N'vàng', 425000, N'Chiếc', N'Hàng cao cấp loại 2'),
	  ('SP04', 'H03', N'Bánh tráng', 12, N'trắng đỏ', 1125000, N'Chiếc', N'Hàng phổ thông'),
	  ('SP05', 'H01', N'Bánh kem', 8, N'trắng', 1255000, N'Chiếc', N'Hàng cao cấp loại 4'),
	  ('SP06', 'H02', N'Bánh bông lan', 17, N'vàng đậm', 65000, N'Chiếc', N'Hàng cao cấp loại 5'),
	  ('SP07', 'H01', N'Bánh khoai', 125, N'tím', 555000, N'Chiếc', N'Hàng cao cấp loại 9'),
	  ('SP08', 'H01', N'Bánh chuối', 112, N'vàng', 605000, N'Chiếc', N'Hàng cao cấp loại 2'),
	  ('SP09', 'H03', N'Bánh cam', 201, N'vàng cam', 1025000, N'Chiếc', N'Hàng cao cấp loại 1'),
	  ('SP10', 'H03', N'Bánh chanh', 165, N'vàng chanh', 200000, N'Chiếc', N'Hàng phổ thông'),
	  ('SP11', 'H02', N'Bánh pía', 118, N'vàng', 19000, N'Chiếc', N'Hàng cao cấp loại 2')

insert into NhanVien
values('NV01', N'Hà Thị Anh', N'Nữ', N'Hà Nội', '0123587964', 'ha@gmail.com', N'Kế toán'),
	  ('NV02', N'Nguyễn Thị Minh', N'Nữ', N'Hà Nội', '01239637964', 'minh@gmail.com', N'Kế toán'),
	  ('NV03', N'Nguyễn Văn Dũng', N'Nam', N'Hà Tây', '0123752964', 'dung@gmail.com', N'Bếp'),
	  ('NV04', N'Tạ Dương Anh', N'Nam', N'Hà Nam', '0123951964', 'duongta@gmail.com', N'Tài chính'),
	  ('NV05', N'Nguyễn Thị Ánh', N'Nữ', N'Hà Nội', '0123580213', 'anh@gmail.com', N'Kế toán')

insert into PNhap
values('HDN01', '06-08-2020', 'NV02'),
	  ('HDN02', '02-12-2020', 'NV03'),
	  ('HDN03', '12-05-2020', 'NV04'),
	  ('HDN04', '12-10-2020', 'NV05'),
	  ('HDN05', '06-25-2018', 'NV01')


insert into Nhap 
values('HDN02','SP03',229,120000),
	  ('HDN04','SP06',506,540000),
	  ('HDN03','SP10',1000,10500),
	  ('HDN01','SP11',250,10000),
	  ('HDN05','SP02',25,540000)

insert into PXuat
values('HDX01', '06-08-2020', 'NV02'),
	  ('HDX02', '02-12-2020', 'NV03'),
	  ('HDX03', '06-30-2020', 'NV04'),
	  ('HDX04', '06-10-2020', 'NV05'),
	  ('HDX05', '06-25-2018', 'NV01')


insert into Xuat
values('HDX02','SP02',12),
	  ('HDX04','SP04',10),
	  ('HDX03','SP08',25),
	  ('HDX01','SP07',70),
	  ('HDX05','SP05',16)

/*a (1đ). Hiển thị thông tin các bảng dữ liệu trên*/
select * from SanPham
select * from HangSX
select * from NhanVien
select * from Nhap
select * from PNhap
select * from Xuat
select * from PXuat

/*b (1đ). Đưa ra thông tin MaSP, TenSP, TenHang,SoLuong, MauSac, GiaBan, DonViTinh,
MoTa của các sản phẩm sắp xếp theo chiều giảm dần giá bán.*/
select MaSP, TenSP, TenHang,SoLuong, MauSac, GiaBan, DonViTinh,MoTa
from SanPham inner join HangSX
				 on SanPham.MaHangSX = HangSX.MaHangSX
order by GiaBan desc


/*c (1đ). Đưa ra thông tin các sản phẩm có trong cữa hàng do công ty có tên hãng là Samsung
sản xuất*/

select MaSP, SanPham.MaHangSX, TenHang, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
from SanPham inner join HangSX
				   on HangSX.MaHangSX = SanPham.MaHangSX
where TenHang = 'SamSung'


/*d (1đ). Đưa ra thông tin các nhân viên Nữ ở phòng ‘Kế toán’.*/
select MaNV, TenNV, GioiTinh, DiaChi, SoDT, Email, TenPhong
from NhanVien
where GioiTinh = N'Nữ' and TenPhong = N'Kế toán'


/*e (2đ). Đưa ra thông tin phiếu nhập gồm: SoHDN, MaSP, TenSP, TenHang, SoLuongN,
DonGiaN, TienNhap=SoLuongN*DonGiaN, MauSac, DonViTinh, NgayNhap, TenNV,
TenPhong, sắp xếp theo chiều tăng dần của hóa đơn nhập.*/
select Nhap.SoHDN, SanPham.MaSP, TenSP, TenHang, SoLuongN, DonGiaN, 
(SoLuongN*DonGiaN) TienNhap, MauSac, DonViTinh, NgayNhap, TenNV,
TenPhong
from Nhap inner join SanPham
				on Nhap.MaSP = SanPham.MaSP
		  inner join HangSX
				on HangSX.MaHangSX = SanPham.MaHangSX
		  inner join PNhap
				on PNhap.SoHDN = Nhap.SoHDN
		  inner join NhanVien
				on NhanVien.MaNV = PNhap.MaNV
order by SoHDN

/*f (2đ). Đưa ra thông tin phiếu xuất gồm: SoHDX, MaSP, TenSP, TenHang, SoLuongX,
GiaBan, tienxuat=SoLuongX*GiaBan, MauSac, DonViTinh, NgayXuat, TenNV,
TenPhong trong tháng 06 năm 2020, sắp xếp theo chiều tăng dần của SoHDX.*/

select PXuat.SoHDX, SanPham.MaSP, TenSP, TenHang, SoLuongX, GiaBan, 
(SoLuongX*GiaBan) tienxuat, MauSac, DonViTinh, NgayXuat, TenNV,
TenPhong 

from Xuat inner join PXuat
				on PXuat.SoHDX = Xuat.SoHDX
		  inner join SanPham
		        on SanPham.MaSP = Xuat.MaSP
		  inner join NhanVien
				on NhanVien.MaNV = PXuat.MaNV
		  inner join HangSX
				on HangSX.MaHangSX = SanPham.MaHangSX
where NgayXuat between ('06-01-2020') and ('06-30-2020')
order by SoHDX
