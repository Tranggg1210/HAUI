#include<iostream>
using namespace std;

struct NGAYTHANG{
	int ngay;
	int thang;
	int nam;
};

struct Hocsinh{
	char hoten[40];
	NGAYTHANG nt;
	char gt[10];
	char hokhau[20];
	float diem;
};

int main()
{
	Hocsinh hs = {
		"Nguyen Thi Trang",
		{12,10,2003},
		"nu",
		"Hung Yen",
		10.0
	};
	cout<<"Ho va ten: " << hs.hoten <<endl;
	cout<<"Ngay, thang, nam sinh: "<< hs.nt.ngay << "/"<< hs.nt.thang << "/"<< hs.nt.nam << endl;
	cout<<"Gioi tinh: "<<hs.gt << endl;
	cout<< "Ho khau: "<<hs.hokhau<<endl;
	cout<<"Diem trung binh: "<<hs.diem << endl;
	return 0;
}
