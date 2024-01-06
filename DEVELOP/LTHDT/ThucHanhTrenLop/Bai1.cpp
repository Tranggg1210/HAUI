#include<bits/stdc++.h>
using namespace std;

class student;

class school{
	private:
		char name[20];
		char date[15];
	friend class faculty;
	friend void setSchoolName(student &sv);
};

class faculty {
	private:
		char name[20];
		char date[15];
		school x;
	public:
		void input();
		void output();
	friend void setSchoolName(student &sv);
};

class person {
	protected:
		char name[20];
		char birth[15];
		char address[20];
	public:
		void input();
		void output();
		person();
};

class student : public person {
	private:
		faculty y;
		char className[20];
		float score;
	public:
		void input();
		void output();
		student();
	friend void setSchoolName(student &sv);
};

void faculty::input() {
	cout<<"\nNhap ten truong: ";				fflush(stdin);				gets(x.name);
	cout<<"\nNhap ngay thanh lap truong: ";		fflush(stdin);				gets(x.date);
	cout<<"\nNhap ten khoa: ";					fflush(stdin);				gets(name);
	cout<<"\nNhap ngay thanh lap khoa: ";		fflush(stdin);				gets(date);
}

void faculty::output() {
	cout<< "\nTen truong: " << x.name;
	cout<< "\nNgay lap truong: " << x.date;
	cout<< "\nTen khoa: " << name;
	cout<< "\nNgay lap khoa: "   << date;
}

void person::input() {
	cout<<"\nNhap ho ten: ";					fflush(stdin);				gets(name);
	cout<<"\nNhap ngay sinh: ";					fflush(stdin);				gets(birth);
	cout<<"\nNhap dia chi: ";					fflush(stdin);				gets(address);
}

void person::output() {
	cout<<"\nHo ten: " << name;
	cout<<"\nNgay sinh: " << birth;
	cout<<"\nDia chi: " << address;
}

person::person(){
	
}

void student::input() {
	cout<<"\n========== NHAP THONG TIN SINH VIEN ==========" << endl;
	y.input();
	person::input();
	
	cout<<"\nNhap ten lop: ";					fflush(stdin);				gets(className);
	do{
		cout<<"\nNhap diem >= 0 va diem <=10: ";							cin>>score;
	}while(score < 0 || score >10);
}

void student::output(){
	y.output();
	person::output();
	cout<<"\nTen lop: " << className;
	cout<<"\nDiem: " << score;
}

student::student() {
	score = 0;
}

void setSchoolName(student &sv) {
	strcpy(sv.y.x.name,"DHCNHN");
}

main()
{
	student sv;
	sv.input();
	cout<<"\n========== THONG TIN SINH VIEN ==========" << endl;
	sv.output();
	cout<<"\n========== THONG TIN SINH VIEN SAU KHI SUA TEN TRUONG ==========" << endl;
	setSchoolName(sv);
	sv.output();
}
/*
CNHN
18/9/1999
CNTT
12/10/1999
Trang 
12/10/2003
Hung Yen
KTPM03
10
*/
