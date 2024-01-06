#include<iostream>
#include<fstream>
using namespace std;

void nhap(int &n, int *&a)
{
	do{
		cout<<"Nhap n > 0: ";
		cin>>n;
	}while(n <= 0);
	a = new int [n];
	for(int i = 0; i < n; i++)
	{
		cout<< "Nhap a[" << i << "]: ";
		cin>>a[i];
	}
}

void xuat(int n, int *a)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout<<endl;
}


void taofile(char *s, int n, int *a)
{
	ofstream f(s, ios::out);
	f << n << endl;
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
		for(int j = i + 1 ; j < n; j++)
		{
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
	}
}

void xoamang(int &n, int *&a)
{
	int dem = 0, t= 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] %2 == 0) dem++;
	}
	int *b = new int[n - dem];
	for(int i = 0; i < n; i++ )
	{
		if(a[i] % 2 == 0)
		{
			continue;
		}
		b[t++] = a[i];
	}
	n -= dem;
	delete a;
	a = b;
}

void saochep(int &n, int *&a)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] < 0) dem++;
	}
	if(dem == 0) cout<< "Trong mang khong co phan tu am!"<< endl;
	else{
		int *b = new int[n + dem];
		int t, m = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] < 0)
			{
				b[m++] = a[i]; 	
			}
		}
		for(int i = 0; i < n; i++)
		{
			b[m++] = a[i];
		}
		n = m;
	    delete a;
	    a = b;
	    cout<<"Mang a theo ycbt la: "<< endl;
	    xuat(n,a);
	}

}

int main()
{
	int n,*a;
	nhap(n,a);
	cout<<"Mang vua nhap la: "<< endl;
	xuat(n,a);
	char s[255] = "ABC2014.TXT";
	taofile(s,n,a);
	cout<<"Mang sau khi sap xep tang dan la: "<<endl;
	sapxep(n,a);
	xuat(n,a);
	taofile("XYZ2014.TXT",n,a);
	xoamang(n,a);
	if(n == 0)
	{
		cout<<"Tat ca phan tu trong mang deu la so chan!"<< endl;
	}else{
		cout<<"Mang sau khi xoa la: "<< endl;
	    xuat(n,a);
	}
	saochep(n,a);
	delete a;
	return 0;
}
