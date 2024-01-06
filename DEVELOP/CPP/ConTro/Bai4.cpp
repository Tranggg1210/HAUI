#include<iostream>
#include<cmath>
using namespace std;

void nhap(int &n, float *&a)
{
	do{
		cout<< "Nhap 1 <= n <= 20: ";
		cin>>n;
	}while(n < 1 || n > 20);
	a = new float[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void timso(int n, float *a)
{
	int min, dem = 0, dem1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0)
		{
			min = a[i];
			dem = 1;
		}else dem1 = 1;
	}
	if(dem == 1)
	{
		for(int i = 0; i < n; i++)
		{
			if(a[i] > 0)
			{
				if(min > a[i]) min = a[i];
			}
		}
		if(dem1 == 1)
		{
			cout<< "Cac so am co tri tuyet doi lon hon so duong nho nhat va vi tri cua chung la: "<<endl;
			for(int i = 0; i < n; i++)
			{
				if(fabs(a[i]) > min && a[i] < 0)
				{
					cout<< "So " << a[i] << " co vi tri: " << i + 1 << endl;
				}
			}
		}else cout<< "Trong mang khong co phan tu am" << endl;
	}else cout<< "Trong mang khong co phan tu duong" << endl;
}

void xuat(int n, float *a)
{
	for(int i = 0; i < n; i++)
	{
		cout<< a[i] << "\t";
	}
	cout<<endl;
}

void nhapk(int &k, int n)
{
	do{
		cout<< "Nhap vi tri thu k can xoa: ";
		cin>>k;
	}while(k < 0 || k > n);
}

void xoa(int &n, float *&a, int k)
{
	int t = 0;
	float *b = new float[n-1];
	for(int i = 0; i < n; i++)
	{
		if(i == k)
		{
			continue;
		}
		b[t++] = a[i];
	}
	n--;
	delete a;
	a = b;
}

void nhapm(int &m, int n, float &h)
{
	do{
		cout<< "Nhap vi tri thu m can chen: ";
		cin>>m;
	}while(m < 0 || m > n);
	cout<<"Nhap gia tri muon chen: ";
	cin>>h;
}

void chen(int &n, int m, float *&a, float h)
{
	float *b = new float[n + 1];
	for(int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	delete a;
	for(int i = n; i >= m; i--)
	{
		b[i+1] = b[i];
	}
	b[m] = h;
	n++;
	a = b;
}

void sapxep(int n, float *a)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i] > a[j])
			{
				float tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}

int main()
{
	int n,k,m;
	float *a,h;
	nhap(n,a);
	cout<<"Mang vua nhap la: "<< endl;
	xuat(n,a);
	timso(n,a);
	nhapk(k,n);
	cout<<"Mang sau khi xoa phan tu thu " << k << " ra khoi mang la: "<< endl;
	xoa(n,a,k);
	xuat(n,a);
	nhapm(m,n,h);
	chen(n,m,a,h);
	cout<<"Mang sau khi chen la: "<< endl;
	xuat(n,a);
	sapxep(n,a);
	cout<<"Mang sau khi sap xep giam dan la: "<<endl;
	xuat(n,a);
	delete a;
	return 0;
}
