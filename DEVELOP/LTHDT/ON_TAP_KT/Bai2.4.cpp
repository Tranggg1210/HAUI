#include<bits/stdc++.h>
using namespace std;

class MAY {
	private:
		char mamay[20];
		char kieumay[40];
		char tinhtrang[40];
	public:
		void nhap();
		void xuat();
};

class QUANLY {
	private:
		char maql[20];
		char hoten[40];
	public:
		void nhap();
		void xuat();
};

class PHONGMAY {
	private:
		char maphong[20];
		char tenphong[40];
		float dientich;
		QUANLY x;
		int n;			// so luong may cua phong
		MAY *y;
	public:
		void nhap();
		void xuat();
};

void MAY::nhap(){
	cout<<"\nNhap ma may: ";				fflush(stdin);			gets(mamay);
	cout<<"\nNhap kieu may: ";				fflush(stdin);			gets(kieumay);
	cout<<"\nNhap tinh trang: ";			fflush(stdin);			gets(tinhtrang);
}

void MAY::xuat() {
	cout<<"\n" << setw(15) <<  mamay
		<<setw(15) << kieumay
		<<setw(20) << tinhtrang ;
}

void QUANLY::nhap() {
	cout<<"\nNhap ma quan ly: ";			fflush(stdin);			gets(maql);
	cout<<"\nNhap ho ten: ";				fflush(stdin);			gets(hoten);
}

void QUANLY::xuat() {
	cout<<"\n\tMa quan ly: " << maql << "\t\tHo ten quan ly: " << hoten;
}

void PHONGMAY::nhap() {
	cout<<"\n========== NHAP THONG TIN PHONG MAY =========" <<endl;
	cout<<"\nNhap ma phong: ";				fflush(stdin);			gets(maphong);
	cout<<"\nNhap ten phong: ";				fflush(stdin);			gets(tenphong);
	cout<<"\nNhap dien tich phong: ";								cin>>dientich;
	
	x.nhap();
	
	do{
		cout<<"\nNhap so luong may cua phong n > 0: ";				cin>>n;
	}while(n < 1);
	y = new MAY[n];
		for(int i = 0; i < n; i++)
		{
			cout<<"\n==== NHAP THONG TIN MAY THU " << i + 1 << " ====" << endl;
			y[i].nhap();
		}
}

void PHONGMAY::xuat() {
	cout<<"\n\t\t=========== THONG TIN PHONG MAY ==========" << endl;
	cout<<"\n\tMa phong: " << maphong << "\t\t\tTen phong: " << tenphong;
	cout<<"\n\tDien tich phong: " << dientich << "\t\tSo luong may trong phong: " << n;
	x.xuat();
	
	cout<<"\n" << setw(15) << "Ma may"
		<<setw(15) << "Kieu may"
		<<setw(20) << "Tinh trang may";
	for(int i = 0; i < n; i++)
	{
		y[i].xuat();
	}
}

main()
{
	PHONGMAY a;
	a.nhap();
	a.xuat();
}

/*
*/
