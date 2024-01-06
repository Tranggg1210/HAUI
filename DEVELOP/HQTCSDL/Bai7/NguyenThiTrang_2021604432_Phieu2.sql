create database QLBanHang
go
use QLBanHang

create table HangSX (
	MaHangSX nchar(10) primary key,
	TenHang nvarchar(20) not null,
	DiaChi nvarchar(30) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(30) not null
)

create table SanPham (
	MaSP nchar(10) primary key,
	MaHangSX nchar(10) not null,
	foreign key(MaHangSX) references HangSX(MaHangSX),
	TenSP nvarchar(20) not null,
	SoLuong int not null,
	MauSac nvarchar(20) not null,
	GiaBan money not null,
	DonViTinh nchar(10) not null,
	MoTa nvarchar(max) not null,
)

create table NhanVien (
	MaNV nchar(10) primary key,
	TenNV nvarchar(20) not null,
	GioiTinh nvarchar(10) not null,
	DiaChi nvarchar(30) not null,
	SoDT nvarchar(20) not null,
	Email nvarchar(30) not null,
	TenPhong nvarchar(30) not null,
)

create table PNhap(
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
	primary key(SoHDN, MaSP),
	SoLuongN int not null,
	DonGiaN money not null
)

create table PXuat(
	SoHDX nchar(10) primary key,
	NgayXuat date not null,
	MaNV nchar(10),
	foreign key(MaNV) references NhanVien(MaNV)
)

create table Xuat(
	SoHDX nchar(10),
	foreign key(SoHDX) references PXuat(SoHDX),
	MaSP nchar(10),
	foreign key(MaSP) references SanPham(MaSP),
	SoLuongX int not null,
	primary key(SoHDX, MaSP)
)

insert into HangSX
values('H01','Samsung', 'Korea', '011-08271717', 'ss@gmail.com.kr'),
	  ('H02','OPPO', 'China', '081-08625252', 'oppo@gmail.com.cn'),
	  ('H03','Vinfone', N'Việt Nam', '084-098262626', 'vf@gmail.com.vn')

insert into NhanVien
values('NV01', N'Nguyễn Thị Thu', N'Nữ', N'Hà Nội','0982626521', 'thu@gmail.com', N'Kế toán' ),
	  ('NV02', N'Lê Văn Nam', N'Nam', N'Bắc Ninh','0972525252', 'nam@gmail.com', N'Vật tư' ),	  
	  ('NV03', N'Trần Hòa Bình', N'Nữ', N'Hà Nội','0328388388', 'hb@gmail.com', N'Kế toán' )

insert into SanPham
values('SP01', 'H02', 'F1 Plus', 100, N'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'),
	  ('SP02', 'H01', 'Galaxy Note11', 50, N'Đỏ', 19000000, N'Chiếc', N'Hàng cao cấp'),
	  ('SP03', 'H02', 'F3 lite', 200, N'Nâu', 3000000, N'Chiếc', N'Hàng phổ thông'),
	  ('SP04', 'H03', 'Vjoy3', 200, N'Xám', 1500000, N'Chiếc', N'Hàng phổ thông'),
	  ('SP05', 'H01', 'Galaxy V21', 500, N'Nâu', 8000000, N'Chiếc', N'Hàng cận cao cấp')

insert into PNhap
values('N01', '02-05-2019', 'NV01'),
	  ('N02', '04-07-2020', 'NV02'),
	  ('N03', '05-17-2020', 'NV02'),
	  ('N04', '03-22-2020', 'NV03'),
	  ('N05', '07-07-2020', 'NV01')

insert into Nhap
values('N01','SP02',10,17000000),
	  ('N02','SP01',30,6000000),
	  ('N03','SP04',20,1200000),
	  ('N04','SP01',10,6200000),
	  ('N05','SP05',20,7000000)


