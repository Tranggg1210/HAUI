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
1. Viết thủ tục SP_Them_Nhan_Vien, biết tham biến là MaNV, MaCV,
TenNV,Ngaysinh,LuongCanBan,NgayCong,PhuCap. Kiểm tra MaCV có tồn tại
trong bảng tblChucVu hay không? nếu thỏa mãn yêu cầu thì cho thêm nhân viên
mới, nếu không thì đưa ra thông báo. 
*/
create proc SP_Them_Nhan_Vien(@MaNV nvarchar(4),
							  @MaCV nvarchar(2), 
							  @TenNV nvarchar(40), 
							  @NgaySinh datetime, 
							  @LuongCanBan float, 
							  @NgayCong int, 
							  @PhuCap float)
as
begin
	if(not exists(select * from ChucVu where MaCV = @MaCV))
		print N'Mã công việc ' + @MaCV + N' không tồn tại trong bảng ChucVu'
	else
		begin
			insert into NhanVien
			values(@MaNV, @MaCV, @TenNV, @NgaySinh, @LuongCanBan, @NgayCong, @PhuCap)
			print N'Dữ liệu bạn nhập đã được thêm mới vào bảng NhanVien'
		end
end

-- Test1: MaCV chưa tồn tại
exec SP_Them_Nhan_Vien 'NV06', 'NC', N'Bùi Văn Tí', '10/10/1978 12:00:00', 400000,24,100000
select * from NhanVien

-- Test2: MaCV đã tồn tại
exec SP_Them_Nhan_Vien 'NV06', 'HC', N'Nguyễn Thị Ánh', '12/6/1979 12:00:00', 900000,31,200000
select * from NhanVien

/*
2 Viết thủ tục SP_CapNhat_Nhan_Vien( không cập nhật mã ), biết tham biến là MaNV, MaCV, TenNV, 
Ngaysinh, LuongCanBan, NgayCong, PhuCap. Kiểm tra MaCV có tồn tại trong bảng tblChucVu hay không? nếu thỏa mãn yêu cầu thì 
cho cập nhật, nếu không thì đưa ra thông báo*/
create proc SP_CapNhat_Nhan_Vien(@MaNV nchar(10), 
								 @MaCV nchar(10), 
								 @TenNV nvarchar(40), 
								 @NgaySinh datetime, 
								 @LuongCanBan float, 
								 @NgayCong int, 
								 @PhuCap float)
as
begin
	if(exists(select * from ChucVu where MaCV = @MaCV))
		begin
			update NhanVien
			set TenNV = @TenNV,
				MaCV = @MaCV,
				NgaySinh = @NgaySinh,
				LuongCanBan = @LuongCanBan,
				NgayCong = @NgayCong,
				PhuCap = @PhuCap
			where MaNV = @MaNV
			print N'Dữ liệu của nhân viên có mã ' + @MaNV + ' đã được cập nhập'
		end
	else
		print N'Mã công việc ' + @MaCV + N' không tồn tại trong bảng ChucVu'
end



--Test1: Mã chức vụ không tồn tại
exec SP_CapNhat_Nhan_Vien 'NV04', 'FC', N'Nguyễn Thị Út', '10/10/1980 12:00:00', 300000,26,300000
select * from NhanVien

--Test2: Mã chức vụ tồn tại và cho phép update
exec SP_CapNhat_Nhan_Vien 'NV04', 'HC', N'Nguyễn Thị Út', '10/10/1980 12:00:00', 300000,26,300000
select * from NhanVien

/*
3) Viết thủ tục SP_LuongLN với Luong = LuongCanBan*NgayCong*PhuCap, biết thủ tục trả về, không truyền tham biến
*/

CREATE PROCEDURE SP_LuongLN
AS
BEGIN
    SELECT TenNV, LuongCanBan, NgayCong, PhuCap, LuongCanBan*NgayCong*PhuCap AS Luong
    FROM NhanVien
END


--Test
exec SP_LuongLN 
