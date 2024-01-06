#include<iostream>
using namespace std;

void nhap(int &n, int &m, float **&a)
{
	do{
		cout<<"Nhap so dong n > 0: ";
		cin >> n;
	}while(n <= 0);
	do{
		cout<<"Nhap so cot m > 0: ";
		cin>>m;
	}while(m <= 0);
	a = new float*[n];
	for(int i = 0; i < n; i++)
	{
		a[i] = new float[m];
	}
	cout<<"Nhap ma tran cua ban: "<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<<"Nhap a[" << i << "][" << j << "]: ";
			cin>>a[i][j];
		}
	}
}

void xuat(int n, int m, float **a)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<< a[i][j] << "\t";
		}
		cout<<endl;
	}
}

void maxdong_mincot(int n, int m, float **a)
{
	for(int i = 0; i < n; i++)
	{
		int max = a[i][0];
		int min = a[0][i];
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] > max) max = a[i][j];
			if(a[j][i] < min) min = a[j][i];
		}
		cout<< "Gia tri lon nhat tren dong thu " 
		    << i << " la: "<< max <<endl;
		if(i < m)
		{
			cout<< "Gia tri nho nhat tren cot thu " 
		        << i << " la: "<< min <<endl;
		}
	}
}

void mtchuyenvi(int n, int m, float **&a, float **&b)
{
	b = new float*[m];
	for(int i = 0; i < m; i++)
	{
		b[i] = new float[n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			b[j][i] = a[i][j];
			a[i][j] *= (-1);
		}
	}
}

int dem(int n, int m, float **a)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] > 0) dem++;
		}
	}
	return dem;
}

int main()
{
	int n,m;
	float **a, **b;
	nhap(n,m,a);
	cout<<"Ma tran vua nhap la: "<<endl;
	xuat(n,m,a);
	maxdong_mincot(n,m,a);
	mtchuyenvi(n,m,a,b);
	cout<<"\nMa tra chuyen vi B cua ma tran chuyen vi A la: "<<endl;
	xuat(m,n,b);
	cout<<"\nMa tran A sau khi doi dau la: "<<endl;
	xuat(n,m,a);
	if(dem(n,m,a) == 0) cout<<"\nMa tran A khong co phan tu duong!"<<endl;
	else cout<<"\nSo phan tu duong cua ma tran A la: "<< dem(n,m,a) << endl;
	delete []a;
	delete []b;
	return 0;
}
