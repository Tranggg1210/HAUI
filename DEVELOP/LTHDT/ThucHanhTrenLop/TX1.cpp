#include<bits/stdc++.h>
using namespace std;

class Phieu;

class NCC {
	private:
		char mancc[10];
		char tenncc[20];
		char diachi[40];
	public:
		void nhap();
		void xuat();
};

class Hang {
	private:
		char tenhang[20];
		float dongia;
		int soluong;
	public:
		void nhap();
		void xuat();
	friend float tongtien(Phieu &p);
};

class Phieu {
	private:
		char maphieu[10];
		char ngaylap[15];
		NCC a;
		int n; // so luong san pham
		Hang *h;
	public:
		void nhap();
		void xuat();
		~Phieu();
	friend float tongtien(Phieu &p);
};


void NCC::nhap() {
	cout<<"\nNhap ma nha cc: ";					fflush(stdin);			gets(mancc);
	cout<<"\nNhap ten nha cc: ";				fflush(stdin);			gets(tenncc);
	cout<<"\nNhap dia chi nha cc: ";			fflush(stdin);			gets(diachi);
}

void NCC::xuat() {
	cout<<"\n\tMa NCC: " << mancc << "\t\tTen NCC" << tenncc;
	cout<<"\n\tDia chi: " << diachi;
}

void Hang::nhap() {
	cout<<"\nNhap ten hang: ";					fflush(stdin);			gets(tenhang);
	cout<<"\nNhap don gia: ";											cin>>dongia;
	cout<<"\nNhap so luong: ";											cin>>soluong;
}

void Hang::xuat() {
	cout<< setw(16) << tenhang 
		<< setw(15) << dongia
		<< setw(15) << soluong
		<< setw(15) << dongia*soluong << endl;
}

void Phieu::nhap() {
	cout<<"\n========== NHAP THONG TIN CUA PHIEU NHAP HANG ==========" << endl;
	cout<<"\nNhap ma phieu: ";					fflush(stdin);			gets(maphieu);
	cout<<"\nNhap ngay lap: ";					fflush(stdin);			gets(ngaylap);
	
	a.nhap();
	
	do{
		cout<<"\nNhap so luong mat hang trong phieu n > 0: ";			cin>>n;
	}while(n < 1);
	
	h = new Hang[n];
	
		for(int i = 0; i < n; i++)
		{
			cout<<"\n==== NHAP THONG TIN HANG THU " << i <<" ===="<< endl;
			h[i].nhap();
		}
	
}


void Phieu::xuat() {
	cout<<"\n\n\t==================== PHIEU NHAP HANG ====================" << endl;
	cout<<"\n\tMa phieu: " << maphieu << "\t\tNgay lap: " << ngaylap;
	a.xuat();
	cout<<endl;
	cout<< setw(16) << "Ten hang" 
		<< setw(15) << "Don gia"
		<< setw(15) << "So luong"
		<< setw(15) << "Thanh tien" << endl;

		for(int i = 0; i < n; i++)
			h[i].xuat();
}

Phieu::~Phieu() {
	delete[] h;
	cout<<"\n\nBo nho da duoc giai phong";
}

float tongtien(Phieu &p)
{
	float sum = 0;
	for(int i = 0; i < p.n; i++)
		sum += (p.h[i].dongia * p.h[i].soluong);
	return sum;
}


int main()
{
	Phieu p;
	p.nhap();
	p.xuat();
	cout<<setw(46) << "Cong thanh tien" << setw(15) << tongtien(p); 
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
