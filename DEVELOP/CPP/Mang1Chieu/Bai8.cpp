#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[100];

void nhap(int &n)
{
	do{
		cout<<"Nhap n: "<<endl;
	    cin>>n;
	}while( n < 1 || n > 30);
}

void nhapMang(int a[], int n)
{
	cout<<"Nhap mang cua ban";
	int i;
	for(i = 0; i < n; i++)
	{
		cout<<endl;
		cout<<"Nhap a[" << i << "] = ";
		cin>>a[i]; 
	}
}

bool snt(int k)
{
	if(k < 2) return false;
	for(int i = 2; i <= sqrt(k); i++)
	{
		if(k % i == 0) return false;
	}  
	return true;
}

void hienThi(int a[], int n)
{
	int i, dem = 0, s = 0;
	for(i = 0; i < n; i++)
	{
		if( snt(a[i]) )
		{
			s += a[i];
			dem++;
		}
	}
	if(dem == 0)
	{
		cout<<"Khong co phan tu nao trong mang la so nguyen to!" << endl;
	}else{
		cout<<"So phan tu trong mang la so nguyen to la: " << dem << endl;
		cout<<"Cac phan tu trong mang la so nguyen to la: "<<endl;
		for(i = 0; i < n; i++)
	    {
	    	if( snt(a[i]) )
		    {
		    	cout<< a[i] << "\t";
		    }
	    }
	    cout<<endl;
	    cout<<"Tong cac phan tu trong mang la: " << s << endl;
	}
}

int main()
{
	nhap(n);
	nhapMang(a,n);
	hienThi(a,n);
	return 0;
}
