#include<iostream>
#include<stdio.h>
using namespace std;

class NSX {
	private:
		char mansx[20];  			// ma NSX
		char tennsx[40]; 			// ten NSX
		char dcnsx[40];  			// dia chi NSX
	public:
		void nhap();
		void xuat();
};

class HANG {
	private:
		char mahang[20];			 
		char tenhang[40];			 
		NSX x;
	public:
		void nhap();
		void xuat(); 
};

void NSX::nhap() {
	cout<<"\nNhap ma nha san xuat: ";			fflush(stdin);				gets(mansx);
	cout<<"\nNhap ten nha san suat: ";			fflush(stdin);				gets(tennsx);
	cout<<"\nNhap dia chi nha san xuat: ";		fflush(stdin);				gets(dcnsx);
}

void NSX::xuat() {
	cout<<"Ma nha san xuat: " << mansx << endl;
	cout<<"Ten nha san xuat: " << tennsx << endl;
	cout<<"Dia chi nha san xuat: " << dcnsx << endl;
}

void HANG::nhap() {
	cout<<"\n================== NHAP THONG TIN MAT HANG ==================" << endl;
	cout<<"\nNhap ma hang: 	";					fflush(stdin);				gets(mahang);
	cout<<"\nNhap ten hang: ";					fflush(stdin);				gets(tenhang);
	x.nhap();
}

void HANG::xuat() {
	cout<<"\n================== THONG TIN MAT HANG ==================" << endl;
	cout<<"Ma hang: " << mahang << endl;
	cout<<"Ten hang: "<< tenhang << endl;
	x.xuat();
}

int main()
{
	HANG a;
	a.nhap();
	a.xuat();
	return 0;
}
