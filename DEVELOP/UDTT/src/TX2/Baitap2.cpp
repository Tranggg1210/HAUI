#include<bits/stdc++.h>
using namespace std;

struct quat {
	string tenHang;
	string mauSac;
	double giaBan;
};



// hien thi du lieu
void hienThi(quat d[], int n)
{
	cout<<"------------ DANH SACH QUAT VUA KHOI TAO ------------" << endl;
	cout<< setw(20) << left <<"Hang SX"
		<< setw(20) << left << "Mau sac"
		<< setw(20) << left << "Gia ban" << endl;
	for(int i = 0; i < n; i++)
	{
		cout<< setw(20) << left << d[i].tenHang
			<< setw(20) << left << d[i].mauSac
			<< setw(20) << left << d[i].giaBan << endl;
	}
}

// sap xep theo gia
bool cmp(quat a, quat b)
{
	return a.giaBan < b.giaBan;
}

//thuat toan tham lam
bool thamLam(long *s, int n, long p, quat d[])
{
	sort(d, d+n, cmp);
	int i = 0;
	while(p > 0 && i < n)
	{
		s[i] = p/d[i].giaBan;
		p -= ((p/d[i].giaBan) * d[i].giaBan);
		i++;
	}
	return true;
}

// hien thi ket qua
void ketQua(long *s, quat d[], int n)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] != 0)
		{
			dem+= s[i];
		}
	}
	cout<<"\nCo the lay toi da " << dem << " chiec quat" << endl;
	cout<<"------------ DANH SACH QUAT DUOC CHON ------------" << endl;
	cout<< setw(20) << left <<"Hang SX"
		<< setw(20) << left << "Gia ban"
		<< setw(20) << left << "So chiec" << endl;
	for(int i = 0; i < n; i++)
	{
		if(s[i] != 0)
		{
			cout<< setw(20) << left << d[i].tenHang
				<< setw(20) << left << d[i].giaBan 
				<< setw(20) << left << s[i] << endl; 
		}
	}
	
}

int main()
{
	// Khoi tao
	int n = 8;
	long *s;
	s = new long[n];
	memset(s, 0, sizeof(long) * n);
	long p = 1000000;
	quat d[n] = {
		{"Panasonic 1", "red", 50000},
		{"Panasonic 2", "blue", 6000},
		{"Panasonic 3", "green", 95000},
		{"Panasonic 4", "black", 10000},
		{"Panasonic 5", "yellow", 500000},
		{"Panasonic 6", "white", 5000},
		{"Panasonic 7", "pink", 60000},
		{"Panasonic 8", "gray", 120000}
	};
	
	// hien thi mang moi khoi tao
	hienThi(d,n);
	if(thamLam(s,n,p,d)){
		ketQua(s,d,n);
	}else cout<<"\nKhong tim thay nghiem";
	
	
	// Huy con tro
	delete[] s;
	return 0;
}
