#include<iostream>
using namespace std;

int m,n,p,q;
int a[21][21], b[21][21], c[21][21], d[21][21];

void nhapA(int &m, int &n, int a[][21])
{
	do{
		cout<<"Nhap so dong m: " << endl;
		cin>>m;
	}while( m < 1 || m > 20);
	do{
		cout<<"Nhap so cot n: " << endl;
		cin>>n;
	}while( n < 1 || n > 20);
	cout<<"Nhap ma tran A: "<<endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>a[i][j];
		}
	}
}

void nhapB(int &p, int &q, int a[][21])
{
	do{
		cout<<"Nhap so dong p: " << endl;
		cin>>p;
	}while( p < 1 || p > 20);
	do{
		cout<<"Nhap so cot q: " << endl;
		cin>>q;
	}while( q < 1 || q > 20);
	cout<<"Nhap ma tran B: "<<endl;
	for(int i = 0; i < p; i++)
	{
		for(int j = 0; j < q; j++)
		{
			cin>>b[i][j];
		}
	}
}

void hienThi(int m, int n, int a[][21])
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<< a[i][j] << "\t";
		}
		cout<<endl;
	}
}

void mangC(int m, int n, int p, int q, int a[][21], int b[][21], int c[][21])
{
	if(m == p && n == q)
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		cout<<"Mang C = A + B la: "<<endl;
		hienThi(m,n,c);
	}else cout<<"Vi hai ma tran khong cung kich thuc nen khong cong duoc!";
}

void mangD(int m, int n, int p, int q, int a[][21], int b[][21], int d[][21])
{
	if(n == p)
	{
		for(int i = 0; i < m; i++){
			for(int j = 0; j < q ; j++){
				int s = 0;
				for(int k = 0; k < n; k++ )
				{
					s += a[i][k] * b[k][j];
				}
				d[i][j] = s;
			}
		}
		cout<<"Mang D = A * B la: "<<endl;
		hienThi(m,q,d);
	}else cout<<"Khong the thuc hien phep nhan vi so cot cua ma tran A khong bang so dong cua ma tran B";
}

int main()
{
	nhapA(m,n,a);
	nhapB(p,q,b);
	mangC(m,m,p,q,a,b,c);
	mangD(m,m,p,q,a,b,d);
	return 0;
}
