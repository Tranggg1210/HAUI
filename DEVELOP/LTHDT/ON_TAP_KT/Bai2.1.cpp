#include<bits/stdc++.h>
using namespace std;

class DATE {
	private:
		int d,m,y;
	public:
		void nhap();
		void xuat();
};

class NHANSU{
	private:
		char mans[20];
		char hoten[40];
		DATE ns;
	public:
		void nhap();
		void xuat();
};

void DATE::nhap()
{
	cout<<"\nNhap ngay, thang, nam sinh: ";						cin>>d>>m>>y;
}

void DATE::xuat()
{
	cout<<"\nNgay sinh: " << d << "/" << m << "/" << y;
}

void NHANSU::nhap() {
	cout<<"\n==== NHAP THONG TIN NHAN SU ====" << endl;
	cout<<"\nNhap ma nhan su: ";				fflush(stdin);	gets(mans);
	cout<<"\nNhap ho ten nhan su: ";			fflush(stdin);	gets(hoten);
	ns.nhap();
}

void NHANSU::xuat()
{
	cout<<"\n==== XUAT THONG TIN NHAN SU ==== "<< endl;
	cout<<"\nMa nhan su: " << mans;
	cout<<"\nHo ten: "<< hoten;
	ns.xuat();
}

main()
{
	NHANSU a;
	a.nhap();
	a.xuat();
}
