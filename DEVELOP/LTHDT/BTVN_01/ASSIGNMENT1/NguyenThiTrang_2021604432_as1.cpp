#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class Phieu;
class NCC {
	private:
		char mancc[10];
		char tenncc[50];
		char diachi[50];
		char sdt[20];
	public:
		void nhap();
		void xuat();
};

class SP {
	private: 
		char masp[10];
		char tensp[40];
		int soluong;
		float dongia;
	public: 
		void nhap();
		void xuat();
	friend class Phieu;
	friend int checkSP(Phieu p);
	friend void sapxep(Phieu &p);
};

class Phieu {
	private:
		char maphieu[10];
		char ngaylap[10];
		int n; // so luong san pham can nhap
		SP sp1[50];
		NCC ncc1;
	public:
		void nhap();
		void xuat();
	friend int checkSP(Phieu p);
	friend void sapxep(Phieu &p);
};

void NCC::nhap() {
	cout<<"\nNhap ma ncc: ";			fflush(stdin);		gets(mancc);
	cout<<"\nNhap ten ncc: ";			fflush(stdin);		gets(tenncc);
	cout<<"\nNhap dia chi ncc: ";		fflush(stdin);		gets(diachi);
	cout<<"\nNhap so dien thoai ncc: ";	fflush(stdin);		gets(sdt);
}

void NCC::xuat(){
	cout<<"\n\t Ma nha cung cap: "<< mancc  << "\t\t\t\t Ten nha cung cap: " << tenncc
		<< endl;
	cout<<"\n\t Dia chi: "<< diachi << "\t\t\t SDT: " << sdt << endl;
}

void SP::nhap(){
	cout<<"\nNhap ma san pham: ";		fflush(stdin);		gets(masp);
	cout<<"\nNhap ten san pham: ";		fflush(stdin);		gets(tensp);
	cout<<"\nNhap so luong san pham: ";						cin>>soluong;
	cout<<"\nNhap don gia san pham: ";						cin>>dongia;
}

void SP::xuat(){
	cout<<setw(15)<< masp
		<<setw(15)<< tensp
		<<setw(15)<< soluong
		<<setw(15)<< dongia
		<<setw(15)<< soluong*dongia <<endl;
}

void Phieu::nhap(){
	cout<<"\nNhap ma phieu: ";			fflush(stdin);		gets(maphieu);
	cout<<"\nNhap ngay lap phieu: ";	fflush(stdin);		gets(ngaylap);
	ncc1.nhap();
	cout<<"\nNhap so luong san pham can nhap: ";			cin>>n;
		for(int i = 0; i < n; i++){
			sp1[i].nhap();
		}
}

void Phieu::xuat(){
	cout<<"\n\t Ma phieu: "<< maphieu << "\t\t\t\t Ngay lap: "<< ngaylap << endl;
	ncc1.xuat();
	cout<<endl;
	cout<<setw(15)<< "Ma SP"
		<<setw(15)<< "Ten san pham"
		<<setw(15)<< "So luong"
		<<setw(15)<< "Don gia"
		<<setw(15)<< "Thanh tien" <<endl;
		for(int i = 0; i < n; i++) 
			sp1[i].xuat();
	float sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += (sp1[i].dongia * sp1[i].soluong);
	}
	cout<< setw(16) <<"Tong: "<< setw(59) << sum;

}

int checkSP( Phieu p)
{
	int count = 0;
	for(int i = 0; i < p.n; i++)
	{
		if(p.sp1[i].soluong < 80) count++;
	}
	return count;
}

void sapxep(Phieu &p)
{
	for(int i = 0; i < p.n - 1; i++)
	{
		for(int j = i + 1 ; j < p.n; j++)
		{
			if(p.sp1[i].dongia > p.sp1[j].dongia)
			{
				SP tg = p.sp1[i];
				p.sp1[i] = p.sp1[j];
				p.sp1[j] = tg;
			}
		}
	}
}

int main()
{
	Phieu p;
	p.nhap();
	cout<<"\n\t=================== PHIEU NHAP VAN PHONG PHAM ================" << endl;
	p.xuat();
	cout<<"\n\nSo luong san pham nho hon 80 la: " << checkSP(p);
	cout<<"\n\n";
	sapxep(p);
	cout<<"\n\t=================== PHIEU NHAP VAN PHONG PHAM SAU KHI SAP XEP TANG DAN THEO DON GIA ================" << endl;
	p.xuat();
	return 0;
}

/*
PH001
4/6/2018
NCC01
Cong ty Van Phu
Quan Ha Dong, Ha Noi
091212xxxx
3
SP01
Giay in A4
100
70
SP02
But da bang
50
10
SP03
Tui clear
60
5
*/
