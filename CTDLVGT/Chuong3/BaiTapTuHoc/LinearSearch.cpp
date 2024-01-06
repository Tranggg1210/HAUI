// Bài toán: Cho truoc dãy a1,a2,... an và giá tri K.  Can tìm chi so I sao cho a1 = K, neu không tìm thay thi tr ve -1.
// Ý tuong: Lan luot kiem tra tung phan tu, neu den cuoi day van khong tim thay thi thong bao ket qua la -1;

#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int k, int n)
{
	int i = 1;
	while(i <= n && a[i] != k) i++;
	if(i <= n) return i;
	else return 0;
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
	if(linearSearch(a,k,n) == 0)
		cout<<"\nKhong co phan tu nao trong mang co gia tri bang " << k << endl;
	else cout<<"\nVi tri phan tu trong mang bang k la: " << linearSearch(a,k,n) << endl;
}
