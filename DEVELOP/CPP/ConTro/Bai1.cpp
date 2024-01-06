#include<iostream>
using namespace std;


void nhap(int *a, float *x)
{
	cout<<"Nhap a: ";
	cin>>*a;
	cout<<endl;
	cout<<"Nhap x: ";
	cin>>*x;
	cout<<endl;
}

void hienThi(int *a, float *x)
{
	cout<<"Dia chi cua bien a la: "<< a << endl;
	cout<<"Dia chi cua bien x la: "<< x << endl;
	cout<<"Gia tri cua bien a la: "<< *a << endl;
	cout<<"Gia tri cua bien x la: "<< *x << endl;
}

void hienThi1(int a, float x)
{
	cout<<"Gia tri cua bien a khong thong con tro la: "<< a << endl;
	cout<<"Gia tri cua bien x khong thong con tro la: "<< x << endl;
}

int main()
{
	int a;
    float x;  
	nhap(&a,&x);
	hienThi(&a,&x);
	hienThi1(a,x);
	return 0;
}
	
