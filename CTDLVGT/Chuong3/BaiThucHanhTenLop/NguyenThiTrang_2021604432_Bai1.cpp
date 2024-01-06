#include<bits/stdc++.h>
using namespace std;

// Nguyen Thi Trang - 2021604432

void bubbleSort(int *a, int n)
{
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n - i; j++){
			if(a[j] > a[j+1]) swap(a[j],a[j+1]);
			cout<<"\n\nMang sau lan duyet thu " << i << " voi j = " << j << endl;
			for(int x = 0; x < n; x++) cout<< a[x] << "\t";
		}	
	}
}

main()
{
	int n, *a;
	do{
		cout<<"\nNhap n > 0: ";					cin>>n;
	}while(n < 1);
	
	a = new int[n];
	
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNhap a[" << i << "]: ";		cin>>a[i];
	}
	cout<<"\nMang vua nhap la: " << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<a[i] << "\t";
	}
	
	cout<<"\n\n";
	bubbleSort(a,n);
	delete[] a;
}
