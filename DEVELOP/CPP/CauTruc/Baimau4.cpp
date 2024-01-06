#include<iostream>
using namespace std;

struct NGAYTHANG{
	int ngay;
	int thang;
	int nam;
};

struct SINHVIEN{
	char hoten[30];
	NGAYTHANG nt;
	char gt[5];
	char hokhau[20];
	float diem;
};

void nhap(SINHVIEN *sv)
{
	fflush(stdin);
	cout<<"Nhap ho ten sv: ";
	gets(sv->hoten);
	cout<<endl;
	cout<<"Nhap ngay thang nam sinh cua sv:"<<endl;
	cout<<"\n\t\tNgay: "; cin>>sv->nt.ngay;
	cout<<"\n\t\tThang: "; cin>>sv->nt.thang;
	cout<<"\n\t\tNam: "; cin>>sv->nt.nam;
	cout<<endl;
	fflush(stdin);
	cout<<"Nhap gioi tinh sv: ";
	gets(sv->gt);
	cout<<endl;
	fflush(stdin);
	cout<<"Nhap ho khau sv: ";
	gets(sv->hokhau);
	cout<<endl;
	cout<<"Nhap diem trung binh: ";
	cin >> sv->diem;
}

void xuat(SINHVIEN *sv)
{
	cout<<"--------------THONG TIN SINH VIEN -----------------"<<endl;
	cout<<"Ho ten: " << sv->hoten << endl;
	cout<< "Ngay thang nam sinh: "<< sv->nt.ngay << " - "<< sv->nt.thang << " - "<< sv->nt.nam << endl;
	cout<<"Gioi tinh: " << sv->gt<<endl;
	cout<<"Ho khau: "<< sv->hokhau <<endl;
	cout<<"Diem tb: "<< sv->diem<<endl;
}

int main()
{
	SINHVIEN *sv;
	sv = new SINHVIEN;
	nhap(sv);
	xuat(sv);
	delete sv;
	return 0;
}
