create database QLNV
go
use QLNV

create table ChucVu(
	MaCV nvarchar(2) primary key,
	TenCV nvarchar(30)
)

create table NhanVien(
	MaNV nvarchar(4) primary key,
	MaCV nvarchar(2),
	foreign key(MaCV) references ChucVu(MaCV),
	TenNV nvarchar(30),
	NgaySinh datetime,
	LuongCanBan float,
	NgayCong int,
	PhuCap float
)

insert into ChucVu
values('BV', N'Bảo Vệ'),
	  ('GD', N'Giám Đốc'),
	  ('HC', N'Hành Chính'),
	  ('KT', N'Kế Toán'),
	  ('TQ', N'Thủ Quỹ'),
	  ('VS', N'Vệ Sinh')

insert into NhanVien
values('NV01', 'GD', N'Nguyễn Văn An', '12/12/1977 12:00:00', 700000,25,500000),
	  ('NV02', 'BV', N'Bùi Văn Tí', '10/10/1978 12:00:00', 400000,24,100000),
	  ('NV03', 'KT', N'Trần Thanh Nhật', '9/9/1977 12:00:00', 600000,26,400000),
	  ('NV04', 'VS', N'Nguyễn Thị Út', '10/10/1980 12:00:00', 300000,26,300000),
	  ('NV05', 'HC', N'Lê Thị Hà', '10/10/1979 12:00:00', 500000,27,200000)

/*
1. Tạo thủ tục có tham số đưa vào là MaNV, MaCV, TenNV, NgaySinh, LuongCB,
NgayCong, PhucCap. Trước khi chèn một bản ghi mới vào bảng NHANVIEN với danh
sách giá trị là giá trị của các biến phải kiểm tra xem MaCV đã tồn tại bên bảng ChucVu
chưa, nếu chưa trả ra 0.
*/

create proc chen(@MaNV nvarchar(4), 
				 @MaCV nvarchar(2), 
				 @TenNV nvarchar(30), 
				 @NgaySinh datetime, 
				 @LuongCB float,
				 @NgayCong int, 
				 @PhuCap float,
				 @flag int output)
as
begin
	if(exists(select * from ChucVu where MaCV = @MaCV))
		begin
			insert into NhanVien
			values(@MaNV, @MaCV, @TenNV, @NgaySinh, @LuongCB, @NgayCong, @PhuCap)
			set @flag = 1
			print N'Dữ liệu bạn nhập đã được tạo mới vào bảng NhanVien'
		end
	else
		begin
			set @flag = 0
			print N'Mã chức vụ ' +  @MaCV + N' không tồn tại trong bảng ChucVu'
		end
	return @flag
end

--Test1: MaCV không tồn tại
declare @bien int
exec chen 'NV06', 'FC', N'Trần Thanh Minh', '9/19/1977 12:00:00', 800000,25,200000, @bien output
select @bien
select * from NhanVien

--Test2: Chèn dữ liệu
declare @bien1 int
exec chen 'NV07', 'GD', N'Trần Thanh Minh', '9/19/1977 12:00:00', 800000,25,200000, @bien1 output
select @bien1
select * from NhanVien

/*
2. Sửa thủ tục ở câu một kiểm tra xem thêm MaNV được chèn vào có trùng với MaNV
nào đó có trong bảng không. Nếu MaNV đã tồn tại trả ra 0, nếu MaCV chưa tồn tại trả ra
1. Ngược lại cho phép chèn bản ghi.
*/

alter proc chen( @MaNV nvarchar(4), 
				 @MaCV nvarchar(2), 
				 @TenNV nvarchar(30), 
				 @NgaySinh datetime, 
				 @LuongCB float,
				 @NgayCong int, 
				 @PhuCap float,
				 @flag int output)
as
begin
	if(exists(select * from NhanVien where MaNV = @MaNV))
		begin
			print N'Mã nhân viên ' + @MaNV + N' đã tồn tại trong bảng NhanVien'
			set @flag = 0
		end
	else
		if(exists(select * from ChucVu where MaCV = @MaCV))
			begin
				insert into NhanVien
				values(@MaNV, @MaCV, @TenNV, @NgaySinh, @LuongCB, @NgayCong, @PhuCap)
				set @flag = 2
				print N'Dữ liệu bạn nhập đã được tạo mới vào bảng NhanVien'
			end
		else
			begin
				set @flag = 1
				print N'Mã chức vụ ' +  @MaCV + N' không tồn tại trong bảng ChucVu'
			end
	return @flag
end

--Test1: MaNV trùng
declare @bien int
exec chen 'NV06', 'GD', N'Trần Minh Quân', '6/19/1977 12:00:00', 400000,28,400000, @bien output
select @bien
select * from NhanVien

--Test2: MaCV không có
declare @bien1 int
exec chen 'NV08', 'FC', N'Trần Minh Quân', '6/19/1977 12:00:00', 400000,28,400000, @bien1 output
select @bien1
select * from NhanVien

--Test3: Chen
declare @bien2 int
exec chen 'NV08', 'KT', N'Trần Minh Quân', '6/19/1977 12:00:00', 400000,28,400000, @bien2 output
select @bien2
select * from NhanVien



/*
3. Tạo SP cập nhật trường NgaySinh cho các nhân viên (thủ tục có hai tham số đầu vào
gồm mã nhân viên, Ngaysinh). Nếu không tìm thấy bản ghi cần cập nhật trả ra giá trị 0.
Ngược lại, cho phép cập nhật.
*/

create proc SP(@MaNV nvarchar(4), @NgaySinh datetime, @flag int output)
as
begin
	if(exists(select * from NhanVien where MaNV = @MaNV))
		begin
			update NhanVien
			set NgaySinh = @NgaySinh
			where MaNV = @MaNV
			print N'Dữ liệu ngày sinh đã được cập nhập thành công cho nhân viên có mã: ' + @MaNV
			set @flag = 1
		end
	else
		begin
			set @flag = 0
			print N'Mã nhân viên ' + @MaNV + N' không tồn tại trong bảng NhanVien'
		end
	return @flag
end

--Test1: MaNV không tồn tại
declare @bien3 int
exec SP 'NV09', '2/28/1998 13:00:00', @bien3 output
select @bien3
select * from NhanVien

--Test2: MaNV tồn tại và cho phép cập nhập
declare @bien4 int
exec SP 'NV08', '2/28/1998 13:00:00', @bien4 output
select @bien4
select * from NhanVien
