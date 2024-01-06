#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class student;

class school {
	private:
		char name[40];
		char date[20];
	friend class faculty;
	friend void update(student &s); 
};

class faculty {
	private:
		char name[40];
		char date[20];
		school x;
	public:
		void input();
		void output();
	friend void update(student &s); 
};

class person {
	private:
		char name[40];
		char birth[20];
		char address[40];
	public:
		void input();
		void output();
		person();
};

class student: public person {
	private:
		faculty y;
		char Class[40];
		float score;
	public:
		void input();
		void output();
		student();
	friend void update(student &s);
};

void faculty::input() {
	cout<<"\nNhap ten khoa: ";						fflush(stdin);				gets(name);
	cout<<"\nNhap ngay thanh lap khoa: ";			fflush(stdin);				gets(date);
	cout<<"\nNhap ten truong: ";					fflush(stdin);				gets(x.name);
	cout<<"\nNhap ngay thanh lap truong: ";			fflush(stdin);				gets(x.date);
}


void faculty::output() {
	cout<<"Ten khoa: " << name << endl;
	cout<<"Ngay lap khoa: " << date << endl;
	cout<<"Ten truong: " << x.name << endl;
	cout<<"Ngay thanh lap truong: " << x.date << endl;
}

void person::input() {
	cout<<"\nNhap ho ten: ";						fflush(stdin);				gets(name);
	cout<<"\nNhap ngay sinh: ";						fflush(stdin);				gets(birth);
	cout<<"\nNhap dia chi: ";						fflush(stdin);				gets(address);
}

void person::output() {
	cout<<"Ho ten: " << name << endl;
	cout<<"Ngay sinh: " << birth << endl;
	cout<<"Dia chi: " << address << endl;
}

person::person() {
	
}

void student::input() {
	cout<< "\n================ NHAP THONG TIN SINH VIEN ================" << endl;
	y.input();
	person::input();
	cout<<"\nNhap ten lop cua sv: ";				fflush(stdin);				gets(Class);
	cout<<"\nNhap diem cua sv: ";												cin >> score;
}

void student::output() {
	y.output();
	person::output();
	cout<<"Ten lop: " << Class << endl;
	cout<<"Diem: " << score << endl;
}

student::student() {
	score = 0;
}

void update(student &s)
{
	strcpy(s.y.x.name,"DHCNHN");
}

int main()
{
	student sv;
	sv.input();
	cout<< "\n================ XUAT THONG TIN SINH VIEN ================" << endl;
	sv.output();
	cout<< "\n================ XUAT THONG TIN SINH VIEN SAU KHI SUA ================" << endl;
	update(sv);
	sv.output();
	return 0;
}
