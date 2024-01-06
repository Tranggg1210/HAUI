create database MarkManagement
go
use MarkManagement

create table Students (
	StudentID nvarchar(12) primary key,
	StudentName nvarchar(25) not null,
	DateofBirth datetime not null,
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
	foreign key(StudentID) references Students(StudentID),
	SubjectID nvarchar(10),
	foreign key(SubjectID) references Subjects(SubjectID),
	primary key(StudentID, SubjectID),
	Date_Mark Datetime,
	Theory tinyint,
	Practical tinyint
)

insert into Students
values('AV0807005', N'Mail Trung Hiếu', '11/10/1989', 'trunghieu@yahoo.com', '0904115116','AV1'),
	  ('AV0807006', N'Nguyễn Quý Hùng', '2/12/1988', 'quyhung@yahoo.com', '0955667787','AV2'),
	  ('AV0807007', N'Đỗ Đắc Huỳnh', '2/1/1990', 'dachuynh@yahoo.com', '0988574747','AV2'),
	  ('AV0807009', N'An Đăng Khuê', '6/3/1986', 'dangkhue@yahoo.com', '0986757463','AV1'),
	  ('AV0807010', N'Nguyễn T.Tuyết Lan', '12/7/1989', 'tuyetlan@yahoo.com', '0983310342','A21'),
	  ('AV0807011', N'Đinh Phụng Long', '2/12/1990', 'phunglong@yahoo.com', '','AV1'),
	  ('AV0807012', N'Nguyễn Tuấn Nam', '2/3/1990', 'tuannam@yahoo.com', '','AV1')

insert into Subjects
values('S001', 'SQL'),
	  ('S002', 'Java Simplefield'),
	  ('S003', 'Active Server Page')

insert into Mark
values('AV0807005', 'S001', 8, 25, '6/5/2008'),
	  ('AV0807006', 'S002', 16, 30, '6/5/2008'),
	  ('AV0807007', 'S001', 10, 25, '6/5/2008'),
	  ('AV0807009', 'S003', 7, 13, '6/5/2008'),
	  ('AV0807010', 'S003', 9, 16, '6/5/2008'),
	  ('AV0807011', 'S002', 8, 30, '6/5/2008'),
	  ('AV0807012', 'S001', 7, 31, '6/5/2008'),
	  ('AV0807005', 'S002', 12, 11, '6/6/2008'),
	  ('AV0807010', 'S001', 7, 6, '6/6/2008')

