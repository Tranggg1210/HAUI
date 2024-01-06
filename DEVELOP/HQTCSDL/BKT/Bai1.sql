create database QLSinhVien 
go
use QLSinhVien

create table Khoa (
	MaKhoa nchar(10) primary key,
	TenKhoa nvarchar(40),
	Diachi nvarchar(40),
	SoDT nchar(20),
	Email nvarchar(40)
)

create table Lop (
	MaLop nchar(10) primary key,
	TenLop nvarchar(40),
	SiSo int,
	MaKhoa nchar(10),
	foreign key(MaKhoa) references Khoa(MaKhoa),
	Phong nvarchar(40)
)

create table SinhVien (
	MaSV nchar(10) primary key,
	HoTen nvarchar(40),
	NgaySinh date,
	GioiTinh nvarchar(20),
	MaLop nchar(10),
	foreign key (MaLop) references Lop(MaLop)
)

-- Nhập dữ liệu
insert into Khoa
values('K01', 'CNTT', N'Tầng 6, A1', '01234567789', 'cntt.haui@gmail.com'),
	  ('K02', 'QTKD', N'Tầng 8, A7', '0627899439', 'qtkd.haui@gmail.com'),
	  ('K03', 'KT', N'Tầng 3, A11', '0128793499', 'kt.haui@gmail.com')

insert into Lop 
values('L01', 'KTPM03', 79, 'K01','A1'),
	  ('L02', 'KT03', 75, 'K03','A3'),
	  ('L03', 'QTKD03', 75, 'K02','A2')

insert into SinhVien 
values('SV01', N'Nguyễn Thị Lan', '08/06/2003', N'Nữ', 'L01'),
	  ('SV02', N'Nguyễn Văn Nam', '10/10/2003', N'Nam', 'L02'),
	  ('SV03', N'Lê Na Na', '09/09/2003', N'Nữ', 'L03'),
	  ('SV04', N'Lê Minh Anh', '12/12/2003', N'Nữ', 'L01'),
	  ('SV05', N'Cao Trung Đức', '11/11/2003', N'Nam', 'L02')

-- Xem dữ liệu
select * from Khoa
select * from Lop
select * from SinhVien

-- Câu2
create function cau2(@TenKhoa nvarchar(40), @TenLop nvarchar(40))
returns @bang table (
	MaSV nchar(10),
	HoTen nvarchar(40),
	Tuoi int
)
as
begin
	insert into @bang
	select MaSV, HoTen, DATEDIFF(YY, NgaySinh, GETDATE())
	from SinhVien inner join Lop 
						on Lop.MaLop = SinhVien.MaLop
				  inner join Khoa
						on Khoa.MaKhoa = Lop.MaLop
	where TenKhoa = @TenKhoa and TenLop = @TenLop
	return
end

--Test
select * from cau2('CNTT', 'KTPM03')