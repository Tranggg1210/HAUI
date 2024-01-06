create database DeptEmp
go
use DeptEmp

create table Department (
	DepartmentNo int primary key,
	DepartmentName char(25) not null,
	DepartmentLocation char(25) not null
)

create table Employee (
	EmpNo int primary key,
	Fname varchar(15) not null,
	Lname varchar(15) not null,
	Job varchar(25) not null,
	HireDate date not null,
	Salary money not null,
	Commision money,
	DepartmentNo int,
	foreign key (DepartmentNo)
	references Department(DepartmentNo)
)

insert into Department
values(10, 'Accounting', 'Melbourne'),
	  (20, 'Research', 'Adealide'),
	  (30, 'Sales', 'Sydney'),
	  (40, 'Operations', 'Perth')

insert into Employee
values(1, 'John', 'Smith', 'Clerk', '12-17-1980', 800, null, 20),
	  (2, 'Peter', 'Allen', 'Salesman', '11-20-1981', 1600, 300, 30),
	  (3, 'Kate', 'Ward', 'Salesman', '11-22-1981', 1250, 500, 30),
	  (4, 'Jack', 'Jones', 'Manager', '07-02-1981', 2975, null, 20),
	  (5, 'Joe', 'Martin', 'Salesman', '09-28-1910', 1250, 1400, 20)

/*1.Hiển thị nội dung bảng Department*/

select * from Department;

/*2.Hiển thị nội dung bảng Employee*/

select * from Employee;

/*3. Hiển thị employee number, employee first name và employee last name từ
bảng Employee mà employee first name có tên là ‘Kate’.*/

select EmpNo, Fname, Lname
from Employee
where Fname = 'Kate'

/*4. Hiển thị ghép 2 trường Fname và Lname thành Full Name, Salary,
10%Salary (tăng 10% so với lương ban đầu). */

select (Fname + ' ' + Lname) FullName, Salary, (Salary +  Salary*0.1)
from Employee

/*5. Hiển thị Fname, Lname, HireDate cho tất cả các Employee có HireDate là
năm 1981 và sắp xếp theo thứ tự tăng dần của Lname.*/

select Fname, Lname, HireDate
from Employee
where year(HireDate) = 1981
order by Lname

/*
6. Hiển thị trung bình(average), lớn nhất (max) và nhỏ nhất(min) của
lương(salary) cho từng phòng ban trong bảng Employee.
*/

select avg(Salary) ['Trung bình lương'], 
	   max(Salary) ['Lương lớn nhất'], 
	   min(Salary) ['Lương nhỏ nhất']
from Employee
group by DepartmentNo

/*7. Hiển thị DepartmentNo và số người có trong từng phòng ban có trong bảng
Employee.*/

select DepartmentNo, count(*) ['Số lượng nhân viên trong phòng ban']
from Employee
group by DepartmentNo

/*8. Hiển thị DepartmentNo, DepartmentName, FullName (Fname và Lname),
Job, Salary trong bảng Department và bảng Employee.*/
select Department.DepartmentNo, DepartmentName, 
	   (Fname + ' ' + Lname ) FullName,
	   Job, Salary
from Department inner join Employee
     on Department.DepartmentNo = Employee.DepartmentNo

/*9. Hiển thị DepartmentNo, DepartmentName, Location và số người có trong
từng phòng ban của bảng Department và bảng Employee.*/
select Employee.DepartmentNo, DepartmentName, DepartmentLocation,
	   count(*) ['Số lượng nhân viên']
from Employee inner join Department 
	 on Employee.DepartmentNo = Department.DepartmentNo
group by Employee.DepartmentNo,DepartmentName, DepartmentLocation

/*10. Hiển thị tất cả DepartmentNo, DepartmentName, Location và số người có
trong từng phòng ban của bảng Department và bảng Employee*/

select all Employee.DepartmentNo, DepartmentName, DepartmentLocation,
	   count(*) ['Số lượng nhân viên'] 
from Employee inner join Department 
	 on Employee.DepartmentNo = Department.DepartmentNo
group by Employee.DepartmentNo,DepartmentName, DepartmentLocation


