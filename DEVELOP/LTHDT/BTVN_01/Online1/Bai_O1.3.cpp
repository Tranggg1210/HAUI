#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;

class Phieu;

class NV {
	private:
		char tennv[40];
		char chucvu[30];
	public:
		void nhap();
		void xuat();
};

class Phong {
	private:
		char tenphong[40];
		char maphong[10];
		char tentruongphong[40];
	public:
		void nhap();
		void xuat();
};

class SP{
	private:
		char tensp[40];
		int soluong;
		char tinhtrang[50];
	public:
		void nhap();
		void xuat();
	friend class Phieu;
	friend void update(Phieu &p1);
	friend void arrange(Phieu &p1);
};

class Phieu {
	private:
		char maphieu[10];
		char ngaykiemke[10];
		int n; // so luong san pham
		SP sp[50];
		NV nv;
		Phong p;
	public:
		void nhap();
		void xuat();
	friend void update(Phieu &p1);
	friend void arrange(Phieu &p1);
};

void NV::nhap() {
	cout<<"\nNhap ten nhan vien kiem ke: ";			fflush(stdin);			gets(tennv);
	cout<<"\nNhap chuc vu cua nhan vien: ";			fflush(stdin);			gets(chucvu);
}

void NV::xuat(){
	cout<<"\n\tNhan vien kiem ke: " << tennv << "\t\tChuc vu: " << chucvu << endl;
}

void Phong::nhap(){
	cout<<"\nNhap ten phong kiem ke: ";				fflush(stdin);			gets(tenphong);
	cout<<"\nNhap ma phong: ";						fflush(stdin);			gets(maphong);
	cout<<"\nNhap ten truong phong: ";				fflush(stdin);			gets(tentruongphong);
}

void Phong::xuat(){
	cout<<"\n\tKiem ke tai phong: " << tenphong << "\t\tMa phong: " << maphong << endl;
	cout<<"\n\tTruong phong: " << tentruongphong << endl; 
}

void SP::nhap(){
	cout<<"\nNhap ten tai san: ";					fflush(stdin);			gets(tensp);
	cout<<"\nNhap so luong san pham: ";										cin>>soluong;
	cout<<"\nNhap tinh trang cua tai san: ";		fflush(stdin);			gets(tinhtrang);
}

void SP::xuat(){
	cout<<"\t"<< setw(15) << tensp
		<< setw(15) << soluong
		<< setw(25) << tinhtrang << endl;
}

void Phieu::nhap(){
	cout<<"\nNhap ma phieu: ";						fflush(stdin);			gets(maphieu);
	cout<<"\nNhap ngay kiem ke: ";					fflush(stdin);			gets(ngaykiemke);
	nv.nhap();
	p.nhap();
	cout<<"\nNhap so tai san can kiem ke: ";								cin>>n;
		for(int i = 0; i < n; i++)
			sp[i].nhap();
}

void Phieu::xuat(){
	cout<<"\n\tMa phieu: " << maphieu << "\t\t\t\t\tNgay kiem ke: " << ngaykiemke << endl;
	nv.xuat();
	p.xuat();
	cout<<endl;
	cout<<"\t" << setw(15) << "Ten tai san"
		<< setw(15) << "So luong"
		<< setw(25) << "Tinh trang" << endl;
		for(int i = 0; i < n; i++)
			sp[i].xuat();
	cout<<endl;
	int sum = 0;
	for(int i = 0; i < n; i++) sum += sp[i].soluong;
	cout<<"\tSo tai san da kiem ke: " << n << "\tTong so luong: " << sum;
}

void update(Phieu &p1)
{
	bool check = false;
	for(int i = 0; i < p1.n; i++)
	{
		if(strcmp(p1.sp[i].tensp, "May vi tinh") == 0)
		{
			p1.sp[i].soluong = 20;
			check = true;
		}
	}
	if(check == false) 
		cout<< "\n\nTrong danh sach tai san khong cos tai san nao co ten la: \"May vi tinh\" " << endl;
	else cout<<"\n\n\t===================== PHIEU KIEM KE TAI SAN  SAU KHI SUA DOI===================" << endl;
}

void arrange(Phieu &p1)
{
	for(int i = 0; i < p1.n - 1; i++)
	{
		for(int j = i + 1; j < p1.n; j++)
		{
			if(p1.sp[i].soluong > p1.sp[j].soluong){
				SP tg = p1.sp[i];
				p1.sp[i] = p1.sp[j];
				p1.sp[j] = tg;
			}
		}
	}
}

int main()
{
	Phieu p1;
	p1.nhap();
	cout<<"\n\t===================== PHIEU KIEM KE TAI SAN ===================" << endl;
	p1.xuat();
	update(p1);
	p1.xuat();
	cout<<"\n\n\t===================== PHIEU KIEM KE TAI SAN SAU KHI SAP XEP TANG DAN THEO SO LUONG"
	    <<" ===================" << endl;
	arrange(p1);
	p1.xuat();
	return 0;
}

/*
PH01
1/1/2007
Kieu Thi Thanh
Ke toan vien
To chuc hanh chinh
PTC
Hoang Bich Hao
3
May vi tinh
5
Tot
May vi tinh
3
Het khau hao - hong
Ban lam viec
6
Tot
*/
