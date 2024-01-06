#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class Phieu;

class SV {
	private:
		char masv[10];
		char tensv[40];
		char lop[15];
		int khoa;
	public:
		void nhap();
		void xuat();
};

class MON {
	private:
		char tenmon[50];
		int sotrinh;
		float diem;
	public:
		void nhap();
		void xuat();
	friend class Phieu;
	friend void checkMON(Phieu p);
	friend void insert(Phieu &p);
};

class Phieu {
	private:
		int n; //So mon can nhap
		SV sv;
		MON m[50];
	public:
		void nhap();
		void xuat();
	friend void checkMON(Phieu p);
	friend void insert(Phieu &p);
};

void SV::nhap(){
	cout<<"\nNhap ma sinh vien: ";				fflush(stdin);			gets(masv);
	cout<<"\nNhap ten sinh vien: ";				fflush(stdin);			gets(tensv);
	cout<<"\nNhap lop sinh vien dang hoc: ";	fflush(stdin);			gets(lop);
	cout<<"\nNhap khoa cua sinh vien: ";								cin >> khoa;
}

void SV::xuat(){
	cout<<"\n\tMa sinh vien: " << masv << "\t\t\tTen sinh vien: " << tensv << endl; 
	cout<<"\n\tLop: " << lop << "\t\t\t\tKhoa: " << khoa << endl; 
}

void MON::nhap(){
	cout<<"\nNhap ten mon: ";					fflush(stdin);			gets(tenmon);
	cout<<"\nNhap so trinh: ";											cin>>sotrinh;
	do{
		cout<<"\nNhap diem: ";											cin >> diem;
	}while( diem < 0 || diem > 10);
}

void MON::xuat(){
	cout<< setw(15) << tenmon
		<< setw(15)	<< sotrinh
		<< setw(15) << diem << endl;
}

void Phieu::nhap(){
	sv.nhap();
	
	do{
		cout<<"\nNhap so mon cua sinh vien: ";							cin >> n;
	}while( n <= 0);
	
		for(int i = 0; i < n; i++)
			m[i].nhap();
			
}

void Phieu::xuat()
{
	sv.xuat();
	
	cout<<"\tBang diem: " << endl;
	cout<<"\t" << "Ten mon" << setw(15)
		<<"So trinh" << setw(15)
		<<"Diem" << endl;
		for(int i = 0; i < n; i++)
			m[i].xuat();
			
	float avg = 0, sumts = 0, summs = 0;
	for(int i = 0; i < n; i++)
	{
		sumts += (m[i].sotrinh * m[i].diem);
		summs += m[i].sotrinh;
	}
	if(summs == 0) avg = 0;
	else avg = sumts / summs;
	cout<<"\tDiem trung binh: " << setw(20) << fixed << setprecision(2) << avg;
}

void checkMON(Phieu p)
{
	int count = 0;
	for(int i = 0; i < p.n; i++)
	{
		if(p.m[i].sotrinh > 3) count++;
	}
	if(count == 0) cout<<"\n\nKhong co mon hoc nao co so trinh lon hon 3 \n" << endl;
	else {
		cout<<"\n\nCo " << count << " mon co so trinh lon hon 3, do la cac mon: " ;
		for(int i = 0; i < p.n; i++){
			if(p.m[i].sotrinh > 3) cout<< p.m[i].tenmon << "\t";
		}
	}
}

void insert(Phieu &p)
{
	int k; // vi tri can chen
	do{
		cout<<"\nNhap vi tri mon hoc can chen: ";						cin>>k;
	}while(k < 0 || k >= p.n);
	MON tg;
	tg.nhap();
	for(int i = p.n; i >= k; i--) 	
		p.m[i] = p.m[i - 1];
	p.n++;
	p.m[k] = tg;
}

int main()
{
	Phieu p;
	p.nhap();
	cout<<"\n\t======================= PHIEU BAO DIEM =====================" << endl;
	p.xuat();
	checkMON(p);
	insert(p);
	cout<<"\n\t======================= PHIEU BAO DIEM SAU KHI CHEN =====================" << endl;
	p.xuat();
	return 0;
}

/*
SV001
Nguyen Hai Ha
CNTT1
10
3
Co so du lieu
4
8
Lap trinh HDT
3
7
He dieu hanh
5
9
*/
