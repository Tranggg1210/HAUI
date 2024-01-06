#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void nhap(int &n, float *&a)
{
	do{
		cout<<"Nhap so phan tu n > 0 cua mang: ";
		cin>>n;
	}while(n <= 0);
	a = new float[n];
	cout<<"------NHAP MANG------"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "] = ";
		cin>>a[i];
	}
}

void ghi(char *k, float *a, int n)
{
	ofstream f(k, ios::out);
	f << n <<endl;
	for(int i; i < n; i++)
	{
		f << a[i] <<"\t";
	}
	f<<endl;
	for(int i = 0; i < n; i++)
	{
		
		if(i == n-1)
		{
			if(a[i] < 0) f << fabs(a[i])<< " x" << i;
			else f << a[i] << " x" << i;
		}else{
			if(a[i] < 0)
	    	{
	    		f << fabs(a[i])<< " x" << i << " + ";
	    	}else f << a[i]<< " x" << i << " + ";
		}
	}
	f.close();
}

void doc(char *k)
{
	cout<< "--------FILE la: --------"<<endl;
	ifstream f(k, ios::in);
	char s[255];
	while(! f.eof())
	{
		f.getline(s,255);
		cout<< s << endl;
	}
	f.close();
}

int main()
{
	int n;
	float *a;
	nhap(n,a);
	char k[255];
	cout<<"Nhap ten file: ";
	fflush(stdin);
	gets(k);
	ghi(k,a,n);
	doc(k);
	delete a;
	return 0;
}
