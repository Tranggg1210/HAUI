#include<iostream>
using namespace std;

int n;
float a[10][10];

void nhap(int &n)
{
	do{
		cout<<"Nhap n: "<<endl;
		cin>>n;
	}while( n < 3 || n > 10);
}

void nhapA(int n, float a[][10])
{
	cout<<"Nhap ma tran cua ban: "<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}
}

void xuat(int n, float a[][10])
{
	cout<<"Ma tran vua nhap la: "<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<< a[i][j] << "\t";
		}
		cout<<endl;
	}
}

bool mtdv(int n, float a[][10])
{
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(i == j)
			{
				if(a[i][j] != 1) return false;
			}else if(a[i][j] != 0) return false;
		}
	}
	return true;
}


void dinhthuc(float a[][10], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n ; j++)
		{
			float m;
			m = - a[j][i]/a[i][i];
			for(int k = i; k < n ; k++)
			{
				a[j][k] = a[j][k] + (a[i][k] * m);
		    } 
		}
	}
	int s = 1;
	for(int i = 0; i < n; i++)
	{
		s *= a[i][i];
	}
	cout<<"Dinh thuc cua ma tran khong co phan tu khong la: " << s;
}

int main()
{
	nhap(n);
	nhapA(n,a);
	xuat(n,a);
	if(mtdv(n,a)){
		cout<<"Day la ma tran don vi"<<endl;
		cout<<"Dinh thuc cua ma tran la 1";
	}
	else 
	{
		cout<<"Day khong phai ma tran don vi" <<endl;
		dinhthuc(a,n);
	}
	return 0;
}
