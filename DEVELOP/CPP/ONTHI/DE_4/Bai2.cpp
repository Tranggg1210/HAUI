#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void nhap(int &n, int *&a)
{
	do{
		cout<< "Nhap n > 0: ";
		cin >> n;
	}while(n <= 0);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i <<"]: ";
		cin >> a[i];
	}
}

void xuat(int n, int *a)
{
	for(int i = 0 ; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

void taofile(char *s, int n, int *a)
{
	ofstream f(s, ios::out);
	for(int i = 0; i < n; i++)
	{
		f << a[i] << "\t";
	}
	f.close();
}

void sapxep(int n, int *a)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j]) swap(a[i],a[j]);
		}
	}
}

void ghifile(char *s, int n, int *a)
{
	ofstream f(s, ios::app);
	f << endl;
	for(int i = 0; i < n; i++)
	    f << a[i] << "\t";
	f.close();
}

void lietke(int n, int *a)
{
	int x, dem=0;
	cout<<"\nNhap x: ";
	cin >> x;
	for(int i = 0; i < n; i++)
	{
		if(abs(a[i]) < x) dem++;
	}
	if(dem == 0) cout<<"\nTrong mang khong co phan tu nao co tri tuyet doi nho hon " << x << endl;
	else{
		int s = 0;
		cout<<"\nCac phan tu co tri tuyet doi nho hon " << x << " la: "<<endl;
		for(int i = 0; i < n; i++)
		{
			if(abs(a[i]) < x)
			{ 
			    s += a[i];
				cout<< a[i] << "\t";
			}
		}
		cout<<"\nTong cua chung la: "<< s << endl;
	}
}

void xoa(int &n, int *&a)
{
	int max = a[0], dem = 0;
	for(int i = 0; i < n; i++)
	    if(a[i] > max) max = a[i];
	for(int i = 0; i < n; i++)
	{
		if(a[i] == max) dem++;
	}
	if(dem == n)
	{
		 cout<<"\nMang bi xoa vi tat ca cac phan tu trong mang deu bang gia tri lon nhat cua mang"<< endl;
		 return ;
	}
	else{
		int *b = new int[n - dem];
		int t = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] == max) continue;
			b[t++] = a[i];
		}
		delete a;
		a = b;
	}
	n -= dem;
	cout<<"\nMang sau khi xoa la: "<<endl;
	xuat(n,a);
}

int main()
{
	int n,*a;
	nhap(n,a);
	cout<<"\nMang vua nhap la: "<< endl;
	xuat(n,a);
	char s[20] = "ABC2006.TXT";
	taofile(s,n,a);
	sapxep(n,a);
	cout<<"\nMang sau khi sap xep la: "<< endl;
	xuat(n,a);
	ghifile(s,n,a);
	lietke(n,a);
	xoa(n,a);
	delete a;
	return 0;
}
