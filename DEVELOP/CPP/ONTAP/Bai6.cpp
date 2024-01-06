#include<iostream>
#include<iomanip>
using namespace std;

struct BANGDIEM{
	char tenmon[100];
	int sotc;
	float diem;
};

struct PHIEU_BD{
	char msv[50];
	char hoten[50];
	char lop[30];
	int khoa;
	BANGDIEM bd[100];
	int n;
};

void nhap(PHIEU_BD &pd)
{
	fflush(stdin);
	cout<<"\nNhap msv: ";
	gets(pd.msv);
	fflush(stdin);
	cout<<"\nNhap ho ten sinh vien: ";
	gets(pd.hoten);
	fflush(stdin);
	cout<<"\nNhap lop cua sinh vien: ";
	gets(pd.lop);
	cout<<"\nNhap khoa cua sinh vien: ";
	cin>>pd.khoa;
	do{
		cout<<"\nNhap so mon sinh vien da thi: ";
	    cin>>pd.n;
	}while(pd.n <= 0);
	for(int i = 0; i < pd.n; i++)
	{
		cout<< endl<<endl;
		cout<<"NHAP DIEM CUA MON HOC THU " << i + 1 << endl;
		fflush(stdin);
		cout<< "\nTen mon: ";
		gets(pd.bd[i].tenmon);
		cout<< "\nSo trinh : ";
		cin >> pd.bd[i].sotc;
		do{
			cout<< "\nDiem: ";
		    cin >> pd.bd[i].diem;
		}while(pd.bd[i].diem < 0 || pd.bd[i].diem > 10);
	}
}

void xuat(PHIEU_BD pd)
{
	float s = 0;
	cout<< "PHIEU BAO DIEM" << endl;
	cout<<"Ma sinh vien: " << pd.msv << setw(40) << "Ten sinh vien: " << pd.hoten << endl;
	cout<<"Lop: " << pd.msv << setw(40) << "Khoa: " << pd.khoa << endl;
	cout<< "\nBang diem:" << endl;
	cout<< setw(40) << "Ten mon" << setw(20) << "So trinh" << setw(40) << "Diem" << endl;
	for(int i = 0; i < pd.n; i++)
	{
		s += pd.bd[i].diem;
		cout<< setw(40) << pd.bd[i].tenmon << setw(20) << pd.bd[i].sotc << setw(40) << pd.bd[i].diem << endl;
	}
	cout<< "Diem trung binh" <<  fixed << setprecision(1) << s / pd.n;
}   


int main()
{
	PHIEU_BD pd;
	nhap(pd);
	xuat(pd);
	return 0;
}
