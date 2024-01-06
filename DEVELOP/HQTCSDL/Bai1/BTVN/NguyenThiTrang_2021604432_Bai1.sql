create database QLSV
go
use QLSV;

create table SV (
	MaSV nchar(10) primary key,
	TenSV nvarchar(40) not null,
	Que nvarchar(40) not null
)

create table MON (
	MaMH nchar(10) primary key,
	TenMH nvarchar(40) not null,
	unique(TenMH),
	Sotc int default(3),
	check(Sotc >= 2 and Sotc <= 5)
)

create table KQ(
	MaSV nchar(10),
	constraint masv_sv_kq
	foreign key(MaSV)
	references SV(MaSV),
	MaMH nchar(10),
	constraint mamh_sv_kq
	foreign key(MaMH)
	references MON(MaMH),
	Diem float not null,
	check( Diem >= 0 and Diem <=10),
	constraint pk_kq primary key(MaMH,MaSV)
)

select * from SV
select * from MON
select * from KQ
