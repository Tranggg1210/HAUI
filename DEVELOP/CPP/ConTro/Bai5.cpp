#include<iostream>
#include<string.h>
using namespace std;

void nhap(int &n, char *&a)
{
	do{
		cout<<"Nhap so luong ky tu trong chuoi: ";
		cin>>n;
	}while(n <= 0 || n > 80);
	fflush(stdin);
	a = new char[n];
	do{
		cout<<"Nhap chuoi khong rong: ";
		gets(a);
	}while(strcmp(a,"") == 0 || strlen(a) > n);
	fflush(stdin);
}




int main()
{
	int n;
	char *a;
	nhap(n,a);
	cout<<"Chuoi vua nhap la: "<<a << endl;
	cout<<"Do dai cua chuoi la: "<<strlen(a);
	return 0;
}
