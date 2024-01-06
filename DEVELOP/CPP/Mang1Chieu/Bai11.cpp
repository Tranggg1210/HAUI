#include<iostream>
using namespace std;

int a[100] , n = 0;
float x;

void nhapMang(int a[], int &n)
{
	int dem = 0;
	cout<<"Nhap mang cua ban: "<<endl;
	do{
		cout<<"Nhap a[" << n << "] = ";
		cin>>a[n];
		cout<<endl;
		if(a[n] == -1){
			n++;
			dem = 1;
			break;
		}
		n++;
	}while(n != 100);
	if(dem == 1) n --;
}

void hienThi(int a[], int n)
{
	for(int i = 0; i < n; i++)
	    cout<< a[i] << "\t";
}

void nhapx(float &x)
{
	cout<<"Nhap x: ";
	cin>>x;
}

void xuLy(int a[], int n, float x)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x) dem++;
	}
	if(dem == 0)
	{
		cout<<"So " << x << " khong xuat hien trong mang!"<<endl;
	}else{
		cout<<"So lan so " << x << " xuat hien trong mang la: "<< dem << endl;
		cout<<"Vi tri ma " << x << " xuat hien la: "<<endl;
		for(int i = 0; i < n; i++)
		{
			if(a[i] == x) cout<< i+1 << "\t";
		}
	}
}

int main()
{
	nhapMang(a,n);
	cout<<"So phan tu cua mang vua nhap la: "<< n << endl;
	cout<<"Mang A la: "<< endl;
	hienThi(a,n);
	cout<<endl;
	nhapx(x);
	xuLy(a,n,x);
	return 0;
}
