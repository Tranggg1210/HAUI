#include<iostream>
#include<stdio.h>
using namespace std;

class nguoi {
	protected:
		char hoten[40];
		int tuoi;
	public:
		void nhap();
		void xuat();
};

class BenhVien {
	private:
		char tenbv[40];
		char diachi[40];
		nguoi gd;					// giam doc
	friend class BenhNhan;
};

class BenhNhan: public nguoi {
	private:
		char mabn[20];
		char tiensu[40];
		char chuandoan[40];
		BenhVien bv;
	public:
		void nhap();
		void xuat();
	friend void nhapdsBN(BenhNhan *ds, int &n);
};

void nguoi::nhap() {
	cout<<"\nNhap ho ten: ";							fflush(stdin);							gets(hoten);
	cout<<"\nNhap tuoi: ";																		cin >> tuoi;
}

void nguoi::xuat() {
	cout<<"\n\tHo ten: " << hoten << "\t\t\tTuoi: " << tuoi;
}

void BenhNhan::nhap() {
	cout<<"\nNhap ma benh nhan: ";						fflush(stdin);							gets(mabn);
	nguoi::nhap();
	cout<<"\nNhap tien su benh nhan: ";					fflush(stdin);							gets(tiensu);
	cout<<"\nNhap chuan doan cua benh nhan: ";			fflush(stdin);							gets(chuandoan);
	cout<<"\nNhap ten benh vien: ";						fflush(stdin);							gets(bv.tenbv);
	cout<<"\nNhap dia chi benh vien: ";					fflush(stdin);							gets(bv.diachi);
	cout<<"\n----Nhap thong tin giam doc " << endl;
	bv.gd.nhap();
}

void nhapdsBN(BenhNhan *ds, int &n)
{
	cout<<"\n================== NHAP THONG TIN CAC BENH NHAN ==================" << endl;
	do{
		cout<<"\nNhap so luong benh nhan: ";													cin>>n;
	}while(n < 1);
	
	ds = new BenhNhan[n];
	for(int i = 0; i < n; i++)
	{
		cout<<endl;
		cout<<"\n==== NHAP THONG TIN BENH NHAN THU " << i+1 << " ====" << endl;
		ds[i].nhap();
	}
}

int main()
{
	int n;					//So luong benh nhan cua benh vien
	BenhNhan *ds;
	nhapdsBN(ds,n);
	delete[] ds;
	return 0;
}


