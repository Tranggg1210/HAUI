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


Create proc sp_Themhangsx(@MaH nchar(10), @TenH nvarchar(20), @DC nvarchar(20),
							@SoDT nchar(10), @Email nvarchar(30))
As
Begin
	if(not exists ( select * from HangSX where TenHang = @TenH))
		insert into HangSX values (@MaH, @TenH, @DC, @SoDT, @Email)
	else
		print N'Đã tồn tại tên Hãng Sản xuất này'
End

EXEC sp_Themhangsx 'H05', 'OPPO', 'haloi', '0982626521', 'abc@gmail.com'
Select * from HangSX

--VD3: Viết thủ tục cập nhập lại Địa chỉ, số điện thoại, email của 1 hãng sản xuất
-- với MaHangSX, DiaChi, SoDT, Email, được nhập từ bàn phím

create proc update_HangSX (@MaH nchar(10), @DC nvarchar(20), @SDT nvar(10), @Email nvarchar(30))
as
Begin
	if(@MaH = (select MaHangSX from HangSX))
	{
		update HangSX 
			set DiaChi = @DC,
			SoDT = @SDT,
			Email = @Email
		--where MaHangSX = @MaH
		print "Dữ liệu đã cập nhập thành công"
	}else {
		print "Hang san xuat can tim khong co trong co so du lieu"
	}
end

-- Tra ve

Create proc SP_TraVe(@MaH nchar(10), @TenH nvarchar(20), @DC nvarchar(20),
							@SoDT nchar(10), @Email nvarchar(30), @trave int output)
As
Begin
	if(not exists ( select * from HangSX where TenHang = @TenH))
		begin
			set @trave = 0
			insert into HangSX values (@MaH, @TenH, @DC, @SoDT, @Email)
		end
	else
		set @trave = 1
return @trave 
End

declare @bien int
exec SP_TraVe 
 'HA6', 'FPT', 'haloi', '0982626521', 'abc@gmail.com', @bien output
select @bien
select * from HangSX


/*a (5đ). Tạo thủ tục nhập liệu cho bảng HangSX, với các tham biến truyền vào MaHangSX,
TenHang, DiaChi, SoDT, Email. Hãy kiểm tra xem TenHang đã tồn tại trước đó hay chưa?
Nếu có rồi thì không cho nhập và Đưa ra thông báo.*/

create proc nhapDuLieu(@MaHangSX nchar(10), @TenH nvarchar(20), @DC nvarchar(30), @SDT nchar(10), @Email nvarchar(40))
as
begin
	if(exists(select * from HangSX where @TenH = TenHang) ) 
		print N'Hãng sản xuất đã tồn tại'
	else 
		insert into HangSX
		values(@MaHangSX, @TenH, @DC, @SDT, @Email)
		print N'Dữ liễu đã được thêm mới'
end

exec nhapDuLieu 'H08', 'ABC', N'Hà Nam', '0123456', 'abc@gmail.com'
select * from HangSX


/*
b (5đ). Viết thủ tục thêm mới nhân viên bao gồm các tham số: MaNV, TenNV, GioiTinh,
DiaChi, SoDT, Email, TenPhong và 1 biến Flag, Nếu Flag=0 thì nhập mới, ngược lại thì
cập nhật thông tin nhân viên theo mã. Hãy kiểm tra:
- GioiTinh nhập vào có phải là Nam hoặc Nữ không, nếu không trả về mã lỗi 1.
- Ngược lại nếu thỏa mãn thì cho phép nhập và trả về mã lỗi 0.
*/

/*create proc themNV(@MaNV nchar(10), @TenNV nvarchar(40), @GioiTinh nvarchar(10),
				   @DC nvarchar(40), @SDT nchar(20), @Email nvarchar(40), @Flag int output)
as
begin
	if(exists(select * from NhanVien where MaNV = @MaNV))

end*/

/*
a (3đ). Tạo thủ tục nhập liệu cho bảng HangSX, với các tham biến truyền vào MaHangSX,
TenHang, DiaChi, SoDT, Email. Hãy kiểm tra xem TenHang đã tồn tại trước đó hay chưa,
nếu rồi trả về mã lỗi 1? Nếu có rồi thì không cho nhập và trả về mã lỗi 0.
*/
create proc nhapDuLieu2(@MaHangSX nchar(10), @TenH nvarchar(20), @DC nvarchar(30), @SDT nchar(10), @Email nvarchar(40), @trave int output)
as
begin
	if(exists(select * from HangSX where @TenH = TenHang) ) 
		set @trave = 1
	else 
		insert into HangSX
		values(@MaHangSX, @TenH, @DC, @SDT, @Email)
		set @trave = 0
return @trave
end

declare @bien int
exec nhapDuLieu2 'H08', 'ABC', N'Hà Nam', '0123456', 'abc@gmail.com', @bien output
select @bien
select * from HangSX

/*
c (4đ). Viết thủ tục nhập dữ liệu cho bảng Xuat với các tham biến SoHDX, MaSP, manv,
NgayXuat, SoLuongX. Kiểm tra xem MaSP có tồn tại trong bảng SanPham hay không nếu
không trả về 1? manv có tồn tại trong bảng NhanVien hay không nếu không trả về 2?
SoLuongX <= SoLuong nếu không trả về 3? ngược lại thì hãy kiểm tra: Nếu SoHDX đã
tồn tại thì cập nhật bảng Xuat theo SoHDX, ngược lại thêm mới bảng Xuat và trả về mã
lỗi 0.
*/

CREATE PROC sp_ThemXuat(
    @SoHDX INT,
    @MaSP INT,
    @MaNV INT,
    @NgayXuat DATE,
    @SoLuongX INT,
	@trave int output
	)
AS
BEGIN
    DECLARE @SoLuong INT
    SELECT @SoLuong = SoLuong FROM SanPham WHERE MaSP = @MaSP
    IF (@@ROWCOUNT = 0)
    BEGIN
        set @trave = 1;
    END

    IF NOT EXISTS (SELECT * FROM NhanVien WHERE MaNV = @MaNV)
    BEGIN
        set @trave = 2;    
	END
    IF (@SoLuongX > @SoLuong)
    BEGIN
        RETURN 3 
    END

    IF EXISTS (SELECT * FROM Xuat WHERE SoHDX = @SoHDX)
    BEGIN
        UPDATE Xuat SET MaSP = @MaSP, 
						SoLuongX = @SoLuongX 
					WHERE SoHDX = @SoHDX
    END
    ELSE
    BEGIN
    
        INSERT INTO Xuat (SoHDX, MaSP, SoLuongX) VALUES (@SoHDX, @NgayXuat, @SoLuongX)
		set @trave = 0
    END

    RETURN @trave
END

