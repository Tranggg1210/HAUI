create database QLBH
go
use QLBH

create table Mathang (
	mahang int primary key,
	tenhang  nvarchar(40),
	soluong int
)

create table Nhatkybanhang (
	stt int primary key,
	ngay date,
	nguoimua nvarchar(40),
	mahang int,
	foreign key (mahang) references Mathang(mahang),
	soluong int,
	giaban money
)

insert into Mathang
values(1,'Keo',100),
	  (2,'Banh',200),
	  (3,'Thuoc',100)

insert into Nhatkybanhang 
values(1,'1999/02/09', 'ab', 2, 230, 500000)

/*
Câu 3 (7đ)Tạo các trigger:
a. trg_nhatkybanhang_insert. Trigger này có chức năng tự động giảm số lượng
hàng hiện có (Trong bảng MATHANG) khi một mặt hàng nào đó được bán (tức
là khi câu lệnh INSERT được thực thi trên bảng NHATKYBANHANG). 
*/

create trigger trg_nhatkybanhang_insert on Nhatkybanhang
after insert
as
begin
	declare @mahang int
	set @mahang = (select mahang from inserted)
	--set @mahang = (select inserted.mahang from inserted)
	if(not exists(select * from Mathang where mahang = @mahang))
		begin
			raiserror( N'Mã hàng không tồn tại', 16,1)
			rollback transaction
		end
	if(exists(select * from Mathang where mahang = @mahang))
		begin
			declare @soluongcon int, @soluongban int
			set @soluongcon = ( select soluong from Mathang where mahang = @mahang)
			set @soluongban = (select soluong from Nhatkybanhang where mahang = @mahang)
			if(@soluongban < @soluongcon)
				begin
					update Mathang
					set soluong = @soluongcon - @soluongban
					where mahang = @mahang
				end
			else 
				begin
					print N'Số lượng mặt hàng không đủ để bán'
					rollback transaction
				end
		end
	else
		begin
			print N'Mã hàng: ' + @mahang + N' không tồn tại trong bảng Mathang'
			rollback transaction
		end
end

drop trigger trg_nhatkybanhang_insert

--Test 1: Mã hàng không tồn tại
insert into Nhatkybanhang
values(2,'2023/02/09', 'Trang', 5, 10, 600000)
select * from Mathang 
select * from Nhatkybanhang
--Test 2: Mã hàng có số lượng bán nhiều hơn số lượng tồn
insert into Nhatkybanhang
values(2,'2023/02/09', 'Trang', 2, 230, 600000)
select * from Mathang 
select * from Nhatkybanhang
--Test 3: Mã hàng có số lượng bán nhiều hơn số lượng tồn
select * from Mathang
select * from Nhatkybanhang
insert into Nhatkybanhang
values(2,'2023/02/09', 'Trang', 2, 330, 600000)
select * from Mathang
select * from Nhatkybanhang
