create database QLBH
go
use QLBH

create table Hang (
	Mahang nchar(10) primary key,
	Tenhang nvarchar(40) not null,
	Soluong int not null,
	GiaBan money not null
)

create table Hoadon(
	Mahd nchar(10) primary key,
	Mahang nchar(10),
	foreign key (Mahang) references Hang(Mahang),
	Soluongban int not null,
	Ngayban date not null,
)

insert into Hang 
values('H01', N'Ti vi', 150, 150000000),
	  ('H02', N'Tủ lạnh', 100, 200000000),
	  ('H03', N'Máy giặt', 250, 90000000),
	  ('H04', N'Lò vi sóng', 108, 80000000),
	  ('H05', N'Bếp từ', 99, 20000000)


/*
Câu 1 (5đ). Viết trigger kiểm soát việc Delete bảng HOADON, Hãy cập nhật lại
soluong trong bảng HANG với: SOLUONG =SOLUONG +
DELETED.SOLUONGBAN
*/

create trigger xoa on Hoadon
after delete
as
begin
	declare @Mahd nchar(10)
	select @Mahd = Mahd from deleted
	if(exists(select * from Hoadon where Mahd = @Mahd))
		begin
			update Hang
			set Soluong = Soluong + deleted.Soluongban
			from Hang inner join deleted on deleted.Mahang = Hang.Mahang
			print N'Đã hủy hàng thành công'
		end
	else
		begin
			raiserror(N'Không tìm thấy hóa đơn mà bạn muốn hủy',16,1)
			rollback transaction
		end
end

drop trigger xoa

--Test1: Không có hóa đơn cần tìm
delete Hoadon
where Mahd = 'HD02'
select * from Hang
select * from Hoadon


--Test2: Tìm thấy hóa đơn cần xóa
delete from Hoadon
where Mahd = 'HD01'
select * from Hang
select * from Hoadon


/*
Câu 2 (5đ). Hãy viết trigger kiểm soát việc Update bảng HOADON. Khi đó hãy
update lại soluong trong bảng HANG.
*/
create trigger capnhap on Hoadon
after update
as
begin
	if(exists(select * from Hang inner join inserted on inserted.Mahang = Hang.Mahang ))
		begin
			update Hang
			set Soluong = Soluong - inserted.Soluongban  + deleted.Soluongban 
			from Hang inner join inserted
							on inserted.Mahang = Hang.Mahang
					  inner join deleted
							on deleted.Mahang = Hang.Mahang
		end
	else
		begin
			raiserror( N'Không tìm thấy mã hàng muốn cập nhập',16,1)
			rollback transaction
		end
end

drop trigger capnhap

--Test1: Không tìm thấy mã hàng muốn cập nhập
update Hoadon set Soluongban = Soluongban-5 where Mahang = 'H03'
select * from Hang
select * from Hoadon

--Test1: Tìm thấy mã hàng muốn cập nhập
update Hoadon set Soluongban = Soluongban-5 where Mahang = 'H02'
select * from Hang
select * from Hoadon
