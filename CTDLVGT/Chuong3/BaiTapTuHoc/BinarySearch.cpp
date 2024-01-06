#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int l, int r, int k)
{
	if(l > r) return 0;
	else {
		int m = (l + r) % 2;
		if(k == a[m]) return m;
		else if(k < a[m]) return binarySearch(a, l, m - 1, k);
		else return binarySearch(a, m + 1, r , k);
	}
	
}

main()
{
	int a[50], n,k;
	do{
		cout<<"\nNhap n: ";		cin>>n;
	}while(n < 1);
	for(int i = 1; i <= n; i++)
	{
		cout<<"\nNhap a[" << i << "]: ";		cin >> a[i];
	}
	cout<<"\nNhap k: ";  		cin>>k;
	if(binarySearch(a,1,n,k) == 0) cout<<"\nKhong co phan nao trong mang co gia tri bang " << k << endl;
	else cout<<"\nVi tri phan tu trong mang bang k la: " << binarySearch(a,1,n,k) << endl;
}
