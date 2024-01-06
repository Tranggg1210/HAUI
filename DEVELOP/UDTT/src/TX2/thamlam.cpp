#include<bits/stdc++.h>
using namespace std;

struct quat{
	string tenHSX;
	string mausac;
	long giaban;
};

void hienThiDSQuat(quat d[], int n)
{
	cout<<"---------------- DANH SACH QUAT MOI KHOI TAO ----------------"<< endl;
	cout<< setw(20) << left << "Ten HSX"
		<< setw(20) << left << "Mau sac"
		<< setw(20) << left << "Gia ban" << endl;
	for(int i = 0; i < n; i++)
	{
		cout<< setw(20) << left << d[i].tenHSX
			<< setw(20) << left << d[i].mausac
			<< setw(20) << left << d[i].giaban << endl;
	}
}

// sap xep giam dan theo gia tien cua quat
bool cmp(quat a, quat b)
{
	return a.giaban > b.giaban;
}

// Chien luoc tham lam
bool thamLam(int n, long *z, quat d[], long p)
{
	sort(d, d+n, cmp);
	int i = 0;
	while(p != 0 && i < n)
	{
		z[i] = p/d[i].giaban;
		p -= ((p/d[i].giaban) * d[i].giaban);
		i++;
	}
	if(p > 0) return false;
	return true;
}


void hienThiKetQua(int n, long *z, quat d[])
{
	int dem = 0;
	for(int i = 0; i < n; i++) dem += z[i];
	cout<< "Co the ban it nhat " << dem << " chiec quat" << endl;
	cout<<"---------------- DANH QUAT DUOC CHON ----------------"<< endl;
	cout<< setw(20) << left << "Ten HSX"
		<< setw(20) << left << "Gia ban"
		<< setw(20) << left << "So luong" << endl;
	for(int i = 0; i < n; i++)
	{
		if(z[i])
		{
			cout<< setw(20) << left << d[i].tenHSX
				<< setw(20) << left << d[i].giaban
				<< setw(20) << left << z[i] << endl;
		}
	}
}

int main()
{
	int n = 8;
	long *z = new long[n];
	memset(z, 0, sizeof(long)*n);
	long p = 1000000;
	quat d[n] = {
		{"Panasonic 1", "red", 60000},
		{"Panasonic 2", "green", 80000},
		{"Panasonic 3", "yellow", 20000},
		{"Panasonic 4", "red", 40000},
		{"Panasonic 5", "red", 70000},
		{"Panasonic 6", "red", 90000},
		{"Panasonic 7", "red", 80000},
		{"Panasonic 8", "red", 10000},
	};
	hienThiDSQuat(d,n);
	if(thamLam(n,z,d,p))
		hienThiKetQua(n,z,d);
	else cout<<"Khong the tim duoc"<<endl;
	delete[] z;
	return 0;
}
