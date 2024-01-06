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
	  ('PN03','01-01-2020','NV02'),
	  ('PN04','10-12-2020','NV03'),
	  ('PN05','07-15-2020','NV03')

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

/*Bài 1*/

/*a. Đưa ra các thông tin về các hóa đơn mà hãng Samsung đã nhập trong năm 2020, gồm:
SoHDN, MaSP, TenSP, SoLuongN, DonGiaN, NgayNhap, TenNV, TenPhong. */
select PNhap.SoHDN, Sanpham.MaSP, TenSP, SoLuongN, 
	   DonGiaN, NgayNhap, TenNV, TenPhong
from PNhap inner join Nhap
				on PNhap.SoHDN = Nhap.SoHDN
	       inner join Sanpham
				on Sanpham.MaSP = Nhap.MaSP
		   inner join NhanVien
				on NhanVien.MaNV = PNhap.MaNV

where YEAR(NgayNhap) = 2020

/*b. Đưa ra Top 10 hóa đơn xuất có số lượng xuất nhiều nhất trong năm 2020, sắp xếp theo
chiều giảm dần của SoLuongX. */
select top 10 PXuat.SoHDX, MaSP, SoLuongX,NgayXuat,MaNV
from PXuat inner join Xuat
				on PXuat.SoHDX = Xuat.SoHDX
where YEAR(NgayXuat) = 2020
order by SoLuongX desc

/*c. Đưa ra thông tin 10 sản phẩm có giá bán cao nhất trong cữa hàng, theo chiều giảm dần
giá bán.*/
select top 10 *
from Sanpham
order by GiaBan desc

/*d. Đưa ra các thông tin sản phẩm có giá bán từ 100.000 đến 500.000 của hãng Samsung.*/
select MaSP, HangSX.MaHangSX,  TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa,TenHang
from Sanpham inner join HangSX
				  on Sanpham.MaHangSX = HangSX.MaHangSX
where GiaBan between 100000 and 500000 and TenHang = 'SamSung'


/*e. Tính tổng tiền đã nhập trong năm 2020 của hãng Samsung.*/
select sum(DonGiaN * SoLuongN) ['Tổng tiền nhập của hãng Samsung trong năm 2020']
from Nhap inner join PNhap
			    on Nhap.SoHDN = PNhap.SoHDN
		  inner join Sanpham
			    on Sanpham.MaSP = Nhap.MaSP
		  inner join HangSX
			    on HangSX.MaHangSX = Sanpham.MaHangSX
where year(NgayNhap) = 2020 and TenHang = 'SamSung'

/*f. Thống kê tổng tiền đã xuất trong ngày 14/06/2020*/
select sum(GiaBan*SoLuongX) ['Tổng tiền xuấtcủa hãng Samsung trong năm 2020']
from Sanpham inner join Xuat
				   on Sanpham.MaSP = Xuat.MaSP
	         inner join PXuat
				   on PXuat.SoHDX =  Xuat.SoHDX
where NgayXuat = '06-14-2020'

/*g. Đưa ra SoHDN, NgayNhap có tiền nhập phải trả cao nhất trong năm 2020*/
select Nhap.SoHDN, NgayNhap
from PNhap inner join Nhap
				on PNhap.SoHDN = Nhap.SoHDN
where (DonGiaN * SoLuongN) = (
								Select Max(DonGiaN * SoLuongN)
								from PNhap inner join Nhap
												on PNhap.SoHDN = Nhap.SoHDN
) and YEAR(NgayNhap) = 2020

/*Bai2*/
/*a. Hãy thống kê xem mỗi hãng sản xuất có bao nhiêu loại sản phẩm
*/

select TenHang, HangSX.MaHangSX , count(*) ['Số lượng sản phẩm của hãng sản xuất']
from Sanpham inner join HangSX 
				   on Sanpham.MaHangSX = HangSX.MaHangSX
group by   TenHang, HangSX.MaHangSX

/*b. Hãy thống kê xem tổng tiền nhập của mỗi sản phẩm trong năm 2020.*/
select TenSP, Sanpham.MaSP, sum(SoLuongN*DonGiaN) ['Tổng tiền']
from Sanpham inner join Nhap
				   on Sanpham.MaSP = Nhap.MaSP
			 inner join PNhap
				   on PNhap.SoHDN = Nhap.SoHDN
group by Sanpham.MaSP,TenSP


/*c. Hãy thống kê các sản phẩm có tổng số lượng xuất năm 2020 là lớn hơn 10.000 sản
phẩm của hãng Samsung.*/
select Xuat.MaSP, TenSP, SoLuongX, NgayXuat, TenHang, sum(SoLuongX) ['Tổng xuất']
from Xuat inner join Sanpham
				on Sanpham.MaSP = Xuat.MaSP
		  inner join PXuat
				on PXuat.SoHDX = Xuat.SoHDX
		  inner join HangSX
				on HangSX.MaHangSX = Sanpham.MaHangSX
where TenHang = 'Samsung' and year(NgayXuat) = 2020
group by Xuat.MaSP, TenSP, SoLuongX, NgayXuat, TenHang
having sum(SoLuongX) >= 10000

/*d. Thống kê số lượng nhân viên Nam của mỗi phòng ban.*/
select TenPhong, TenNV, MaNV, count(*) ['Số lượng nhân viên']
from NhanVien
where GioiTinh = 'Nam'
group by TenPhong, MaNV, TenNV

/*e. Thống kê tổng số lượng nhập của mỗi hãng sản xuất trong năm 2018.*/
select HangSX.MaHangSX, TenHang, sum(SoLuongN) ['Số lượng nhập']
from Nhap inner join PNhap
				on Nhap.SoHDN = PNhap.SoHDN
		  inner join Sanpham
				on Nhap.MaSP = Sanpham.MaSP
		  inner join HangSX
				on HangSX.MaHangSX = Sanpham.MaHangSX
where year(NgayNhap) = 2018
group by HangSX.MaHangSX, TenHang

/*f. Hãy thống kê xem tổng lượng tiền xuất của mỗi nhân viên trong năm 2018 là bao
nhiêu.*/

select MaNV, sum(SoLuongX * GiaBan) ['Tổng tiền xuất']
from PXuat inner join Xuat
				on Xuat.SoHDX = PXuat.SoHDX
		   inner join Sanpham
				on Sanpham.MaSP = Xuat.MaSP
where year(NgayXuat) = 2018
group by MaNV

