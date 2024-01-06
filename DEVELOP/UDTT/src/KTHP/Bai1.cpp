#include<bits/stdc++.h>
using namespace std;

double sum(float a[], int l, int r)
{
	double sum1 = 0;
	if(l == r) return (sum1 + a[l]);
	else{
		int m = (l+r)/2;
		return sum(a,l,m) + sum(a, m+ 1, r);
	}
}

double sum2(float a[], int n)
{
	double sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum+= a[i];
	}
	return sum;
}

int main()
{
	int n = 12;
	float a[n] = {5.1, 10, 6.9, 9, 9.1, 8.2, 9.4,7.6,9.9,10.1,11.2,12.9};
	cout<<"\nTong cua mang a la: " << fixed << setprecision(2) << sum(a,0,n-1);
	cout<<"\nTong voi vong for la: " << sum2(a,n);
	return 0;
}
