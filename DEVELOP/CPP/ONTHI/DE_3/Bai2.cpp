#include<iostream>
#include<fstream>
using namespace std;

void nhap(int &n, int *&a)
{
	do{
		cout<<"Nhap n > 0: ";
		cin >> n;
	}while(n <= 0);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void xuat(int n, int *a)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}

void taofile(char *s, int n, int *a)
{
	ofstream f(s,ios::out);
	for(int i = 0 ; i < n; i++)
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
			if(a[i] > a[j] ) swap(a[i], a[j]);
		}
	}
}

void tachmang(int n, int *a)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 != 0) dem++;
	}
	if(dem == 0){
		cout<< "\nTrong mang A khong co phan tu le!"<< endl;
		cout<<"\nMang C la: " << endl;
		xuat(n,a);
	}else{
		if(dem == n) 
		{
			cout<< "\nTrong mang A toan phan tu chan" << endl;
	    	cout<<"\nMang B la: " << endl;
	    	xuat(n,a);
		}else{
			int *b = new int[dem];
			int *c = new int[n - dem];
			int t = 0, p = 0;
			for(int i = 0; i < n; i++)
			{
				if(a[i] % 2 != 0)
				{
					b[t++] = a[i]; 
				}else{
					c[p++] = a[i];
				}
			}
			cout<< "\nMang B la: "<<endl;
			xuat(t,b);
			cout<< "\nMang C la: "<<endl;
			xuat(p,c);
			delete b;
			delete c;
		}
	}
}

bool kthople(int n, int *a)
{
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] %2 == 0) dem++;
	}
	if(dem == n)
	{
		for(int i = 0; i < n; i++)
		{
			if(a[i] == a[i+1]) return false;
		}
	}else return false;
	return true;
}

int main()
{
	int n, *a;
	nhap(n,a);
	cout<<"\nMang vua nhap la: " << endl;
	xuat(n,a);
	char s[20] = "ABC2007.TXT";
	taofile(s,n,a);
	sapxep(n,a);
	cout<<"\nMang vua sap xep la:" << endl;
	xuat(n,a);
	char s1[20] = "XYZ2007.TXT";
	taofile(s1,n,a);
	tachmang(n,a);
	if(kthople(n,a)) cout<< "\nMang tren hop le"<<endl;
	else cout<< "\nMang tren khong hop le"<<endl;
	delete a;
	return 0;
}
