#include<bits/stdc++.h>
using namespace std;

struct dienthoai{
	string nhanhieu;
	long kichthuoc, giatien;
};

// khoi tao
const int n = 8;
const long s = 12;
dienthoai d[n] = {
	{"SamSung", 5, 20},
	{"Xiaomi", 6, 25},
	{"Oppo", 4, 53},
	{"SamSung A23", 5, 42},
	{"Iphone 8", 6, 16},
	{"Vivo", 4, 19},
	{"Iphone 15", 5, 200},
	{"Vivo 2", 6, 23},
};
double f[n+1][s+1];

// ham in title va du lieu
void printTitle()
{
	cout<< setw(20) << left << "Nhan hieu"
		<< setw(20) << left << "Kich thuoc"
		<< setw(20) << left << "Gia tien" << endl;
}

void printData(int i)
{
	cout<< setw(20) << left << d[i].nhanhieu
		<< setw(20) << left << d[i].kichthuoc
		<< setw(20) << left << d[i].giatien << endl;
}

// hien thi mang 1 chieu
void hienThi()
{
	cout<<"-------------------- DANH SACH DIEN THOAI VUA KHOI TAO --------------------"<<endl;
	printTitle();
	for(int i = 0; i < n; i++)
	{
		printData(i);
	}
}

// thuat toan quy hoach dong
long quyHoachDong()
{
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= s; j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= d[i].kichthuoc)
				f[i][j] = max(f[i][j], f[i-1][j - d[i].kichthuoc] + d[i].giatien);
		}
	}
	return f[n][s];
}

// ket qua
void ketQua()
{
	cout<<"Tong gia ban lon nhat la: " << quyHoachDong() << endl;
	cout<<"Bang chien luoc la: "<< endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= s; j++)
			cout<< f[i][j] << "\t";
		cout<<endl;
	}
	
	int i = n, j = s;
	cout<<"-------------------- DANH SACH DIEN THOAI DUOC CHON --------------------"<<endl;
	printTitle();
	while(i != 0)
	{
		if(f[i][j] != f[i-1][j])
		{
			printData(i);
			j -= d[i].kichthuoc;
		}
		i--;
	}
	
}

int main()
{
	hienThi();
	ketQua();
	return 0;
}
