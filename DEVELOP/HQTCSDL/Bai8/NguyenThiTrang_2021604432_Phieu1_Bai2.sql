create database QuanLy
go
use QuanLy

create table Khoa (
	MaKhoa nchar(10) primary key,
	TenKhoa nvarchar(40) not null,
	DienThoai nchar(20) not null
)

create table Lop (
	MaLop nchar(10) primary key,
	TenLop nvarchar(40) not null,
	Khoa int not null,
	Hedt nvarchar(40) not null,
	Namnhaphoc int not null,
	MaKhoa nchar(10),
	foreign key(MaKhoa) references Khoa(MaKhoa)
)

insert into Khoa 
values('K01', N'Công nghệ thông tin', '0123456789'),
	  ('K02', N'Quản trị kinh doanh', '0645321789'),
	  ('K03', N'Kế toán', '0785432155'),
	  ('K04', N'Cơ khí', '0579634586'),
	  ('K05', N'Điện tử', '0257963458')


insert into Lop
values('L01',N'Lập trình C', 16, N'Đại học', 2023, 'K01'),
	  ('L02',N'Kinh tế học', 16, N'Đại học', 2023, 'K03'),
	  ('L03',N'Âm nhạc đại cương', 16, N'Cao Đẳng', 2023, 'K04'),
	  ('L04',N'Kinh tế vĩ mô', 16, N'Cao Đẳng', 2023, 'K02'),
	  ('L05',N'Lập trình Java', 16, N'Đại học', 2023, 'K01')


/*
Câu 1 (5đ). Viết thủ tục nhập dữ liệu vào bảng KHOA với các tham biến:
makhoa,tenkhoa, dienthoai, hãy kiểm tra xem tên khoa đã tồn tại trước đó hay chưa,
nếu đã tồn tại trả về giá trị 0, nếu chưa tồn tại thì nhập vào bảng khoa, test với 2
trường hợp.
*/

create proc nhapdulieubangkhoa(@makhoa nchar(10), @tenkhoa nvarchar(40), @dienthoai nchar(20), @flag bit output)
as
begin
	if(exists(select * from Khoa where TenKhoa = @tenkhoa))
		begin
			print N'Tên khoa ' + @tenkhoa + N' đã tồn tại trong bảng Khoa'
			set @flag = 0
		end
	else
		begin
			insert into Khoa
			values(@makhoa, @tenkhoa, @dienthoai)
			set @flag = 1
			print N'Dữ liệu bạn nhập đã được tạo mới trong bảng Khoa!'
		end
	return @flag
end

--Test1: Tên khoa trùng
declare @bien bit
exec nhapdulieubangkhoa 'K01', N'Công nghệ thông tin', '0123456789', @bien output
select @bien
select * from Khoa

--Test2: Tên khoa không trùng
declare @bien1 bit
exec nhapdulieubangkhoa 'K06', N'Ngôn ngữ Anh', '0579824639', @bien1 output
select @bien1
select * from Khoa

/*
Câu 2 (5đ). Hãy viết thủ tục nhập dữ liệu cho bảng lop với các tham biến
malop,tenlop,khoa,hedt,namnhaphoc,makhoa.
 - Kiểm tra xem tên lớp đã có trước đó chưa nếu có thì trả về 0.
 - Kiểm tra xem makhoa này có trong bảng khoa hay không nếu không có thì trả về
1.
 - Nếu đầy đủ thông tin thì cho nhập và trả về 2.
*/

create proc nhapdulieubanglop(@malop nchar(10), @tenlop nvarchar(40), @khoa int, @hedt nvarchar(40), @namnhaphoc int, @makhoa nchar(10), @flag int output)
as
begin
	if(exists(select * from Lop where TenLop = @tenlop))
		begin
			print N'Tên lớp ' + @tenlop + N' đã tồn tại trong bảng lớp'
			set @flag = 0
		end
	else
		begin
			if(not exists(select * from Khoa where MaKhoa = @makhoa))
				begin
					print N'Mã khoa ' + @makhoa + N' không tồn tại trong bảng Khoa'
					set @flag = 1
				end
			else
				begin 
					insert into Lop
					values(@malop, @tenlop, @khoa, @hedt, @namnhaphoc, @makhoa)
					print N'Dữ liệu bạn nhập đã được tạo mới vào bảng Lop'
					set @flag = 2
				end
		end
	return @flag
end

--Test1: Tên lớp trùng
declare @bien int
exec nhapdulieubanglop 'L01',N'Lập trình C', 16, N'Đại học', 2023, 'K01', @bien output
select @bien
select * from Lop


--Test2: Mã khoa không tồn tại trong bảng Khoa
declare @bien1 int
exec nhapdulieubanglop 'L06',N'Triết học', 16, N'Đại học', 2023, 'K19', @bien1 output
select @bien1
select * from Lop

-- Test3: Nhập dữ liệu vào bảng lớp
declare @bien2 int
exec nhapdulieubanglop 'L06',N'Triết học', 16, N'Đại học', 2023, 'K04', @bien2 output
select @bien2
select * from Lop



