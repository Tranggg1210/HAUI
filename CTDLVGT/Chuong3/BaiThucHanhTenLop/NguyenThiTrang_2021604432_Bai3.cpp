#include<bits/stdc++.h>
using namespace std;

void insertionSort(int *a,  int n)
{
	int x,y;
	for(int i = 1; i < n; i++)
	{
		x = i;
		y = a[i];
		while(x > 0 && a[x - 1] > y ) {
			a[x] = a[x - 1];
			x--;
		}
		a[x] = y;
		cout<<"\n\nMang sau lan duyet thu " << i << endl;
		for(int z = 0; z < n ; z++) cout<<a[z] << "\t";
	}
}

main()
{
	int n, *a;
	do{
		cout<<"\nNhap n > 0: ";						cin>>n;
	}while(n < 1);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNhap a[" << i << "]: ";			cin>>a[i];
	}
	cout<<"\nMang vua nhap la: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<a[i] << "\t";
	}
	insertionSort(a,n);
	delete[] a;
}
