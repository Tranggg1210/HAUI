#include<bits/stdc++.h>
using namespace std;

void hienThiMang(int n, double a[])
{
	cout<<"----------------- MANG VUA KHOI TAO -----------------"<<endl;
	for(int i = 0; i < n; i++)
		cout<< a[i] << "\t";
	cout<< endl;
}

// chia de tri
double sum(double a[], int l, int r)
{
	if(l == r) return (a[l] > 0 ? a[l] : 0);
	else{
		int m = (l+r)/2;
		return sum(a,l,m) + sum(a,m+1,r);
	}
}

// ket qua
void ketQua(int n, double a[])
{
	cout<< "Tong cac so duong trong mang la: " << sum(a,0,n-1);
}

int main()
{
	// khoi tao 
	int n = 12;
	double a[n] = {-1.1,2.3,3.4,-2,6,9,10,-2.3,2.6,9.9,-11,12.10};
	
	// hien thi mang
	hienThiMang(n,a);
	
	//ketQua
	ketQua(n,a);
	return 0;
}
