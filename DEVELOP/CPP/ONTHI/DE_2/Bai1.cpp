#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

void nhap(float &x, float &y, int &m)
{
	cout<<"Nhap y: ";
	cin >> y; 
	do{
		cout<<"Nhap x < y ";
		cin >> x; 
	}while(x >= y);
	do{
		cout<<"Nhap m > 0: ";
		cin >> m;
	}while(m <= 0);
}

float gt(int k)
{
	float a = 1;
	for(int i = 1; i <= k; i++)
	{
		a *= i;
	}
	return a;
}

double P(float x, float y)
{
	double p;
	if(x >= y) p = 1;
	else{
		p = 1;
		float k = 1;
		int i = 1;
		do{
			k *= fabs(x);
			p += (k/gt(i));
			i++;
		}while( (k/gt(i)) > 0.00001);
		p += (fabs(y) + sqrt(fabs(y - x)));
	}
	return p;
}

float F(float x, int n)
{
	float f = 2020*x;
	float a = x;
	for(int i = 2; i <= n; i++)
	{
		a *= x;
		float b = i;
		for(int j = 1; j < i; j++)
		{
			b *= i;
		}
		f += (a/b);
	}
	return f;
}

int main()
{
	float x,y;
	int m;
	nhap(x,y,m);
	cout<<"Gia tri bieu thuc P(" << x << "," << y << ") = " << fixed << setprecision(4) << P(x,y) << endl;
	cout<<"Gia tri bieu thuc F(" << x+y << "," << m << ") = " << fixed << setprecision(4) << F(x+y,m) << endl;
	return 0;
}
