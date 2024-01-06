#include<bits/stdc++.h>
using namespace std;

void selectionSort(int x[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int m = i;
		for(int j = i + 1; j < n; j++)
		{
			if(x[j] < x[m] ) m = j;
		}
		if(m != i)
		{
			swap(x[i], x[m]);
		}
//		swap(x[i], x[m]);
	}
}

main()
{
	int n = 7;
	int x[n] = {1,2,47,6,55,9,3};
	selectionSort(x,n);
	for(int i = 0; i < n; i++)
	{
		cout<< x[i] <<"\t";
	}
}
