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
Bài 1 (5đ). Scalar Valued Function
a. Hãy xây dựng hàm Đưa ra tên hãng sản xuất khi nhập vào MaSP từ bàn phím
b. Hãy xây dựng hàm đếm số sản phẩm có giá bán từ x đến y do hãng z cung ứng, với x,y,z
nhập từ bàn phím.
Bài 2 (5đ). Table valued funtion
c. Hãy tạo hàm đưa ra thông tin các sản phẩm có giá bán >=x và do hãng y cung ứng. Với
x,y nhập từ bàn phím. 
*/

--Bai 1 a
create function getTenhang(@MaSP nchar(10))
returns nvarchar(40)
as
	begin
	declare @TenHang nvarchar(40)
	set @TenHang = (select TenHang
					from HangSX inner join SanPham
									  on HangSX.MaHangSX = SanPham.MaHangSX
					where MaSP = @MaSP
					)
	return @TenHang
end


select dbo.getTenhang('SP01')

-- Bai 1 b
create function demsanpham(@x money, @y money, @z nvarchar(40))
returns int
as
	begin
		declare @dem int
		set @dem = (select count(*) 
				   from SanPham inner join HangSX 
									  on HangSX.MaHangSX = SanPham.MaHangSX
				   where (GiaBan between @x and @y) and (TenHang = @z)
				   )
	return @dem
end

select dbo.demsanpham(3000000,10000000, 'OPPO');

/*
Bài 2 (5đ). Table valued funtion
c. Hãy tạo hàm đưa ra thông tin các sản phẩm có giá bán >=x và do hãng y cung ứng. Với
x,y nhập từ bàn phím. 
*/

create function bai2(@x money, @y nvarchar(40))
returns @BANGTHONGTIN table(
					MaSP nchar(10) primary key,
					TenSP nvarchar(40),
					SoLuong int,
					MauSau nvarchar(20),
					GiaBan money,
					DonViTinh nvarchar(20),
					MoTa nvarchar(40)
)

as
	begin
	insert into @BANGTHONGTIN
	select HangSX.MaHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
	from HangSX inner join SanPham
					  on HangSX.MaHangSX = SanPham.MaHangSX
	where GiaBan >= @x and TenHang = @y
    return
end

select * from bai2(7000000, 'OPPO')