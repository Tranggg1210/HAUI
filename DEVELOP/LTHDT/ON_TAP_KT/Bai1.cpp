#include<bits/stdc++.h>
using namespace std;

class student;

class school {
	private:
		char name[40];
		char date[20];
	friend class faculty;
	friend void update(student &a);
};

class faculty {
	private:
		char name[40];
		char date[20];
		school x;
	public:
		void input();
		void output();
	friend void update(student &a);
		
};

class person {
	protected:
		char name[40];
		char birth[20];
		char address[40];
	public:
		void input();
		void output();
		person();
};

class student : public person {
	private:
		faculty y;
		char class1[40];
		float score;
	public:
		student();
		void input();
		void output();
	friend void update(student &a);
};

void faculty::input() {
	cout<<"\nNhap ten truong: ";					fflush(stdin);				gets(x.name);
	cout<<"\nNhap ngay thanh lap truong: ";			fflush(stdin);				gets(x.date);
	cout<<"\nNhap ten khoa: ";						fflush(stdin);				gets(name);
	cout<<"\nNhap ngay thanh lap khoa: ";			fflush(stdin);				gets(date);
}

void faculty::output() {
	cout<<"\nTruong: " << x.name;
	cout<<"\nNgay thanh lap truong: " << x.date;
	cout<<"\nKhoa: " << name;
	cout<<"\nNgay thanh lap khoa: " << date;
}

void person::input() {
	cout<<"\nNhap ten sinh vien: ";					fflush(stdin);				gets(name);
	cout<<"\nNhap ngay sinh cua sinh vien: ";		fflush(stdin);				gets(birth);
	cout<<"\nNhap dia chi cua sinh vien: ";			fflush(stdin);				gets(address);
}

void person::output() {
	cout<<"\nTen sinh vien: " << name;
	cout<<"\nNgay sinh cua sinh vien: " << birth;
	cout<<"\nDia chi cua sinh vien: " << address;
}

person::person() {
	
}

void student::input() {
	cout<<"\n==== NHAP THONG TIN CUA SINH VIEN =====" << endl;
	y.input();
	person::input();
	cout<<"\nNhap ten lop hoc cua sinh vien: ";		fflush(stdin);				gets(class1);
	cout<<"\nNhap diem cua sinh vien: ";										cin>>score;
}

void student::output() {
	y.output();
	person::output();
	cout<<"\nLop: " << class1;
	cout<<"\nDiem: " << score; 
}
student::student(){
	
}

void update(student &a)
{
	strcpy(a.y.x.name, "DHCNHN");
}

main()
{
	student a;
	a.input();
	cout<<"\n===== THONG TIN CUA SINH VIEN ====" << endl;
	a.output();
	cout<<"\n\n===== THONG TIN CUA SINH VIEN SAU KHI SUA TEN TRUONG ====" << endl;
	update(a);
	a.output();
}
