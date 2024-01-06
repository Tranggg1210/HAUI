#include<iostream>
using namespace std;

void selectionSort(int x[], int n)
{ 
	for(int i = 0; i < n - 1; i++)
	{
		int m = i;
		for(int j = i + 1; j < n; j++)
		{
			if(x[j] < x[m]) m = j;
		}
		if(m!=i) swap(x[i],x[m]);
		cout<<"\nMang sau lan duyet thu " << i << endl;
		for(int k = 0; k < n; k++) cout<< x[k] << "\t";
	}
}

main()
{
	int n, x[50];
	cout<<"\nNhap n: ";			cin>>n;
	for(int i = 0; i < n; i++) 	cin>>x[i];	
	selectionSort(x,n);
	
}
