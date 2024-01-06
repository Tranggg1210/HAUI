#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

class hang {
	private:
		char mahang[20];				
		char tenhang[40];
		float dongia;
	public:
		void nhap();
		void xuat();
};

class phieu {
	private:
		char maphieu[20];
		int n;					// so luong mat hang trong phieu
		hang x[100];
	public:
		void nhap();
		void xuat();
};

void hang::nhap() {
	cout<<"\nNhap ma hang: ";				fflush(stdin);				gets(mahang);
	cout<<"\nNhap ten hang: ";				fflush(stdin);				gets(tenhang);
	cout<<"\nNhap don gia: ";											cin>>dongia;
}

void hang::xuat() {
	cout<<"\n\t" << setw(15) << mahang
		<< setw(15) << tenhang
		<< setw(15) << dongia << endl;
}

void phieu::nhap() {
	cout<<"\n==================== NHAP THONG TIN PHIEU ====================" << endl;
	
	cout<<"\nNhap ma phieu: ";				fflush(stdin);				gets(maphieu);
	
	do{
		cout<<"\nNhap so luong mat hang trong phieu n: ";				cin >> n;
	}while(n < 1);
	
	for(int i = 0; i < n; i++) 
	{
		cout<< endl;
		cout<<"\n==== NHAP THONG TIN SAN PHAM THU " << i + 1 << " ====" << endl;
		x[i].nhap();
	}
	
}

void phieu::xuat() {
	cout<<endl;
	cout<<"\n\t==================== PHIEU XUAT ====================" << endl;
	cout<<"\n\tMa phieu: " << maphieu << endl;
	
	cout<<"\n\tBang hang: " << endl;
	cout<<"\n\t" << setw(15) << "Ma hang" 
		<<setw(15) << "Ten hang"
		<<setw(15) << "Don gia" << endl;
		
	for(int i = 0; i < n; i++)
	{
		x[i].xuat();
	} 
}

int main()
{
	phieu a;
	a.nhap();
	a.xuat();
	return 0;
}
