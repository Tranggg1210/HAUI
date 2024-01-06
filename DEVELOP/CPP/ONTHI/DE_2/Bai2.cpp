#include<iostream>
#include<fstream>
using namespace std;

void nhap(int &n, float *&a)
{
	do{
		cout<<"Nhap n > 0: " ;
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
			if(a[i] < a[j]) swap(a[i], a[j]);
		}
	}
}

void ghifile(char *s , int n, float *a)
{
	ofstream f(s, ios::app);
	f << endl;
	for(int i = 0; i < n; i++)
	{
		f << a[i] << "\t";
	}
	f.close();
}

void tim(int n, float *a)
{
	float min = -1;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0 )
		{
			min = a[i];
			break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] > 0 && a[i] < min )
		{
			min = a[i];
		}
	}
	if(min == -1) cout<< "\nDay khong co phan tu duong nao" << endl;
	else cout<< "\nPhan tu duong nho nhat trong mang la: " << min;
}

bool kthople(int n, float *a)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] < 0) dem++;
	}
	if(dem == n) return false;
	else{
		if(dem == 0){
			for(int i = 0 ; i < n -1; i++)
			{
				if(a[i] + a[i+1] < 5) return false;
			}
		}else return false;
	}
	return true;
}

int main()
{
	int n;
	float *a;
	nhap(n,a);
	cout<<"\nMang vua nhap la: "<< endl;
	xuat(n,a);
	char s[20] = "ABC2018.TXT";
	taofile(s,n,a);
	sapxep(n,a);
	cout<<"\nMang sau khi sap xep la: " << endl;
	xuat(n,a);
	ghifile(s,n,a);
	tim(n,a);
	if(kthople(n,a)) cout<< "\nMang tren hop le" << endl;
	else cout<< "\nMang tren khong hop le" << endl;
	delete a;
	return 0;
}
