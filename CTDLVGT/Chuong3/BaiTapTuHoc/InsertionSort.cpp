#include<iostream>
using namespace std;

void insertionSort(int x[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int tam = x[i];
		int j = i - 1;
		while(j > -1 && x[j] > tam)
		{
			x[j+1] = x[j];
			j--;
		}
		x[j+1] = tam;
		cout<<"\nMang sau lan thu thu " << i << endl;
		for(int k = 0; k < n; k++) cout<<x[k] << "\t";
	}
}


main()
{
	int n, x[50];
	cout<<"\nNhap n: ";			cin>>n;
	for(int i = 0; i < n; i++) 	cin>>x[i];	
	insertionSort(x,n);
	
}
