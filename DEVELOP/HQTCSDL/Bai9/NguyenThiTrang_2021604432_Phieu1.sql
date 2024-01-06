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
a (5đ). Tạo thủ tục nhập liệu cho bảng HangSX, với các tham biến truyền vào MaHangSX,
TenHang, DiaChi, SoDT, Email. Hãy kiểm tra xem TenHang đã tồn tại trước đó hay chưa?
Nếu có 
*/

create proc nhapdulieubangHangSX(@MaHangSX nchar(10), 
				 @TenHang nvarchar(40), 
				 @DiaChi nvarchar(40), 
				 @SoDT nvarchar(20), 
				 @Email nvarchar(40))
as
begin
	if(exists(select * from HangSX where TenHang = @TenHang))
		print N'Tên hãng: ' + @TenHang + N' đã tồn tại trong bảng HangSX'
	else
		begin
			 insert into HangSX
			 values(@MaHangSX,  @TenHang, @DiaChi, @SoDT, @Email)
			 print N'Dữ liệu bạn nhập đã được tao mới trong bảng HangSX'
		end
end


--Test1: Tên hãng đã tồn tại
exec nhapdulieubangHangSX 'H04','Samsung', N'Việt Nam', '084-08271717', 'fpt@gmail.com.kr'
select * from HangSX

--Test2: Tên hãng chưa tồn tại
exec nhapdulieubangHangSX 'H04','FPT', N'Việt Nam', '084-08271717', 'fpt@gmail.com.kr'
select * from HangSX



/*
b (5đ). Viết thủ tục thêm mới nhân viên bao gồm các tham số: MaNV, TenNV, GioiTinh,
DiaChi, SoDT, Email, TenPhong và 1 biến Flag, Nếu Flag=0 thì nhập mới, ngược lại thì
cập nhật thông tin nhân viên theo mã. Hãy kiểm tra:
- GioiTinh nhập vào có phải là Nam hoặc Nữ không, nếu không trả về mã lỗi 1.
- Ngược lại nếu thỏa mãn thì cho phép nhập và trả về mã lỗi 0.
*/

create proc themmoiNV(@MaNV nchar(10),
					  @TenNV nvarchar(40),
					  @GioiTinh nvarchar(20),
					  @DiaChi nvarchar(40),
					  @SoDT nvarchar(20),
					  @Email nvarchar(40),
					  @TenPhong nvarchar(40),
					  @Flag int output)
as
begin
	if(exists(select * from NhanVien where MaNV = @MaNV))
		begin
			update NhanVien
			set TenNV = @TenNV,
				GioiTinh = @GioiTinh,
				DiaChi = @DiaChi,
				SoDT = @SoDT,
				Email = @Email,
				TenPhong = @TenPhong
			where MaNV = @MaNV
			set @Flag = 2
			print N'Dự liệu của nhân viên có mã ' + @MaNV + N' đã được cập nhập'
		end
	else
		begin
			if(@GioiTinh <> 'Nam' and @GioiTinh <> N'Nữ')
				begin
					set @Flag = 1;
					print N'Dữ liệu giới tính bạn vừa nhập không đúng định dạng là nam hoặc nữ'
				end
			else
				begin
					insert into NhanVien
					values(@MaNV, @TenNV, @GioiTinh, @DiaChi, @SoDT, @Email,  @TenPhong)
					set @Flag = 0
					print N'Dữ liệu bạn nhập đã được tạo mới vào bảng NhanVien'
				end
		end
		
	return @Flag
end



--Test1: Dự liêu được cập nhập
declare @bien int
exec themmoiNV 'NV02', N'Lê Văn Nam', N'Nam', N'Hải Phòng','0972525252', 'nam@gmail.com', N'Vật tư' , @bien output
select @bien
select * from NhanVien


--Test2: Dự liêu nhập sai định dạng giới tính nam hoặc nữ
declare @bienb int
exec themmoiNV 'NV04', N'Lê Văn Dũng', N'B', N'Hà Tĩnh','0257896358', 'dung@gmail.com', N'Hành chính' , @bienb output
select @bienb
select * from NhanVien

--Test3: Dự liêu được tạo mới
declare @bienc int
exec themmoiNV 'NV04', N'Lê Văn Dũng', N'Nam', N'Hà Tĩnh','0257896358', 'dung@gmail.com', N'Hành chính' , @bienc output
select @bienc
select * from NhanVien