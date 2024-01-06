#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

class QuanLy {
	private:
		char maql[20];
		char hoten[40];
	public:
		void nhap();
		void xuat();
};

class May {
	private:
		char mamay[20];
		char kieumay[40];
		char tinhtrang[40];
	public:
		void nhap();
		void xuat();
};

class PhongMay {
	private:
		char maphong[20];
		char tenphong[40];
		float dientich;
		QuanLy x;
		int n; 						// so luong may trong phong
		May *y;
	public:
		void nhap();
		void xuat();
		~PhongMay();
};

void QuanLy::nhap() {
	cout<<"\nNhap ma quan ly: ";							fflush(stdin);					gets(maql);
	cout<<"\nNhap ho ten quan ly: ";						fflush(stdin);					gets(hoten);
}

void QuanLy::xuat() {
	cout<<"\n\tMa quan ly: " << maql << "\t\tHo ten quan ly: " << hoten ;  
}

void May::nhap() {
	cout<<"\nNhap ma may: ";								fflush(stdin);					gets(mamay);
	cout<<"\nNhap kieu may: ";								fflush(stdin);					gets(kieumay);
	cout<<"\nNhap tinh trang cua may: ";					fflush(stdin);					gets(tinhtrang);
}


void May::xuat() {
	cout<<"\n\t" << setw(15) << mamay
		<< setw(15) << kieumay
		<< setw(15) << tinhtrang;
}

void PhongMay::nhap() {
	cout<<"\n=================== NHAP THONG TIN PHONG MAY ===================" << endl;
	cout<<"\nNhap ma phong: ";								fflush(stdin);					gets(maphong);
	cout<<"\nNhap ten phong: ";								fflush(stdin);					gets(tenphong);
	cout<<"\nNhap dien tich: ";																cin>>dientich;
	x.nhap();
	do{
		cout<<"\nNhap so luong may cua phong n: ";											cin >> n;
	}while(n < 1);
	
	y = new May[n];
	
	for(int i = 0; i < n; i++)
	{
		cout<<endl;
		cout<<"\n==== NHAP THONG TIN MAY THU " << i + 1 << " ====" << endl;
		y[i].nhap();
	}
}

void PhongMay::xuat() {
	cout<<"\n\t================== THONG TIN PHONG MAY ==================" <<endl;
	cout<<"\n\tMa phong: " << maphong << "\t\t\tTen phong: " << tenphong << endl;
	cout<<"\n\tDien tich: " << dientich << "\t\t\tSo luong may trong phong: " << n << endl;
	x.xuat();
	
	cout<<"\n\tBang may: " << endl;
	cout<<"\n\t" << setw(15) << "Ma may"
		<< setw(15) << "Kieu may" 
		<<setw(15) << "Tinh trang" << endl;
		
	for(int i = 0; i < n; i++)
	{
		y[i].xuat();
	}
}

void 

PhongMay::~PhongMay() {
	delete[] y;
}

int main()
{
	PhongMay p;
	p.nhap();
	p.xuat();
	return 0;
}

/*
P01
CNTT
16
QL01
Nguyen Thi Lan
4
a101
MAY CASE
Tot
a102
MAY LAPTOP
Kha
a103
MAY CASE
Kha
a104
MAY LAPTOP
Tot
a105
MAY ASUS
Kha
*/
