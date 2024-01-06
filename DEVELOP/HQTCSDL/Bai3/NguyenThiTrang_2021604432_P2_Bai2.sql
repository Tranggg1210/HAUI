create database MarkManagement;
go 
use MarkManagement

create table Students (
	StudentID nvarchar(12) primary key,
	StudentName nvarchar(25) not null,
	DateofBirth date not null,
	Email nvarchar(40),
	Phone nvarchar(12),
	Class nvarchar(10)
)

create table Subjects (
	SubjectID nvarchar(10) primary key,
	SubjectName nvarchar(25) not null
)

create table Mark (
	StudentID nvarchar(12),
	SubjectID nvarchar(10),
	Date1 date,
	Theory tinyint,
	practical tinyint,
	primary key(StudentID, SubjectID)
)


insert into Students 
values('AV0807005', N'Mail Trung Hiếu', '10-11-1989', 'trunghieu@yahoo.com', '0904115116', 'AV1'),
	  ('AV0807006', N'Nguyễn Quý Hùng', '12-02-1988', 'quyhung@yahoo.com', '0955667787', 'AV2'),
	  ('AV0807007', N'Đỗ Đắc Huỳnh', '01-02-1990', 'dachuynh@yahoo.com', '0988574747', 'AV2'),
	  ('AV0807009', N'An Đăng Khuê', '03-06-1986', 'dangkhue@yahoo.com', '0986757463', 'AV1'),
	  ('AV0807010', N'Nguyễn Thị Tuyết Lan', '07-12-1989', 'tuyetlan@yahoo.com', '0983310342', 'AV2'),
	  ('AV0807011', N'Đinh Phụng Long', '12-02-1990', 'phunglong@yahoo.com', null, 'AV1'),
	  ('AV0807012', N'Nguyễn Tuấn Nam', '03-02-1990', 'tuannam@yahoo.com', null, 'AV1')

insert into Subjects
values('S001', 'SQL'),
	  ('S002', 'Java Simplefied'),
	  ('S003', 'Active Server Page')

insert into Mark
values('AV0807005', 'S001', '05-06-2008', 8, 25),
	  ('AV0807006', 'S002', '05-06-2008', 16, 30),
	  ('AV0807007', 'S001', '05-06-2008', 10, 25),
	  ('AV0807009', 'S003', '05-06-2008', 7, 13),
	  ('AV0807010', 'S003', '05-06-2008', 9, 16),
	  ('AV0807011', 'S002', '05-06-2008', 8, 30),
	  ('AV0807012', 'S001', '05-06-2008', 7, 31),
	  ('AV0807005', 'S002', '06-06-2008', 12, 11),
	  ('AV0807009', 'S002', '06-06-2008', 11, 20),
	  ('AV0807010', 'S001', '06-06-2008', 7, 6)


/*1. Hiển thị nội dung bảng Students*/
select * from Students

/*2. Hiển thị nội dung danh sách sinh viên lớp AV1*/
select * 
from Students
where Class = 'AV1'

/*3. Sử dụng lệnh UPDATE để chuyển sinh viên có mã AV0807012 sang lớp AV2*/
update Students
set Class = 'AV2'
where StudentID = 'AV0807012'

/*4. Tính tổng số sinh viên của từng lớp*/
select Class, count(*) ['So luong sinh vien cua lop']
from Students
group by Class;

/*5. Hiển thị danh sách sinh viên lớp AV2 được sắp xếp tăng dần theo
StudentName*/

select *
from Students
where Class = 'AV2'
order by StudentName

/*6. Hiển thị danh sách sinh viên không đạt lý thuyết môn S001 (theory <10) thi
ngày 6/5/2008*/select Students.StudentID, StudentName, DateofBirth, Email, Phone, Class, Theory, SubjectID, Date1from Students inner join Mark					on Students.StudentID = Mark.StudentIDwhere Date1 = '05-06-2008' and Theory < 10 and SubjectID = 'S001'/*7. Hiển thị tổng số sinh viên không đạt lý thuyết môn S001. (theory <10)*/select count(*) ['Số sinh viên không đạt môn S001']from Markwhere Theory < 10 and SubjectID = 'S001'/*8. Hiển thị Danh sách sinh viên học lớp AV1 và sinh sau ngày 1/1/1980*/select *from Studentswhere Class = 'AV1' and DateofBirth > '01-01-1980'/*9. Xoá sinh viên có mã AV0807011*/delete from Studentswhere StudentID = 'AV0807011'/*10.Hiển thị danh sách sinh viên dự thi môn có mã S001 ngày 6/5/2008 bao gồm
các trường sau: StudentID, StudentName, SubjectName, Theory, Practical,
Date*/select Students.StudentID, StudentName, SubjectName, Theory, Practical, Date1from Mark inner join Students				on Mark.StudentID = Students.StudentID		  inner join Subjects				on Mark.SubjectID = Subjects.SubjectID