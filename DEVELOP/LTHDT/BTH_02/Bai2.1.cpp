#include<iostream>
#include<stdio.h>
using namespace std;

class Date {
	private:
		int d, m, y;
	public:
		void nhap();
		void xuat();
};

class NhanSu {
	private:
		char mans[20];
		char hoten[40];
		Date ns;
	public:
		void nhap();
		void xuat();
};

void Date::nhap() {
	cout<<"\nNhap ngay sinh: ";									cin >> d;
	cout<<"\nNhap thang sinh: ";								cin >> m;
	cout<<"\nNhap nam sinh: ";									cin >> y;
}

void Date::xuat()
{
	cout<<"Ngay sinh: " << d << "/" << y << "/" << y << endl;
}

void NhanSu::nhap() {
	cout<< "\n=============== NHAP THONG TIN NHAN SU ===============" << endl;
	cout<< "\nNhap ma nhan su: ";			fflush(stdin);		gets(mans);
	cout<< "\nNhap ten nhan su: ";			fflush(stdin);		gets(hoten);
	ns.nhap();
}

void NhanSu::xuat() {
	cout<< "\n=============== THONG TIN NHAN SU ===============" << endl;
	cout<<"Ma nhan su: " << mans << endl;
	cout<<"Ho ten nhan su: " << hoten << endl;
	ns.xuat();
}

int main()
{
	NhanSu x;
	x.nhap();
	x.xuat();
	return 0;
}
