#include<bits/stdc++.h>
using namespace std;

struct HANG_HOA {
	const char* tenHH;
	double khoiLuong;
	double giaBan;
	
	HANG_HOA(){}
	HANG_HOA(const char* ten, double kl,double gb)
	{
		tenHH = ten;
		khoiLuong = kl;
		giaBan = gb;
	}
};

void fakeDATA(HANG_HOA d[], int n)
{
	d[0] = HANG_HOA("TI VI", 15, 12600000);
    d[1] = HANG_HOA("TU LANH", 32, 21050000);
    d[2] = HANG_HOA("MAY GIAT", 12, 8000000);
    d[3] = HANG_HOA("DIEU HOA", 42, 10740000);
    d[4] = HANG_HOA("LAPTOP", 3, 20100000);
    d[5] = HANG_HOA("BEP TU", 5.5, 5020000);
    d[6] = HANG_HOA("BEP GA", 3.2, 1200000);
    d[7] = HANG_HOA("MAY IN", 19, 21000000);
}

void printDATA(HANG_HOA d[], int n)
{
	cout<< setw(8) << "TEN HH"
		<< setw(15) << "KHOI LUONG"
		<< setw(15) << "GIA BAN" << endl;
		
	cout << setprecision(0) << fixed;
	
	for(int i = 0; i < n; i++)
	{
		cout<< setw(8) << d[i].tenHH
			<< setw(15) << d[i].khoiLuong
			<< setw(15) << d[i].giaBan << endl;
	}
}

// tinh tong gia ban
double sumPrice(HANG_HOA d[], int n)
{
	if(n == 1) return d[0].giaBan;
	return d[n-1].giaBan + sumPrice(d,n-1);
}

// y 3
int count_DATA(HANG_HOA p, HANG_HOA d[], int l, int r)
{
	if(l == r) return p.giaBan > d[l].giaBan ? 1 : 0;
	int m = (l+r)/2;
	return count_DATA(p,d,l,m) + count_DATA(p,d,m+1,r);
}

void show(int x)
{
	for(int i = 0; i < x; i++)
	{
		
	}
}

void Try(int k)
{
	for(int i = 0; i <= 8; i++)
	{
		x[k] = i;
		if(i == 8)
			show(x);
		else Try(k+1);
	}
}

int main()
{
	int n = 8;
	HANG_HOA d[n];
	fakeDATA(d,n);
	cout<<"\t===== BANG HANG HOA VUA FAKE ====="<< endl;
	printDATA(d,n);
	cout<< "\nTong gia ban: " << sumPrice(d,n);
	
	HANG_HOA p("TU KINH", 20, 19000000);
	cout<< "\nSo hang hoa trong danh sach d co gia thap hon p(TU KINH, 20, 19000000): " << count_DATA(p,d,0,n-1);
	return 0;
}
