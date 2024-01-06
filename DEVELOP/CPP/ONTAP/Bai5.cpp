#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void taofile(char *s)
{
	ofstream f(s, ios::out);
	int n,t;
	do{
		cout<<"Nhap so n > 0: ";
		cin >> n;
	}while(n <= 0);
	f << n << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "]: ";
		cin >> t;
		f << t << "\t";
	}
	f.close();
}

void taomang(char *s, int &n, int *&a)
{
	ifstream f(s, ios::in);
	char k[255];
	f >> k;
	n = atoi(k);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		f >> k;
		a[i] = atoi(k);
	}
	f.close();
}

void sapxep(int n, int *a)
{
	for(int i = 0; i < n - 1 ; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
	}
}

void ghifile(char *s, int n, int *a)
{
	ofstream f( s, ios::app);
	f << endl;
	for(int i = 0; i < n; i++)
	{
		f << a[i] << "\t";
	}
	f.close();
}

void ghiflie_sort(char *s, int n, int *a)
{
	ofstream f(s, ios::out);
	f << n << endl;
	for(int i = 0; i < n; i++)
	{
		f << a[i] << "\t";
	}
	f.close();
}

void docfile(char *s)
{
	ifstream f(s, ios::in);
	char m[255];
	while(!f.eof())
	{
		f.getline(m,255);
		cout<< m << endl;
	}
	f.close();
}

int main()
{
	char s[255] = "FILE.txt";
	taofile(s);
	int n, *a;
	taomang(s,n,a);
	sapxep(n,a);
	ghifile(s,n,a);
	cout<< "FILE.txt la: " << endl;
	docfile(s);
	char m[100] = "SORTED_FILE.txt";
	ghiflie_sort(m,n,a);
	cout<< "SORTED_FILE.txt la: " << endl;
	docfile(m);
	delete a;
	return 0;
}
