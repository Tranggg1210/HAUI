use master
go
create database QLBH1
on primary (
 name = "QLBH_dat",
 filename='D:\LAP_TRINH\HQTCSDL\Bai1\Ly_thuyet\QLBH1.mdf',
 size=10MB,
 maxsize = 100MB,
 filegrowth = 10MB
 )

 log on (
 name = 'QLBH1_log',
 filename='D:\LAP_TRINH\HQTCSDL\Bai1\Ly_thuyet\QLBH1.ldf',
 size = 1 MB,
 maxsize = 5MB,
 filegrowth = 20%
 )

 go 
 use QLBH1
 go
 create table CongTy1(
   MaCT nchar(10) primary key,
   TenCT nvarchar(20) not null,
   TrangThai nchar(10),
   ThanhPho nvarchar(20)
 )
 create table SanPham(
 MaSP nchar(10) primary key,
 TenSP nvarchar(20),
 MauSac nchar(10) default N'Đỏ',
 Gia money,
 SoLuongCo int,
 constraint unique_SP unique( TenSP)
 )

 create table Cungung(
 MaCT nchar(10) not null,
 MaSP nchar(10) not null,
 SoLuongBan int,
 constraint PK_CungUng Primary key(MaCT, MaSP),
 constraint chk_SLB check(SoLuongBan > 0)