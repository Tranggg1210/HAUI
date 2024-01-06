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
nếu đã tồn tại đưa ra thông báo, nếu chưa tồn tại thì nhập vào bảng khoa, test với 2
trường hợp
*/

create proc nhapdulieu(@makhoa nchar(10), @tenkhoa nvarchar(40), @dienthoai nchar(20))
as
begin
	if(exists((select * from Khoa where @tenkhoa = TenKhoa)))
		print N'Tên khoa ' + @tenkhoa + N' đã tồn tại'
	else
		begin
			insert into Khoa
			values(@makhoa, @tenkhoa, @dienthoai)
			print N'Dữ liệu bạn nhập đã được tạo mới!'
		end
end


--Test1: Tên trùng
exec nhapdulieu 'K01', N'Công nghệ thông tin', '0123456789'
select * from Khoa

-- Test2: Tên không trùng
exec nhapdulieu 'K06', N'Ngôn Ngữ Anh', '0759463589'
select * from Khoa

/*
Câu 2 (5đ). Hãy viết thủ tục nhập dữ liệu cho bảng Lop với các tham biến Malop,
Tenlop, Khoa,Hedt,Namnhaphoc,Makhoa nhập từ bàn phím.
 - Kiểm tra xem tên lớp đã có trước đó chưa nếu có thì thông báo
 - Kiểm tra xem makhoa này có trong bảng khoa hay không nếu không có thì thông
báo
 - Nếu đầy đủ thông tin thì cho nhập
*/

create proc nhapdulieulop(@Malop nchar(10), @Tenlop nvarchar(40), @Khoa int, @Hedt nvarchar(40), @Namnhaphoc int, @Makhoa nchar(10))
as
begin
	if(exists(select * from Lop where TenLop = @Tenlop))
		print N'Tên lớp ' + @Tenlop + N' đã tồn tại trong csdl'
	else
		begin
			if(not exists(select * from Khoa where MaKhoa = @Makhoa))
				print N'Mã khoa ' + @Makhoa + N' này không tồn tại trong csdl'
			else
				begin
					insert into Lop
					values(@Malop, @Tenlop, @Khoa, @Hedt, @Namnhaphoc, @Makhoa)
					print N'Dữ liệu bạn nhập đã được tạo mới vào bảng Lop!'
				end
		end
end
-- Test1: tên lớp trùng

exec nhapdulieulop 'L02',N'Kinh tế học', 16, N'Đại học', 2023, 'K03'
select * from Lop

-- Test2: mã khoa không tồn tại trong bảng khoa
exec nhapdulieulop 'L06',N'Triết học', 16, N'Đại học', 2023, 'K19'
select * from Lop

-- Test3: Test cho nhập dữ liệu
exec nhapdulieulop 'L07',N'Giải tích', 16, N'Đại học', 2023, 'K04'
select * from Lop
