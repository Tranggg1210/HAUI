create database TRUONGHOC
go
use TRUONGHOC

create table HOCSINH (
	mahs char(5) primary key,
	ten nvarchar(30) not null,
	nam bit not null, --Column gioitinh Nam: 1 - đúng, 0 - sai
	ngaysinh date not null,
	diachi varchar(20) not null,
	diemtb float not null
)


create table GIAOVIEN (
	magv char(5) primary key,
	ten nvarchar(30) not null,
	nam bit not null, --Column gioitinh Nam: 1 - đúng, 0 - sai
	ngaysinh date not null,
	diachi varchar(20),
	luong money
)

create table LOPHOC (
	malop char(5) primary key,
	tenlop nvarchar(30) not null,
	soluong int not null
)

insert into HOCSINH 
values('SV01',N'Hà Mai Anh', 0, '05-06-2003','Ha noi',8.9 ),
	  ('SV02',N'Nguyen Van A', 1, '07-02-2003','Ha tay',9.8 ),
	  ('SV03',N'Nguyen Thi Anh', 0, '05-06-2003','Ha nam',10)

insert into GIAOVIEN
values('GV01', N'Nguyễn Thị Nhung', 0, '02-03-1990',null, null),
	  ('GV02', N'Nguyễn Van C', 1, '03-08-1990',null, 1200000),
	  ('GV03', N'Nguyễn Van D', 1, '05-09-1990',null, 6000000)

insert into LOPHOC
values('LH01',N'Cơ sở dữ liệu',6),
	  ('LH02',N'HQTCSDL',6),
	  ('LH03',N'Toán rời rạc',12),
	  ('LH04',N'Giải tích',8),
	  ('LH05',N'Đại số tuyến tính',10)

update LOPHOC
set soluong = 16
where malop = 'LH05'

delete from GIAOVIEN
where magv = 'GV01'