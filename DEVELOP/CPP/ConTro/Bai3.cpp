#include<iostream>
using namespace std;

void nhap(int &m, int &n, int **&b)
{
	do{
		cout<<"Nhap vao so dong m: ";
		cin>> m ;
	}while(m <= 0);
	do{
		cout<<"Nhap vao so cot n: ";
		cin>> n ;
	}while(n <= 0);
	cout<<"Nhap mang: "<<endl;
	b = new int *[m];
	for(int i = 0; i < m; i++)
	{
		b[i] = new int[n];
	}
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
		    cin >>*(*(b + i) + j);
		}
	}
}

void xuat(int m, int n, int **b)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<< *(*(b + i) + j) << "\t";
		}
		cout<<endl;
	}
}

int tongdongdau(int m, int n, int **b)
{
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += *(*b + i);
	}
	return s;
}

void maxsoam(int m, int n, int **b)
{
	int max, dem = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if( *(*(b + i) + j) < 0)
			{
				max = *(*(b + i) + j);
				dem = 1;
				break;
			}
		}
	}
	if(dem == 1)
	{
		for(int i = 0; i < m; i++)
    	{
	    	for(int j = 0; j < n; j++)
	    	{
	    		if( *(*(b + i) + j) < 0)
	    		{
	    			if( *(*(b + i) + j) > max)
	                {
			        	max = *(*(b + i) + j);
			        }
		    	}
		    }
	    }
	    cout<< "Gia tri am lon nhat trong ma tran la: "<< max << endl;
	}else{
		cout<< "Ma tran khong co gia tri am"<< endl;
	}
}

void mtchuyenvi(int m, int n, int **&b)
{
	int t = 0,k;
	int **a;
	a = new int *[n];
	for(int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for(int i = 0; i < n; i++)
	{
		k = 0;
		for(int j = 0; j < m; j++)
		{
			a[t][k] = b[j][i];
			k++;
		}
		t++;
	}
	delete b;
	b = a;
	cout<<"Ma tran chuyen vi cua ma tran a la: "<< endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout<< b[i][j] << "\t";
		}
		cout<<endl;
	}
}

int main()
{
	int m,n, **b;
	nhap(m,n,b);
	cout<<"Ma tran vua nhap la: "<<endl;
	xuat(m,n,b);
	cout<<"Tong dong dau cua ma tran B la: "<< tongdongdau(m,n,b) <<endl;
	maxsoam(m,n,b);
	mtchuyenvi(m,n,b);
	delete []b;
	return 0;
}
