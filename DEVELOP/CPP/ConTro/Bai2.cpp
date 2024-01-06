#include<iostream>
using namespace std;

void nhap(int &n, int* &a)
{
	do{
		cout<<"Nhap n > 0: ";
		cin>>n;
	}while(n <= 0);
	a = new int[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap a[" << i << "]: ";
		cin>> *(a+i);
	}
}


void hienThi(int n, int *a)
{
	for(int i = 0; i < n; i++)
	{
		cout<< *(a + i) << "\t";
	}
	cout<<endl;
}

void tim(int n, int *a)
{
	int max = 0, dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(*(a + i) % 2 == 0)
		{
			max = *(a + i);
			dem = 1;
		}
	}
	if(dem == 1)
	{
		for(int i = 0; i < n; i++)
	    {
		    if(*(a + i) % 2 == 0)
		    {
		    	if(max < *(a + 1)) max = *(a + i);
		    }
	    }
		cout<<"So chan lon nhat trong mang a la: "<< max << endl;
	}
}

void sapxep(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(*(a + i) < *(a + j))
			{
				int tg = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = tg;
			}
		}
	}
}

int main()
{
	int n,*a;
	nhap(n,a);
	cout<<"Mang vua nhap la: "<< endl;
	hienThi(n,a);
	tim(n,a);
	cout<<"Mang sau khi sap xep la: "<< endl;
	sapxep(a,n);
	hienThi(n,a);
	delete a;
	return 0;
}
