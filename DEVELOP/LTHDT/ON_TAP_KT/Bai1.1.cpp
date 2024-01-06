#include<bits/stdc++.h>
using namespace std;

class SV {
	private:
		char masv[15];
		char hoten[40];
		int tuoi;
		float diem;
	public:
		void nhap();
		void xuat();
};

void SV::nhap()
{
	cout<<"\n==== NHAP THONG TIN SINH VIEN ====="<< endl;
	cout<<"\nNhap ma sinh vien: ";				fflush(stdin);			gets(masv);
	cout<<"\nNhap ho ten sinh vien: ";			fflush(stdin);			gets(hoten);
	cout<<"\nNhap tuoi cua sinh vien: ";								cin>>tuoi;
	cout<<"\nNhap diem cua sinh vien: ";								cin>>diem;
}

void SV::xuat() {
	cout<<"\n==== THONG TIN CUA SINH VIEN ====" << endl;
	cout<<"\nMa sinh vien: " << masv;
	cout<<"\nHo ten: " << hoten;
	cout<<"\nTuoi: " << tuoi;
	cout<<"\nDiem: " << diem;
}

main()
{
	SV a;
	a.nhap();
	a.xuat();
}
