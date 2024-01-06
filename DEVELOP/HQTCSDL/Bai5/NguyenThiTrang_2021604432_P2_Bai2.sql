create database QLSV
go
use QLSV

-- Bai1

create table LOP (
	MaLop nchar(10) primary key,
	TenLop nvarchar(40) not null,
	Phong nchar(20) not  null
)

create table SV (
	MaSV nchar(10) primary key,
	TenSV nvarchar(40) not null,
	MaLop nchar(10)
	foreign key (MaLop) references LOP(MaLop)
)

insert into LOP 
values('1', 'CD', '1'),
	  ('2', 'DH', '2'),
	  ('3', 'LT', '2'),
	  ('4', 'CH', '4')

insert into SV 
values('1','A','1'),
	  ('2','B','2'),
	  ('3','C','1'),
	  ('4','D','3')

-- Bai2

/*1. Viết hàm thống kê xem mỗi lớp có bao nhiêu 
sinh viên với malop là tham số truyền vào
từ bàn phím.*/

create function thongke(@malop nchar(10))
returns int
as
	begin
		declare @soluongsv int
		set @soluongsv = (
							select count(*)
							from SV
							where MaLop = @malop
		)
	return @soluongsv
	end

-- test
select dbo.thongke('2')


/*2. Đưa ra danh sách sinh viên(masv,tensv) 
học lớp với tenlop được truyền vào từ bàn phím.*/
create function dssv(@tenlop nvarchar(40))
returns @dssvtheolop table(
			masv nchar(10) primary key,
			tensv nvarchar(40))
as
begin
	insert into @dssvtheolop
	select MaSV, TenSV
	from SV inner join LOP
					on LOP.MaLop = SV.MaLop
	where TenLop = @tenlop
return
end

-- test
select * from dssv('CD')


/*3. Đưa ra hàm thống kê sinhvien: malop,tenlop,
soluong sinh viên trong lớp, với tên lớp được 
nhập từ bàn phím. Nếu lớp đó chưa tồn tại thì 
thống kê tất cả các lớp, ngược lại nếu lớp đó 
đã tồn tại thì chỉ thống kê mỗi lớp đó.*/

create function bai3(@tenlop nvarchar(40))
returns @tk table(
				malop nchar(10) primary key,
				tenlop nvarchar(40),
				soluongsv int
)
as
begin
	if(not exists(select MaLop from LOP where TenLop = @tenlop))
		insert into @tk 
		select LOP.MaLop, TenLop, count(*)
		from LOP inner join SV on SV.MaLop = LOP.MaLop
		group by LOP.MaLop, TenLop
	else
		insert into @tk 
		select LOP.MaLop, TenLop, count(*)
		from LOP inner join SV on SV.MaLop = LOP.MaLop
		where TenLop = @tenlop
		group by LOP.MaLop, TenLop
	
return
end



select * from bai3('2')


/*4. Đưa ra phòng học của tên sinh 
viên nhập từ bàn phím.*/
create function tim(@TenSV nvarchar(40))
returns nvarchar(40)
as
begin
	declare @TenPH nvarchar(40)
	set @TenPH = (select Phong 
				  from LOP inner join SV
								on LOP.MaLop = SV.MaLop
				  where TenSV = @TenSV
				  )
return @TenPH
end

--test
select dbo.tim('D')

/*5. Đưa ra thống kê masv,tensv, tenlop với tham biến nhập từ 
bàn phím là phòng. Nếu phòng không tồn tại thì đưa ra tất cả 
các sinh viên và các phòng. Nếu phòng tồn tại thì đưa ra các
sinh vien của các lớp học phòng đó (Nhiều lớp học cùng phòng).*/