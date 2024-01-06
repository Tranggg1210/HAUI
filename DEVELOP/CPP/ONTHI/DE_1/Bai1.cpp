#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int tang1(int &n)
{
	return n += 1;
}

void nhap(int &n, float &x)
{
	cout<<"Nhap n: ";
	cin >> n;
	cout<< "Nhap x: ";
	cin>>x;
}

float S(float x, int n)
{
	float s = 0;
	if(n > 2)
	{
		s = sqrt(2019);
		float k = 1;
		for(int i = 1; i <= n; i++)
		{
			k *= (x+1);
			s += k;
		}
	}else s = fabs(n * x);
	return s;
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

double P(int n, float x)
{
	double p;
	if( n > 0)
	{
		p = 1;
		float k = 1;
	    int i = 1;
    	do{
	    	k *= fabs(x);
	    	p += (k/gt(i));
	    	i++;
	    }while( (k/gt(i)) > 0.00001);
	    p *= 2020;
	    for(int j = 1; j <=n; j += 2)
	    {
	    	p += j;
	    }
	}else p = -1;
	return p;
}

int main()
{
	float x;
	int n;
	nhap(n,x);
	tang1(n); tang1(n); tang1(n);
	cout<<endl;
	if(P(n,x) == -1) cout<< "Loi vi n khong phai so nguyen duong nen khong the tinh P(n)" << endl;
	else cout<< "Gia tri bieu thuc S(x,n)/P(n) la:  "<< fixed << setprecision(4) << S(x,n)/P(n,x) << endl;
	return 0;
}
