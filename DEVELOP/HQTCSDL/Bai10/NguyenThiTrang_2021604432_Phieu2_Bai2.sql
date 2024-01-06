create database QLBH
go
use QLBH


create table Mathang (
	mahang int primary key,
	tenhang nvarchar(40),
	soluong int
)

create table Nhatkybanhang (
	stt int primary key,
	ngay date,
	nguoimua nvarchar(40),
	mahang int,
	--foreign key (mahang) references Mathang(mahang),
	soluong int,
	giaban money
)



--Nhập dữ liệu
insert into Mathang
values(1, 'Keo', 100),
	  (2, 'Banh', 200),
	  (3, 'KThuoc', 100)

insert into Nhatkybanhang
values(1, '1999-02-09', 'ab', 2, 230, 500000)

-- Xem dữ liệu
select * from Mathang
select * from Nhatkybanhang

/*
a. trg_nhatkybanhang_insert. Trigger này có chức năng tự động giảm số lượng
hàng hiện có (Trong bảng MATHANG) khi một mặt hàng nào đó được bán (tức
là khi câu lệnh INSERT được thực thi trên bảng NHATKYBANHANG).
+
c. Trigger dưới đây được kích hoạt khi câu lệnh INSERT được sử dụng để bổ sung
một bản ghi mới cho bảng NHATKYBANHANG. Trong trigger này kiểm tra
điều kiện hợp lệ của dữ liệu là số lượng hàng bán ra phải nhỏ hơn hoặc bằng số
lượng hàng hiện có. Nếu điều kiện này không thoả mãn thì huỷ bỏ thao tác bổ
sung dữ liệu
*/

alter trigger trg_nhatkybanhang_insert on Nhatkybanhang
after insert
as
begin
	declare @mahang int
	set @mahang = (select mahang from inserted)
	if(not exists(select * from Mathang where mahang = @mahang))
		begin
			raiserror('Lỗi không có mặt hàng đó trong cơ sở dữ liệu',16,1)
			rollback transaction
		end
	else 
		begin
			declare @soluongban int, @soluongcon int
			select @soluongban = soluong from inserted
			select @soluongcon = soluong from Mathang where mahang = @mahang
			if(@soluongban < @soluongcon)
				begin
					update Mathang
					set Mathang.soluong = @soluongcon - @soluongban
					where Mathang.mahang = @mahang
				end
			else
				begin
					raiserror('Không đủ số lượng bán', 16,1)
					rollback transaction
				end
		end
end

--Test1: Mã hàng không tồn tại
insert into Nhatkybanhang
values(2, '1999-10-10', 'Trang', 50, 50, 6000000)
--Test2: Hết hàng
insert into Nhatkybanhang
values(2, '1999-10-10', 'Trang', 1, 150, 6000000)
--Test3: Cho phép nhập dữ liệu
select * from Mathang
select * from Nhatkybanhang
insert into Nhatkybanhang
values(2, '1999-10-10', 'Trang', 1, 50, 6000000)
select * from Mathang
select * from Nhatkybanhang

disable trigger trg_nhatkybanhang_insert on Nhatkybanhang

/*
b. trg_nhatkybanhang_update_soluong được kích hoạt khi ta tiến hành cập nhật
cột SOLUONG cho một bản ghi của bảng NHATKYBANHANG (lưu ý là chỉ
cập nhật đúng một bản ghi).
*/

alter trigger trg_nhatkybanhang_update_soluong
on Nhatkybanhang
after update
as
begin 
	update Mathang
	set Mathang.soluong = Mathang.soluong - inserted.soluong + deleted.soluong
	from Mathang inner join inserted
						on inserted.mahang = Mathang.mahang
				 inner join deleted
						on deleted.mahang = Mathang.mahang
	where deleted.stt = inserted.stt
end


--test: Với trigger ở ví dụ trên, câu lệnh:
select * from Mathang
select * from Nhatkybanhang
UPDATE Nhatkybanhang SET soluong=soluong+20 WHERE stt=1
select * from Mathang
select * from Nhatkybanhang

/*
d.Trigger dưới đây nhằm để kiểm soát lỗi update bảng nhatkybanhang, nếu update
>1 bản ghi thì thông báo lỗi(Trigger chỉ làm trên 1 bản ghi), quay trở về. Ngược
lại thì update lại số lượng cho bảng mathang
*/

alter trigger trg_nhatkybanhang_update_soluong
on Nhatkybanhang
after update
as
begin 
	if((select count(*) from inserted) > 1)
		begin
			raiserror(N'Không được cập nhập quá nhiều dữ liệu',16,1)
			rollback transaction
		end
	else
		begin
			if(UPDATE(soluong))
				begin
					update Mathang
					set Mathang.soluong = Mathang.soluong - inserted.soluong + deleted.soluong
					from Mathang inner join inserted
										on inserted.mahang = Mathang.mahang
									inner join deleted
										on deleted.mahang = Mathang.mahang
					where deleted.stt = inserted.stt
				end
			else
				begin
					raiserror(N'Cột bạn đang cập nhập không phải cột số lượng',16,1)
					rollback transaction
				end
		end
end

--Test1: Cập nhập nhiều bản ghi 
update Nhatkybanhang
set soluong = 50

-- Test2: Cột cập nhập không phải cột soluong
update Nhatkybanhang 
set nguoimua = 'c'
where stt = 2

--Test3: Cho phép cập nhập
select * from Mathang
select * from Nhatkybanhang
update Nhatkybanhang
set soluong = soluong - 48
where stt = 1
select * from Mathang
select * from Nhatkybanhang

/*
e. Hãy tao Trigger xoa 1 ban ghi bang nhatkybanhang, neu xoa nhieu hon 1 record
thi hay thong bao loi xoa ban ghi, nguoc lai hay update bang mathang voi cot so
luong tang len voi ma hang da xoa o bang nhatkybanhang.
*/

alter trigger xoa_nhatkybanhang
on Nhatkybanhang
after delete
as
begin
	if((select count(*) from deleted) > 1)
		begin
			raiserror(N'Bạn chỉ được phét xóa một bản ghi',16,1)
			rollback transaction
		end
	else
		begin 
			if(not exists(select 1 from Nhatkybanhang where stt = (select stt from deleted)))
				begin
					raiserror(N'Không tìm thấy bản ghi cần xóa',16,1)
					rollback transaction
				end
			else
				begin
					update Mathang
					set Mathang.soluong = Mathang.soluong + deleted.soluong
					from deleted inner join Mathang
										on Mathang.mahang = deleted.mahang
				end
		end
end

--Test1: Trường hợp xóa nhiều hơn một bản ghi
delete Nhatkybanhang
select * from Nhatkybanhang

--Test2: Không tìm thấy mã hóa đơn cần xóa
delete Nhatkybanhang
where stt = 2000
select * from Nhatkybanhang

--Test3: Cho phép xóa
select * from Mathang
select * from Nhatkybanhang
delete Nhatkybanhang
where stt = 1
select * from Mathang
select * from Nhatkybanhang