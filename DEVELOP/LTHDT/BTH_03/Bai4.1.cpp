#include<iostream>
#include<stdio.h>
using namespace std;

class person {
	protected:
		char hoten[40];
		char ngaysinh[20];
		char quequan[40];
};

class kysu:public person {
	private:
		char nganh[50];
		int namtn;
	public:
		void nhap();
		void xuat();
};

void kysu::nhap() {
	cout<< "\nNhap ho ten cua ky su: ";			fflush(stdin);			gets(hoten);
	cout<<"\nNhap ngay sinh cua ky su: ";		fflush(stdin);			gets(ngaysinh);
	cout<<"\nNhap que quan cua ky su: ";		fflush(stdin);			gets(quequan);
	cout<<"\nNhap ten nganh ma ky su da hoc: ";	fflush(stdin);			gets(nganh);
	cout<<"\nNhap nam tot nghiep cua ky su: ";							cin>>namtn;
}

void kysu::xuat()
{
	cout<<"\n==================== THONG TIN CUA KY SU ================" << endl;
	cout<<"Ho ten: " << hoten << endl;
	cout<<"Ngay sinh: " << ngaysinh << endl;
	cout<<"Que quan: " << quequan << endl;
	cout<<"Nganh: " << nganh << endl;
	cout<<"Nam tot nghiep: " << namtn << endl;
}

int main()
{
	kysu ks;
	ks.nhap();
	ks.xuat();
	return 0;
}