insert into PXuat
values('X01', '06-14-2020', 'NV02'),
	  ('X02', '03-05-2019', 'NV03'),
	  ('X03', '12-12-2020', 'NV01'),
	  ('X04', '06-02-2020', 'NV02'),
	  ('X05', '05-18-2020', 'NV01')


insert into Xuat 
values('X01','SP03',5),
	  ('X02','SP01',3),
	  ('X03','SP02',1),
	  ('X04','SP03',2),
	  ('X05','SP05',1)

/*
Bai1
a. Hãy xây dựng hàm Đưa ra tên HangSX khi nhập vào MaSP từ bàn phím
*/

create function timtenhang(@MaSP nchar(10))
returns nvarchar(40)
as
begin
	declare @TenHang nvarchar(40)
	set @TenHang = (
						select TenHang
						from HangSX inner join SanPham
									on HangSX.MaHangSX = SanPham.MaHangSX
						where MaSP = @MaSP
					)
	return @TenHang
end

select dbo.timtenhang('SP03')

/*
b. Hãy xây dựng hàm đưa ra tổng giá trị nhập từ năm nhập x đến năm nhập y, với x, y được
nhập vào từ bàn phím.
*/
create function tongnhap(@x date, @y date)
returns money
as
begin
	declare @tongtien money
	set @tongtien = (
						select sum(DonGiaN*SoLuongN)
						from Nhap inner join PNhap
										on Nhap.SoHDN = PNhap.SoHDN
						where Year(NgayNhap) between Year(@x) and Year(@y)
					)
	return @tongtien
end

select dbo.tongnhap('05-20-2015', '05-20-2023')

/*
c. Hãy viết hàm thống kê tổng số lượng thay đổi nhập xuất của tên sản phẩm x trong năm
y, với x,y nhập từ bàn phím.
*/

create function thongke(@x nvarchar(40), @y int)
returns int
as
begin
	declare @tong int
	set @tong = (select sum(abs(SoLuongX - SoLuongN))
				 from SanPham inner join Nhap
									on Nhap.MaSP = SanPham.MaSP
							  inner join Xuat
									on Xuat.MaSP = SanPham.MaSP
							  inner join PNhap 
									on PNhap.SoHDN = Nhap.SoHDN
							  inner join PXuat
									on PXuat.SoHDX = Xuat.SoHDX
				 where (TenSP = @x) and (Year(NgayXuat) = @y) and (Year(NgayNhap) = @y)
 				)
	return @tong
end

select dbo.thongke('Galaxy V21',2020)

--Cach2
Create Function fn_ThongKeNhapXuat(@TenSP nvarchar(20),@nam int)
Returns int
As
Begin
 Declare @tongnhap int
 Declare @tongxuat int
 Declare @thaydoi int
 Select @tongnhap = Sum(SoLuongN) From Nhap
 Inner join SanPham on Nhap.MaSP = SanPham.MaSP
 Inner join PNhap on PNhap.SoHDN=Nhap.SoHDN
 Where TenSP = @TenSP And Year(NgayNhap)=@nam
 Select @tongxuat = Sum(SoLuongX) From Xuat
 Inner join SanPham on Xuat.MaSP = SanPham.MaSP
 Inner join PXuat on PXuat.SoHDX=Xuat.SoHDX
 Where TenSP = @TenSP And Year(NgayXuat)=@nam
 Set @thaydoi = @tongnhap - @tongxuat
 Return @thaydoi
End

Select dbo.fn_ThongKeNhapXuat('Galaxy V21',2020)

/*
d. Hãy xây dựng hàm Đưa ra tổng giá trị nhập từ ngày nhập x đến ngày nhập y, với x, y
được nhập vào từ bàn phím.
*/

create function tonggiatrinhap(@x date, @y date)
returns int
as
begin
	declare @tong int
	set @tong = (
				 select sum(SoLuongN*DonGiaN)
				 from Nhap inner join PNhap
								  on PNhap.SoHDN = Nhap.SoHDN
				 where NgayNhap between @x and @y
				)
	return @tong
end

