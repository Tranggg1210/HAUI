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
Hãy tạo 1 trigger insert HoaDon, hãy kiểm tra xem mahang cần mua có tồn
tại trong bảng HANG không, nếu không hãy đưa ra thông báo.
 - Nếu thỏa mãn hãy kiểm tra xem: soluongban <= soluong? Nếu không hãy đưa
ra thông báo.
 - Ngược lại cập nhật lại bảng HANG với: soluong = soluong - soluongban
*/


create trigger dathang 
on Hoadon
after insert
as
begin
	if(not exists (select * 
				   from Hang inner join inserted
								   on Hang.Mahang = inserted.Mahang))
		begin
			raiserror(N'Lỗi không có hàng',16,1)
			rollback transaction
		end
	else
		begin
			declare @soluong int
			declare @soluongban int
			select @soluong = Soluong from hang inner join inserted
													  on Hang.Mahang = inserted.Mahang
			select @soluongban =  inserted.Soluongban
			from inserted

			if(@soluong <= @soluongban)
				begin
					raiserror(N'Không đủ hàng để bán',16,1)
					rollback transaction
				end
			else
				begin
					update Hang
					set Soluong = @soluong - @soluongban
					from Hang inner join inserted on inserted.Mahang = Hang.Mahang
				end
		end
end


--gọi trigger
insert into Hoadon values('HD01', 'H01', 50, '12/10/2023')
select * from Hoadon
select * from Hang

--Ko đủ hàng để bán
insert into Hoadon values('HD02', 'H01', 250, '12/10/2023')
select * from Hoadon
select * from Hang

--Hàng ko tồn tại
insert into Hoadon values('HD03', 'H016', 50, '12/10/2023')
select * from Hoadon
select * from Hang

