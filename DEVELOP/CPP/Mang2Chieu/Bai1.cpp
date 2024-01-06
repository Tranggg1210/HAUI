#include<iostream>
using namespace std;

int m,n;
int a[15][16];

void nhap(int &m, int &n)
{
	do{
		cout<<"Nhap so dong m: " << endl;
		cin>>m;
	}while( m < 3 || m > 15);
	do{
		cout<<"Nhap so cot n: " << endl;
		cin>>n;
	}while( n < 1 || n > 15);
}

void matranxoanoc(int m, int n, int a[][16])
{
	int gt = 1, i;
	int h1 = 0, h2 = m - 1;
	int c1 = 0, c2 = n - 1;
	while(h1 <= h2 && c1 <= c2)
	{
		//xay dung dong tren
		for( i = c1 ; i <= c2; i++)
		{
			a[h1][i] = gt++;
		}
		//xay dung canh phai
		++h1;
		for(i = h1; i <= h2; i++)
		{
			a[i][c2] = gt++;
		}
		--c2;
		if(c1 <= c2)
		{
			for(i = c2 ; i >= c1; i--)
			{
				a[h2][i] = gt++;
			}
			--h2;
		}
		if(h1 <= h2)
		{
			for(i = h2 ; i >= h1; i--)
			{
				a[i][c1] = gt++;
			}
			++c1;
		}
	}
}

void inMaTran(int a[][16], int m, int n)
{
	cout<<"Ma tran xoan oc la: "<<endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<< a[i][j] <<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	nhap(m,n);
	matranxoanoc(m,n,a);
	inMaTran(a,m,n);
	return 0;
}
