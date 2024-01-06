create database QLSV
go
use QLSV

create table SV (
	MaSV nchar(10) primary key,
	TenSV nvarchar(40) not null,
	Que nvarchar(40) not null
)

create table MON (
	MaMH nchar(10) primary key,
	TenMH nvarchar(40) not  null,
	Sotc int not null
)

create table KQ (
	MaSV nchar(10),
	MaMH nchar(10),
	Diem float,
	primary key(MaSV, MaMH),
	foreign key(MaSV) references SV(MaSV),
	foreign key(MaMH) references MON(MaMH)
)


insert into SV 
values('SV01', N'Nguyễn Hương Lan', N'Hà Nội'),
	  ('SV02', N'Nguyễn Văn Nam', N'Hà Tây'),
	  ('SV03', N'Nguyễn Hà Dương', N'Hà Nam')

insert into MON
values('MH01',N'Cơ sở dữ liệu', 3),
	  ('MH02',N'NLHĐH', 4),
	  ('MH03',N'Toán rời rạc', 3)

insert into KQ
values('SV01', 'MH01', 10),
	  ('SV01', 'MH02', 8),
	  ('SV02', 'MH03', 5),
	  ('SV02', 'MH01', 3),
	  ('SV03', 'MH02', 6),
	  ('SV03', 'MH01', 5)

-- Hien thi thong tin bang sv
select * from SV

-- Hien thi thong tin bang MON
select * from MON

-- Hien thi thong tin bang KQ
select * from KQ

-- Cau2
SELECT TenSV 
FROM SV
WHERE MaSV NOT IN (
					SELECT MaSV 
					FROM KQ 
					WHERE Diem < 5
					)


-- Cau3
create view cau3
as
select SV.MaSV, count(*) Soluongmondangky
from KQ inner join SV
				on SV.MaSV = KQ.MaSV
group by SV.MaSV


-- test
select * from cau3

select TenSV
from SV
where MaSV in (
				select MaSV
				from cau3
				where Soluongmondangky = (
							select count(*)
							from MON
				))


--Cau4
create function cau4(@MaMH nchar(10))
returns @TK table(
				TenMH nvarchar(40),
				SoLuongDK int
)
as
begin
	insert into @TK
	select TenMH, count(*)
	from MON inner join KQ
					on KQ.MaMH = MON.MaMH
	where KQ.MaMH = @MaMH
	group by MON.MaMH,TenMH
return 
end



--test 
select * from cau4('MH02')


