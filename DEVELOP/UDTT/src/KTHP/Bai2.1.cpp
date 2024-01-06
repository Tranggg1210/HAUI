#include<bits/stdc++.h>
using namespace std;

void hienThiMang(int n, int a[]){
	cout<<"--------------- MANG VUA KHOI TAO ---------------"<< endl;
	for(int i = 0; i < n; i++)
		cout<<a[i] << "\t";
	cout<< endl;
}

long sum(int n, int a[])
{
	if(n == -1) return 0;
	if(a[n] % 2 != 0)
		return a[n] + sum(n-1,a);
	return sum(n-1,a);  
}

void ketQua(int n, int a[])
{
	cout<<"Tong cac phan tu le trong mang la: " << sum(n-1,a) <<endl;
	cout<<"--------------- CAC PHAN TU LE TRONG MANG ---------------"<< endl;
	for(int i = 0; i < n; i++)
		if(a[i] % 2 != 0)
			cout<<a[i] << "\t";
	cout<< endl;
}

int main()
{
	// khoi tao
	int n = 12;
	int a[n] = {1,5,9,15,6,10,8,2,18,10,16,12};
	
	// hien thi mang
	hienThiMang(n,a);
	
	// ket qua
	ketQua(n,a);
	
	
	return 0;
}
