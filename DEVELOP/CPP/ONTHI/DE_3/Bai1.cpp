#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void nhap(float &x, int &n, int &m)
{
	cout<< "Nhap x: ";
	cin >> x;
	do{
		cout<< "Nhap n > 0: ";
		cin >> n;
	}while(n <= 0);
	do{
		cout<< "Nhap m > 0: ";
		cin >> m;
	}while(m <= 0);
}

float gt(int n)
{
	float a = 1;
	for(int i = 1; i <= n; i++) a *= i;
	return a;
}

float P(float x, int n)
{
	float p;
	p = (1/gt(n));
	float k = 1;
	double e = 1;
	int i = 1;
	do{
		k *= fabs(x);
		e += (k/gt(i));
		i++;
	}while((k/gt(i)) > 0.000001);
	e *= 2020;
	k = 1;
	for(i = 0; i <= n; i++)
	{
		k *= x;
		e += fabs(k);
	}
	p *= e;
	return p;
}

float K(float x, int n, int m)
{
	return (P(x,n) + P(x,m)) / (P(x,n+m));
}

int main()
{
	float x;
	int n,m;
	nhap(x,n,m);
	cout<< "Gia tri bieu thuc: " << fixed << setprecision(4) << K(x,n,m) + P(x,n) + P(x,m) << endl;
	cout<< "\n" << K(x,n,m) << endl;
	cout<< "\n" << P(x,n) << endl;
	cout<< "\n" << P(x,m) << endl;
	return 0;
}
