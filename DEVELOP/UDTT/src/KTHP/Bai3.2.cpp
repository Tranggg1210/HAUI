#include<bits/stdc++.h>
using namespace std;

struct hang{
	string tenHang;
	long m;
	double v;
};

double dp[10][16];

void hienThiDanhSach(int n, hang a[])
{
	cout<<"-------------- DANH SACH A VUA KHOI TAO --------------"<<endl;
	cout<< setw(20) << left << "Ten hang"
		<< setw(15) << left<< "Khoi luong"
		<< setw(15) << left << "Gia tri" << endl;  
	for(int i = 0; i < n; i++)
	{
		cout<< setw(20) << left << a[i].tenHang
			<< setw(15) << left<< a[i].m
			<< setw(15) << left << a[i].v << endl;  
	}
}

// chien luoc tham lam
bool cmp(hang a, hang b)
{
	return a.v < b.v;
}
bool thamlam(int n, int *z, hang a[], double c)
{
	sort(a, a + n, cmp);
	int i = 0;
	while(i < n && c >= 0)
	{
		c -= a[i].v;
		z[i] = 1;
		i++;
	}
	if(c > 0 || c < 0) return false;
	return true;
}

void ketQua(int n, int *z, hang a[])
{
	int d = 0;
	for(int i = 0; i < n; i++) d += z[i];
	cout<< "So hang co the lay la: " << d << endl;
	cout<<"-------------- DANH SACH CAC MAT HANG DUOC CHON --------------"<<endl;
	cout<< setw(20) << left << "STT"
		<< setw(15) << left<< "Ten hang"
		<< setw(15) << left << "Gia tri" << endl;  
	for(int i = 0; i < n; i++)
	{
		if(z[i] != 0)
			cout<< setw(20) << left << i + 1
				<< setw(15) << left<< a[i].tenHang
				<< setw(15) << left << a[i].v << endl;  
	}
}

// quy hoach dong
void quyHoachDong( int n, long m1, hang a[])
{
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= 15; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(a[i].m <= j)
				dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].m] + a[i].v);
		}
	}
}

// ket qua
void ketQua2(int n, long m1, hang a[])
{
	cout<< "Tong gia tri hang lon nhat la: " << dp[n][m1]<< endl;
	cout<<"Bang chien luoc la: "<< endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m1; j++)
			cout<< dp[i][j] << "\t";
		cout<<endl;
	}  
	cout<<"-------------- DANH SACH CAC MAT HANG DUOC CHON Y 2 --------------"<<endl;
	cout<< setw(20) << left << "Ten hang"
		<< setw(15) << left << "Gia tri" << endl;
		
	int i = n, j = m1;
	while(i != 0)
	{
		if(dp[i][j] != dp[i-1][j])
		{
			cout<< setw(20) << left << a[i].tenHang 
				<< setw(15) << left << a[i].v << endl; 
			j -= a[i].m; 
		}
		i--;
	}
}

int main()
{
	//khoi tao
	int n = 9;
	hang a[n] = {
		{"Tivi", 12, 8},
		{"Tu lanh", 20, 9},
		{"May giay", 10, 12},
		{"May tinh", 2, 29},
		{"May say", 1, 2.8},
		{"May suoi", 8, 12},
		{"Dieu hoa", 19, 20},
		{"Quat", 2, 6.9},
		{"Dien thoai", 1, 39}
	};
	double c = 39.8;
	long m = 15;
	int *z = new int[n];
	memset(z,0,sizeof(int)*n);
	
	// hien thi danh sach
	hienThiDanhSach(n,a);
	
	// y 1
	if(thamlam(n,z,a,c))
		ketQua(n,z,a);
	else cout<< "Khong the tim duoc" << endl;
	
	// y 2
	quyHoachDong(n,m,a);
	ketQua2(n,m,a);
	// huy con tro
	delete[] z;
	return 0;
}
