#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class DATE{
	private:
		int d;
		int m;
		int y;
	public:
		void nhap();
		void xuat();
	friend class TIVI;
};

class NSX {
	private:
		char tennsx[50];
		char diachi[50];
	public:
		void nhap();
		void xuat();
};

class HANG {
	protected:
		char tenhang[50];
		NSX x;
		float dongia;
	public:
		void nhap();
		void xuat();
		HANG();
};

class TIVI: public HANG{
	private:
		int kichthuoc;
		DATE NgayNhap;
	public:
		void nhap();
		void xuat();
		TIVI();
};


void DATE::nhap() {
	do{
		cout<<"\nNhap ngay nhap: ";												cin >> d;
	}while(d < 1 || d > 31);
	
	do{
		cout<<"\nNhap thang nhap: ";											cin >> m;
	}while(m < 1 || m > 12);
	
	do{
		cout<<"\nNhap nam nhap: ";												cin >> y;
	}while(y <= 0);
}

void DATE::xuat(){
	cout<<"Ngay nhap: " << d << "/" << m << "/" << y << endl; 
}

void NSX::nhap()
{
	cout<<"\nNhap ten nsx: ";						fflush(stdin);				gets(tennsx);
	cout<<"\nNhap dia chi nsx: ";					fflush(stdin);				gets(diachi);
}

void NSX::xuat(){
	cout<<"Ten NSX: " << tennsx << endl;
	cout<<"Dia chi: " << diachi << endl;
}

void HANG::nhap() {
	cout<< "\nNhap ten hang: ";						fflush(stdin);				gets(tenhang);
	x.nhap();
	cout<<"\nNhap don gia: ";													cin >> dongia;
}

void HANG::xuat(){
	cout<<"Ten hang: " << tenhang << endl;
	x.xuat();
	cout<<"Don gia: " << dongia << endl;
}

HANG::HANG(){
	dongia = 0;
}

void TIVI::nhap(){
	cout<<"\n================ NHAP THONG TIN CUA TIVI ================" << endl;
	HANG::nhap();
	cout<< "\nNhap kich thuoc: ";												cin >> kichthuoc;
	NgayNhap.nhap();
}

void TIVI::xuat()
{
	cout<<"\n================ THONG TIN CUA TIVI ================" << endl;
	HANG::xuat();
	cout<<"Kich thuoc: " << kichthuoc << endl;
	NgayNhap.xuat();
}

TIVI::TIVI() {
	kichthuoc = 0;
	NgayNhap.d = 1;
	NgayNhap.y = 1;
	NgayNhap.m = 1;
}

int main()
{
	TIVI t;
	t.nhap();
	t.xuat();
	return 0;
}
