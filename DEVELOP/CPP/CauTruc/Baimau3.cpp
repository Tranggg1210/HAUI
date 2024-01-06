#include<iostream>
#include<string.h>
using namespace std;

struct NGAYTHANG{
	int ngay;
	int thang;
	int nam;
};

struct SINHVIEN
{
	char masv[12];
	char hoten[40];
	NGAYTHANG nt;
	char gt[5];
	char hokhau[20];
	float diem;
	
};

void nhap(SINHVIEN &sv)
{
	fflush(stdin);
	cout<<"Nhap ma sinh vien cua sinh vien: ";
	gets(sv.masv);
	cout<<endl;
	fflush(stdin);
	cout<<"Nhap ten sinh vien: ";
	gets(sv.hoten);
	cout<<endl;
	cout<<"Nhap ngay, thang, nam sinh cua sinh vien: ";
	cout<<"\n\t\tNgay: "; cin >> sv.nt.ngay;
	cout<<"\n\t\tThang: "; cin >> sv.nt.thang;
	cout<<"\n\t\tNam: "; cin >> sv.nt.nam;
	fflush(stdin);
	cout<<endl;
	cout<<"Nhap gioi tinh cua sinh vien: ";
	gets(sv.gt);
	fflush(stdin);
	cout<<endl;
	cout<<"Nhap ho khau cua sinh vien: ";
	gets(sv.hokhau);
	cout<<endl;
	cout<<"Nhap diem tot nghiep cua sinh vien: ";
	cin>>sv.diem;
}

void danhsachsv(SINHVIEN sv[], int &n)
{
	do{
		cout<<"Nhap so sinh vien 3 <= n <= 100: ";
		cin>>n;
	}while(n < 3 || n > 100);
	for(int i = 0; i < n; i++)
	{
		cout<<"-------Nhap thong tin sinh vien thu " << i + 1 <<"----------" << endl;
		nhap(sv[i]);
	}
}

void xuat(SINHVIEN sv)
{
	cout<<"MSV: " << sv.masv
	    <<"\t Ho ten: " << sv.hoten
	    <<"\t Ngay sinh: " << sv.nt.ngay << "-"<< sv.nt.thang << "-"<< sv.nt.nam
	    <<"\t Gioi tinh: " << sv.gt
	    <<"\t Ho khau: " << sv.hokhau
	    <<"\t DTN: "<< sv.diem << endl;
}

void xuatds(SINHVIEN sv[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<endl;
		cout<<"---------Thong tin sinh vien thu " << i + 1 <<"----------" << endl;
		xuat(sv[i]);
	}
}

float dtb(SINHVIEN sv[], int n)
{
	float s = 0;
	for(int i = 0; i < n; i++)
	{
		s += sv[i].diem;
	}
	return s / n;
}

void sapxep(SINHVIEN sv[], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(strcmpi(sv[i].hoten, sv[j].hoten) < 0)
			{
				SINHVIEN tg = sv[i];
				sv[i] = sv[j];
				sv[j] = tg;
			}
		}
	}
}

int main()
{
	int n;
	SINHVIEN sv[98];
	danhsachsv(sv,n);
	xuatds(sv,n);
	cout<<"Diem trung binh cua " << n << " sinh vien la: "<< dtb(sv,n) << endl;
	sapxep(sv,n);
	cout<<"Danh sach sinh vien sau khi sap xep: "<<endl;
	xuatds(sv,n);
	return 0;
}
