#include<iostream>
#include<fstream>
using namespace std;

void nhap(int &n, float *&a)
{
	do{
		cout<<"Nhap n > 0: ";
		cin >> n;
	}while(n <= 0);
	a = new float[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void xuat(int n, float *a)
{
	for(int i = 0; i < n; i++)
	{
		cout<< a[i] << "\t";
	}
}

void taofile(char *s, int n, float *a)
{
	ofstream f(s, ios::out);
	for(int i = 0; i < n; i++)
	{
		f << a[i] << "\t";
	}
	f.close();
}

void sapxep(int n, float *a)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void ghifile(char *s, int n, float *a)
{
	ofstream f(s,ios::app);
	f << endl;
	for(int i = 0; i < n; i++ )
	{
		f << a[i] << "\t";
	}
	f.close();
}

int dem(int n, float *a)
{
	int dem1 = 0;
	float min = a[0];
	for(int i = 1; i < n; i++)
	{
		if(a[i] < min) min = a[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] == min) dem1++;
	}
	return dem1;
}

void nhapx(float &x)
{
	cout<< "Nhap x: ";
	cin >> x;
}

void chen(int &n, float *&a, float x)
{
	int vt = -1;
	for(int i = 0; i < n; i++)
	{
		if( a[i] > x){
			vt = i + 1;
			break;
		}
	}
	if(vt == -1) cout<<"\nTrong mang khong co phan tu nao lon hon " << x << endl;
	else {
		float *b = new float[n + 1];
		for(int i = 0; i < n; i++) b[i] = a[i];
		for(int i = n; i >= vt; i--)
		{
			b[i] = b[i - 1];
		}
		b[vt] = x;
		n++;
		delete a;
		a = b;
		cout<<"\nMang sau khi chen " << x << " la: " << endl;
		xuat(n,a);
	}
}

int main()
{
	int n;
	float *a,x;
	nhap(n,a);
	cout<<"\nMang vua nhap la: " << endl;
	xuat(n,a);
	char s[20] = "ABC2017.TXT";
	taofile(s,n,a);
	sapxep(n,a);
	cout<<"\nMang sau khi sap xep la: " << endl;
	xuat(n,a);
	ghifile(s,n,a);
	cout<<"\nSo phan tu  co gia tri bang voi gia tri phan tu nho nhat la: "<< dem(n,a) << endl; 
	nhapx(x);
	chen(n,a,x);
	delete a;
	return 0;
}
