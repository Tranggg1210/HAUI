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


/*	  Bài 1 (5đ).
a. Tạo thủ tục nhập dữ liệu cho bảng sản phẩm với các tham biến truyền vào MaSP,
TenHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa. Hãy kiểm tra xem
nếu MaSP đã tồn tại thì cập nhật thông tin sản phẩm theo mã, ngược lại thêm mới sản phẩm
vào bảng SanPham.
*/

create proc nhapSP(@MaSP nchar(10),
				   @TenHangSX nvarchar(40), 
				   @TenSP nvarchar(40), 
				   @SoLuong int, 
				   @MauSac nvarchar(40), 
				   @GiaBan money, 
				   @DonViTinh nvarchar(40), 
				   @MoTa nvarchar(40))
as
begin
	if( not exists(select * from HangSX where TenHang = @TenHangSX))
		print N'Tên hãng sản xuất ' + @TenHangSX + N' không tồn tại trong bảng HangSX, mâu thuẫn dữ liệu'
	else
		begin
			declare @MaHangSX nchar(10)
			set @MaHangSX = (select MaHangSX from HangSX where TenHang = @TenHangSX)
			if(exists(select * from SanPham where MaSP = @MaSP))
				begin
					update SanPham
					set TenSP = @TenSP,
						MaHangSX = @MaHangSX,
						SoLuong = @SoLuong,
						MauSac = @MauSac,
						GiaBan = @GiaBan,
						DonViTinh = @DonViTinh,
						MoTa = @MoTa
					where MaSP = @MaSP
					print N'Dữ liệu đã được cập nhập vào sản phẩm có mã ' + @MaSP
				end
			else
				begin
					insert into SanPham
					values(@MaSP,  @MaHangSX , @TenSP, @SoLuong, @MauSac, @GiaBan, @DonViTinh, @MoTa)
					print N'Dữ liệu bạn nhập đã được tạo mới trong bảng SanPham'
				end
		end
end

--Test1: MaSP đã tồn tại và cập nhập
exec nhapSP 'SP01', 'SamSung', 'F1 Plus', 100, N'Xám', 7000000, N'Chiếc', N'Hàng cận cao cấp'
select * from SanPham
select * from HangSX

--Test2: MaSP chưa tồn tại nhưng tên hãng không tồn tại
exec nhapSP 'SP06', 'FPTgfgfgdfg', 'OPPO A32', 100, N'Xanh', 8000000, N'Chiếc', N'Hàng cận cao cấp'
select * from SanPham


--Test3: Tạo mới dữ liệu
exec nhapSP 'SP06', 'FPT', 'OPPO A32', 100, N'Xanh', 8000000, N'Chiếc', N'Hàng cận cao cấp'
select * from SanPham
select * from HangSX

/*
b. Viết thủ tục xóa dữ liệu bảng HangSX với tham biến là TenHang. Nếu TenHang chưa
có thì thông báo, ngược lại xóa HangSX với hãng bị xóa là TenHang. (Lưu ý: xóa HangSX
thì phải xóa các sản phẩm mà HangSX này cung ứng). 
*/

Create Proc sp_xoaHangSX(@TenHang nvarchar(20))
As
Begin
	If(Not Exists(Select * From HangSX Where TenHang = @TenHang))
		Print N'Không tồn tại hãng sx cần xóa'
	Else
		Begin
			Declare @MaHangSX nvarchar(10)
			Select @MaHangSX = MaHangSX From HangSX Where TenHang =@TenHang
			Delete From SanPham Where MaHangSX = @MaHangSX
			Delete From HangSX Where MaHangSX = @MaHangSX
		End
End



--Test1: @TenHang vừa nhập không tồn tại
exec sp_xoaHangSX N'ABC'
select * from HangSX

--Test2: Cho phép xóa theo tên hãng
exec sp_xoaHangSX N'OPPO'
select * from HangSX
select * from SanPham

/*
c. Viết thủ tục nhập dữ liệu cho bảng nhân viên với các tham biến manv, TenNV, GioiTinh,
DiaChi, SoDT, Email, Phong, và 1 biến cờ Flag, Nếu Flag = 0 thì cập nhật dữ liệu cho bảng
nhân viên theo manv, ngược lại thêm mới nhân viên này.
*/

create proc nhap_cNV (@MaNV nchar(10), @TenNV nvarchar(40), @GioiTinh nvarchar(20),
					  @DiaChi nvarchar(40), @SoDT nchar(20), @Email nvarchar(40), 
					  @Phong nvarchar(40), @Flag int output)
as
begin
	if(exists(select * from NhanVien where MaNV = @MaNV))
		set @Flag = 0
	else set @Flag = 1
	if(@Flag <> 1)
		begin
			update NhanVien
			set TenNV = @TenNV,
				GioiTinh = @GioiTinh,
				DiaChi = @DiaChi,
				SoDT = @SoDT,
				Email = @Email,
				TenPhong = @Phong
			where MaNV = @MaNV
			print N'Nhân viên có mã ' + @MaNV + N' đã được cập nhập thông tin'
		end
	else 
		begin
			insert into NhanVien
			values(@MaNV, @TenNV, @GioiTinh,@DiaChi, @SoDT, @Email, @Phong)
			print N'Đã thêm mới một nhân viên vào bảng NHANVIEN'
		end
	return @Flag
end
drop proc nhap_cNV
--Test1: Cập nhập thông tin nhân viên theo mã nhân viên đổi NV02 từ phòng Vật tư sang Hành chính
declare @bien int
exec nhap_cNV 'NV02', N'Lê Văn Nam', N'Nam', N'Bắc Ninh','0972525252', 'nam@gmail.com', N'Hành chính', @bien output
select @bien
select * from NhanVien

--Test1: Thêm mới nhân viên
declare @bien1 int
exec nhap_cNV 'NV05', N'Nguyễn Thị A', N'Nữ', N'Bắc Ninh','0972525252', 'anh@gmail.com', N'Hành chính', @bien1 output
select @bien1
select * from NhanVien