#include<iostream>
using namespace std;

int n, a[100], b[100], t;

void nhap(int &n)
{
	do{
		cout<<"Nhap n: " << endl;
		cin>>n;
	}while( n < 1 || n > 30);
}

void nhapMang(int a[], int n)
{
	cout<<"Nhap mang cua ban: ";
    for(int i = 0; i < n; i++)
	{
		cout<<endl;
		cout<<"Nhap a[" << i << "] = ";
		cin>>a[i];
	}	
}

void xuLy(int a[], int n, int b[], int &t)
{
	t = 0;
	for(int i = n - 1; i >= 0; i--)
	    b[t++] = a[i];
}

void hienThi(int a[], int n)
{
	for(int i = 0; i < n; i++ )
	    cout<< a[i] << "\t";
}

int main()
{
	nhap(n);
	nhapMang(a,n);
	xuLy(a,n,b,t);
	cout<<"Mang A la: " << endl;
	hienThi(a,n);
	cout<<endl;
	cout<<"Mang B la: " << endl;
	hienThi(b,t);
	return 0;
}