select dbo.tonggiatrinhap('05-20-2017', '05-20-2022')

/*
Bài 2 (5đ). Table Valued Function
a. Hãy xây dựng hàm đưa ra thông tin các sản phẩm của hãng có tên nhập từ bàn phím.
*/

create function thongtin(@TenHang nvarchar(40))
returns @bang table(
					 MaSP nchar(10) primary key,
					 TenSP nvarchar(40),
					 SoLuong int,
					 MauSac nvarchar(40),
					 GiaBan money,
					 DonViTinh nvarchar(20),
					 MoTa nvarchar(40)
				   )
as
begin
	insert into @bang
	select MaSP, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
	from SanPham inner join HangSX
					   on SanPham.MaHangSX = HangSX.MaHangSX
	where TenHang = @TenHang
	return
end

select * from thongtin('OPPO')

/*
b. Hãy viết hàm Đưa ra danh sách các sản phẩm và hãng sản xuất tương ứng đã được nhập
từ ngày x đến ngày y, với x,y nhập từ bàn phím
*/

create function danhsach(@x date, @y date)
returns @bang table(
					 MaSP nchar(10),
					 TenSP nvarchar(40),
					 SoLuong int,
					 MauSac nvarchar(40),
					 GiaBan money,
					 MaHangSX nchar(10),
					 TenHangSX nvarchar(40),
					 NgayNhap date
				   )
as
begin
	insert into @bang 
	select  Nhap.MaSP, TenSP,SoLuong,MauSac,GiaBan, SanPham.MaHangSX ,TenHang, NgayNhap
	from HangSX inner join SanPham
					  on SanPham.MaHangSX = HangSX.MaHangSX
				inner join Nhap
					  on Nhap.MaSP = SanPham.MaSP
				inner join PNhap
					  on PNhap.SoHDN = Nhap.SoHDN
	where NgayNhap between @x and @y
return
end

select * from danhsach('05-20-2017', '05-20-2021')

/*
c. Hãy xây dựng hàm Đưa ra danh sách các sản phẩm theo hãng sản xuất và 1 lựa chọn,
nếu lựa chọn = 0 thì Đưa ra danh sách các sản phẩm có SoLuong = 0, ngược lại lựa chọn
=1 thì Đưa ra danh sách các sản phẩm có SoLuong >0.
*/

create function DSSP(@TenHang nvarchar(40), @select bit)
returns @bang table(
						 MaSP nchar(10),
						 TenSP nvarchar(40),
						 SoLuong int,
						 MauSac nvarchar(40),
						 GiaBan money,
						 MaHangSX nchar(10),
						 TenHangSX nvarchar(40)
					)
as
begin 
	if(@select = 0)
		insert into @bang
		select MaSP,TenSP ,SoLuong, MauSac, GiaBan,HangSX.MaHangSX,TenHang 
		from HangSX inner join SanPham
					  on SanPham.MaHangSX = HangSX.MaHangSX
		where (TenHang = @TenHang) and (SoLuong = 0)
	else
		insert into @bang
		select MaSP,TenSP ,SoLuong, MauSac, GiaBan,HangSX.MaHangSX,TenHang 
		from HangSX inner join SanPham
					  on SanPham.MaHangSX = HangSX.MaHangSX
		where (TenHang = @TenHang) and (SoLuong > 0)
	return
end

select * from DSSP('OPPO',1)

/*
d. Hãy xây dựng hàm Đưa ra danh sách các nhân viên có tên phòng nhập từ bàn phím.
*/
create function DSNV(@TenPhong nvarchar(40))
returns @bang table(
						MaNV nchar(10),
						TenNV nvarchar(40),
						GioiTinh nvarchar(20),
						DiaChi nvarchar(40),
						SoDT nvarchar(20),
						Email nvarchar(40),
						TenPhong nvarchar(40)
				   )
as
begin
	insert into @bang
	select * from NhanVien
	where TenPhong = @TenPhong
	return
end

select * from DSNV(N'Kế toán')