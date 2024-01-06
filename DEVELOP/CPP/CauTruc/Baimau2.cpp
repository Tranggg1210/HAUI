#include<iostream>
using namespace std;

struct NGAYSINH{
	int ngay;
	int thang;
	int nam;
};

struct HOCSINH{
	char hoten[30];
	NGAYSINH nt;
	char gt[5];
	char hokhau[20];
	float diemtb;
};

void nhap(HOCSINH &hs)
{
	fflush(stdin);
	cout<<"Nhap ho ten hoc sinh: ";
	gets(hs.hoten);
	cout<<endl;
	cout<<"Nhap ngay sinh cua hoc sinh: ";
	cin>>hs.nt.ngay;
	cout<<"Nhap thang sinh cua hoc sinh: ";
	cin>>hs.nt.thang;
	cout<<"Nhap nam sinh cua hoc sinh: ";
	cin>>hs.nt.nam;
	cout<<endl;
	fflush(stdin);
	cout<<"Nhap gioi tinh cua hoc sinh: ";
	gets(hs.gt);
	cout<<endl;
	fflush(stdin);
	cout<<"Nhap ho khau cua hoc sinh: ";
	gets(hs.hokhau);
	cout<<endl;
	cout<<"Nhap diem trung binh cua hoc sinh: ";
	cin>>hs.diemtb;
}

void xuat(HOCSINH hs)
{
	cout<<"-------------------THONG TIN HOC SINH---------------------"<<endl;
	cout<<"Ho va ten: " << hs.hoten <<endl;
	cout<<"Ngay, thang, nam sinh: "<< hs.nt.ngay << "/"<< hs.nt.thang << "/"<< hs.nt.nam << endl;
	cout<<"Gioi tinh: "<<hs.gt << endl;
	cout<< "Ho khau: "<<hs.hokhau<<endl;
	cout<<"Diem trung binh: "<<hs.diemtb << endl;
}

int main()
{
	HOCSINH hs;
	nhap(hs);
	xuat(hs);
	return 0;
}
