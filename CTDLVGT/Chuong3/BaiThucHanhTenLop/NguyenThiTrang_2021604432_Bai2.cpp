#include<bits/stdc++.h>
using namespace std;

// Nguyen Thi Trang - 2021604432


void selectionSortTang(int *x, int n)
{
	for(int i = 0; i < n - 1 ; i++)
	{
		int m = i;
		for(int j = i + 1; j < n; j++)
			if(x[j] < x[m]) m = j;
		if(m != i) swap(x[i], x[m]);
		cout<<"\n\nMang tang sau lan duyet thu " << i << endl;
		for(int k = 0; k < n; k++) cout<< x[k] << "\t";
	}
}

void selectionSortGiam(int *x, int n)
{
	for(int i = 0; i < n - 1 ; i++)
	{
		int m = i;
		for(int j = i + 1; j < n; j++)
			if(x[j] > x[m]) m = j;
		if(m != i) swap(x[i], x[m]);
		cout<<"\n\nMang giam sau lan duyet thu " << i << endl;
		for(int k = 0; k < n; k++) cout<< x[k] << "\t";
	}
}

main()
{
	int n, *x;
	do{
		cout<<"\nNhap n > 0: ";					cin>>n;
	}while(n < 1);
	
	x = new int[n];
	
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNhap x[" << i << "]: ";		cin>>x[i];
	}
	cout<<"\nMang vua nhap la: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<x[i] << "\t";
	}
	
	cout<<"\n\n";
	selectionSortTang(x,n);
	
	cout<<"\n\n";
	selectionSortGiam(x,n);
	delete[] x;
}
