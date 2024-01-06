#include<iostream>
#include<iomanip>
using namespace std;

void nhap(float &x, float &y, int &n)
{
	cout<<"Nhap x: ";
	cin>>x;
	cout<<"Nhap y: ";
	cin>>y;
	do{
		cout<<"Nhap n > 0: ";
		cin>>n;
	}while(n <= 0);
}

float dthcn(float x, float y)
{
	if(x == 0 || y == 0) return -1;
	return x * y;
}

int tong(int n)
{
	int s = 0;
	for(int i = 1; i <= n; i++)
	{
		if( i % 2 == 0)
		   if(i % 3 == 0) s+= i;
	}
	return s;
}

double F1(float x, int n)
{
	double f1 = 0;
	float k = 1;
	float t = 1;
	for(int i = 1; i <= n; i++)
	{
		t *= 3;
		k *= x;
		f1 += (k/t);
	}
	return f1 + (2016*k);
}

float gt(int k)
{
	float gt = 1;
	for(int i = 1; i <= k; i++)
	{
		gt *= i;
	}
	return gt;
}

float F2(float x, int n)
{
	float f2 = 0, e = 1;
	if(n > 10)
	{
		f2 = 2016 * x;
	}else{
		float k = 1;
		int i = 1;
		do{
			k *= x;
			e += (k / gt(i));
			i++;
		}while((k / gt(i)) > 0.00001);
		for(int i = 1; i <= n; i++)
		{
			f2 += i;
		}
		f2 += e;
	}
	return f2;
}

int main()
{
	int n;
	float x,y;
	nhap(x,y,n);
	if(dthcn(x,y) == -1) cout<<"Day khong phai hinh chu nhat vi co canh bang 0"<<endl;
	else cout<<"Dien tich hinh chu nhat voi hai canh "
	         << x << " va " << y << " la: " << dthcn(x,y) << endl;
	if( tong(n) == 0) cout<< "Khong co so chan nao chia het cho 3 nam trong doan tu 1 den "<< n << endl;
	else cout<<"Tong cac so chan va chia het cho 3 nam trong doan tu 1 den " << n << " la: " << tong(n) << endl;
	cout<<"Gia tri cua F1 la: " << fixed << setprecision(3) << F1(x,n) << endl;
	cout<<"Gia tri cua F2 la: " << fixed << setprecision(3) << F2(x,n) << endl;
	return 0;
}
