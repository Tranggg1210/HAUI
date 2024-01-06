#include<bits/stdc++.h>
using namespace std;

// insertion_sort
void insertion_sort(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int j = i;
		int last = a[i];
		while(j > 0 && a[j - 1] > last)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = last;
	}
}

int main()
{
	int a[5] = {6,5,8,9,10};
	insertion_sort(a, 5);
	for(int i = 0; i < 5; i++)
		cout << a[i] << "\t";
	return 0;
}
