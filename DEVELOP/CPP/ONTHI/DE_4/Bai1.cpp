#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void nhapn(int &n)
{
	do{
		cout<<"Nhap n > 0: ";
		cin >> n;
	}while(n <= 0);
}

void nhapx(float &x)
{
	cout<<"Nhap x: ";
	cin >> x;
}

long F(int n)
{
	long s = 1;
	for(int i = 1; i <= n; i++)
	{
		s *= (2*i - 1);
	}
	return s;
}

float P(float x, int n)
{
	float p = fabs(x);
	for(int i = 2; i <= n; i++)
	{
		p += ((i*1.0) / F(i));
	}
	return p;
}

int main()
{
	int n;
	float x;
	nhapn(n);
	nhapx(x);
	cout<<"Gia tri bieu thuc P(" 
	    << x << "," << 2 * n << ") la: " 
	    << fixed << setprecision(4) << P(x,2*n);
	return 0;
}
