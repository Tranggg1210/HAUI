#include<bits/stdc++.h>
using namespace std;

struct dienthoai {
	string nhanHieu;
	long kichThuoc;
	long giaBan;
};

// khoi tao du lieu
const int n = 8;
	dienthoai d[n] = {
		{"Dien thoai 1", 4, 500},
		{"Dien thoai 2", 6, 800},
		{"Dien thoai 3", 5, 950},
		{"Dien thoai 4", 8, 200},
		{"Dien thoai 5", 3, 120},
		{"Dien thoai 6", 4, 50},
		{"Dien thoai 7", 5, 60},
		{"Dien thoai 8", 6, 120}
	};
const long s = 12;
long f[n+1][s+1];

// hien thi danh sach quat khi moi khoi tao
void hienThiDS()
{
	cout<<"---------------------- DANH SACH QUAT VUA KHOI TAO ----------------------" << endl;
	cout<< setw(20) << left << "Nhan hieu"
		<< setw(20) << left << "Kich thuoc"
		<< setw(20) << left << "Gia ban" << endl;
	for(int i = 0; i < n; i++)
	{
		cout<< setw(20) << left << d[i].nhanHieu
			<< setw(20) << left << d[i].kichThuoc
			<< setw(20) << left << d[i].giaBan << endl;
	}
}

// thuat toan quy hoach dong
void quyHoachDong()
{
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= s; j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= d[i].kichThuoc)
				f[i][j] = max(f[i][j], f[i-1][j - d[i].kichThuoc] + d[i].giaBan);
		}
	}
}

// hien thi ket qua
void ketQua()
{
	cout<< "Tong gia ban lon nhat la: " << f[n][s] << endl;
	
}

int main()
{
	hienThiDS();
	quyHoachDong();
	ketQua();
	return 0;
}
