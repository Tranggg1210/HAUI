#include<iostream>
#include<fstream>
#include <stdlib.h>
using namespace std;


//void nhap(char *a)
//{
//	int m, n;
//	do{
//		cout<<"Nhap so dong n cua ma tran: ";
//		cin>>n;
//	}while(n <= 0);
//	do{
//		cout<<"Nhap so cot m cua ma tran: ";
//		cin>>m;
//	}while(m <= 0);
//	ofstream f(a, ios::out);
//	f << n << m << endl;
//	int **b;
//	b = new int *[n];
//	for(int i = 0; i < n; i++)
//	{
//		b[i] = new int[m];
//	}
//		cout<<"-----Nhap du lieu ma tran vao file----- "<<endl;
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < m; j++)
//		{
//			cin >> b[i][j];
//			f << b[i][j] << "\t";
//		}
//		f << endl;
//	}
//	f.close();
//	delete []b;
//}

void nhap(char *a)
{
	int m,n,t;
	ofstream f(a, ios::out);
	cout<<"Nhap so dong n cua ma tran: ";
	cin>> n;
	f << n << endl;
	cout<<"Nhap so cot m cua ma tran: ";
	cin>> m;
	f << m << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<"Nhap a[" << i << "][" << j << "] = ";
			cin>>t;
			f << t << "\t";
		}
		f<<endl;
	}
	f.close();
}

void doc(char *a)
{
	ifstream f(a, ios::in);
	char s[255];
	while( !f.eof())
	{
		f.getline(s,255);
		cout<< s << endl;
	}
	f.close();
}

void doc1(char *a, int &m, int &n, int **&b)
{
	ifstream f(a, ios::in);
	char s[255];
	f >> s;
	n = atoi(s);
	f >> s;
	m = atoi(s);
	b = new int *[n];
	for(int i; i < n; i++)
	{
		b[i] = new int[m];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			f >> s;
			b[i][j] = atoi(s);
		}
	}
	f.close();
}

void xuat1(int **b, int m, int n)
{
	cout<< "XUAT MA TRAN"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<< b[i][j] << "\t";
		}
		cout<<endl;
	}
}

int main()
{
	char a[100];
	fflush(stdin);
	cout<<"Nhap ten file: ";
	gets(a);
	nhap(a);
	cout<< "File vua nhap la: "<<endl;
	doc(a);
	int m,n,**b;
	doc1(a,m,n,b);
	xuat1(b,m,n);
	delete []b;
	return 0;
}
