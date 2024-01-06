#include<iostream>
using namespace std;

void nhap(int &n, int *&a)
{
	do{
		cout<<"Nhap n > 0: ";
		cin>>n;
	}while(n <= 0);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "]: ";
		cin>>a[i];
	}
}

void sapxeptang(int n, int *a)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
}

void xuat(int n, int *a)
{
	for(int i = 0; i < n; i++)
	{
		cout<< a[i] << "\t";
	}
}


int dem(int n, int *a)
{
	int dem1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] >= 10 && a[i] <= 20) dem1++;
	}
	return dem1;
}

bool sclt(int n, int *a)
{
	if(n < 2) return false;
	for(int i = 0; i < n; i++)
	{
		if((a[i] % 2 == 0) && (a[i + 1] % 2 == 0) && (a[i + 2] % 2 == 0)) return true;
	}
	return false;
}

int main()
{
	int n, *a;
	nhap(n,a);
	sapxeptang(n,a);
	cout<<"Mang sau khi sap xep tang dan la: "<<endl;
	xuat(n,a);
	if(dem(n,a) == 0) cout<<"\nKhong co phan tu nao trong mang thuoc [10,20]"<<endl;
	else cout<<"\nSo luong phan tu trong mang thuoc [10,20] la: "<< dem(n,a) << endl;
	if(sclt(n,a)) cout<<"Trong mang co ba so chan lien tiep!"<< endl;
	else cout<<"Trong mang khong co ba so chan lien tiep" << endl;
	delete a;
	return 0;
}
