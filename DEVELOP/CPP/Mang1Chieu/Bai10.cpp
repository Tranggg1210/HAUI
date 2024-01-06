#include<iostream>
using namespace std;

int a[100] , n = 0;

void nhapMang(int a[], int &n)
{
	int dem = 0;
	cout<<"Nhap mang cua ban: "<<endl;
	do{
		cout<<"Nhap a[" << n << "] = ";
		cin>>a[n];
		cout<<endl;
		if(a[n] == -1){
			n++;
			dem = 1;
			break;
		}
		n++;
	}while(n != 100);
	if(dem == 1) n --;
}

void hienThi(int a[], int n)
{
	for(int i = 0; i < n; i++)
	    cout<< a[i] << "\t";
}
void sapXep(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
	    for(int j = i + 1; j < n; j++)
	    {
	    	if(a[i] < a[j])
	    	{
	    		int tg = a[i];
	    		a[i] = a[j];
	    		a[j] = tg;
			}
		}
}

int main()
{
	nhapMang(a,n);
	cout<<"So phan tu cua mang vua nhap la: "<< n << endl;
	cout<<"Mang A la: "<< endl;
	hienThi(a,n);
	cout<<endl;
	cout<<"Mang A sau khi sap xep giam dan la: "<< endl;
	sapXep(a,n);
	hienThi(a,n);
	return 0;
}
