#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;



class NCC {
	private:
		char mancc[10];
		char tenncc[40];
		char diachi[50];
	public:
		void nhap();
		void xuat();
};

class SP {
	private:
		char tenhang[40];
		float dongia;
		int soluong;
	public:
		void nhap();
		void xuat();
	friend class Phieu;
};

class Phieu {
	private:
		char maphieu[10];
		char ngaylap[10];
		int n; // so luong san pham
		SP h[50];
		NCC ncc;
	public:
		void nhap();
		void xuat();
};

void NCC::nhap(){
	cout<<"\nNhap ma nha cung cap: ";			fflush(stdin);			gets(mancc);
	cout<<"\nNhap ten nha cung cap: ";			fflush(stdin);			gets(tenncc);
	cout<<"\nNhap dia chi nha cung cap: ";		fflush(stdin);			gets(diachi);
}

void NCC::xuat(){
	cout<<"\n\tMa NCC: " << mancc << "\t\t\tTen NCC: " << tenncc << endl;
	cout<<"\n\tDia chi: " << diachi << endl;
	
}

void SP::nhap(){
	cout<<"\nNhap ten san pham: ";				fflush(stdin);			gets(tenhang);
	cout<<"\nNhap don gia san pham: ";									cin >> dongia;
	cout<<"\nNhap so luong san pham: ";									cin >> soluong;
}

void SP::xuat(){
	cout<< setw(16) << tenhang
		<< setw(15) << dongia
		<< setw(15) << soluong
		<< setw(15) << soluong * dongia << endl;
}

void Phieu::nhap(){
	cout<<"\nNhap ma phieu: ";					fflush(stdin);			gets(maphieu);
	cout<<"\nNhap ngay lap phieu: ";			fflush(stdin);			gets(ngaylap);
	ncc.nhap();
	cout<<"\nNhap so luong hang: ";										cin >> n;
		for(int i = 0; i < n; i++)
			h[i].nhap();
}

void Phieu::xuat(){
	cout<<"\n\tMa phieu: " << maphieu << "\t\t\tNgay lap: " << ngaylap << endl;
	
	ncc.xuat();
	
	cout<<endl;
	cout<<"\t" <<"Ten hang" << setw(15)
		<<"Don gia" << setw(15)
		<<"So luong" << setw(15)
		<<"Thanh tien" << endl;
		
		for(int i = 0; i < n; i++)
			h[i].xuat();
			
	// Tinh tong tien
	float sum = 0;
	for(int i = 0; i < n; i++) sum += (h[i].soluong *  h[i].dongia);
	cout<<"\tCong thanh tien: " << setw(36) << sum;
	
}

int main()
{
	Phieu p;
	p.nhap();
	cout<<"\n\t================ PHIEU NHAP HANG ==================" << endl;
	p.xuat();
	return 0;
}

/*
PH001
1/1/2007
NCC1
LG-Electronic
Khu cong nghiep Nhu Quynh A
3
TiVi
30
2
Quat
1.2
3
Mobi
5
10
*/

