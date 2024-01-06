#include<bits/stdc++.h>
using namespace std;

int n, x[100],k;

void show()
{
	for(int i = 1; i <= k ; i++)
		cout<< x[i] << " ";
	cout<< endl;
}


void Try(int i)
{
	for(int j = x[i-1] + 1; j <= n - k + i; j++)
	{
		x[i] = j;
		if(i == k)
		{
			show();
		}else Try(i+1);
	}
}

int main()
{
	cin>>n>>k;
	memset(x,0,sizeof(x));
	Try(1);
	return 0;
}
