#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void nhap(int &n, int &m)
{
	cout<<"Nhap n: ";
	cin >> n;
	cout<<"Nhap m: ";
	cin >> m;
	if(n > m) swap(m,n);
}

int tong(int n, int m)
{
	int s = 0;
	for(int i = n; i <= m; i++)
	{
		if((i % 3 == 0) && (i % 5 == 0))
		    s +=  i;
	}
	return s;
}

float F(float x, int n)
{
	float f;
	if(n <= 0) f = 1;
	else{
		f = fabs(n * x) * 2020;
    	for(int i = 1; i <= n; i++)
    	{
    		f += (x / (2 * n - i));
     	}
	}
	return f;
}

int main()
{
	int n,m;
	float x;
	nhap(n,m);
	cout << "Nhap x: ";
	cin >> x;
	cout<<"\nTong cac so chia het 3 va 5 trong doan [" << n << "," << m <<"] la: " <<tong(n,m) << endl;
	cout<<"\nTong cac so chia het 3 va 5 trong doan [1"  << "," << n <<"] la: " <<tong(1,n) << endl;
	cout<<"\nGia tri bieu thuc T = " << fixed << setprecision(4) << F(x,m) - F(x,n) << endl; 
	return 0;
}
