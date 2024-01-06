#include<bits/stdc++.h>
using namespace std;

int UCLN(int a, int b)
{
	if(b == 0) return a;
	if(a % b == 0) return b;
	return UCLN(b, a%b);
}

main()
{
	int a, b;
	cout<<"\nNhap a: "; 		cin>>a;
	cout<<"\nNhap b: ";			cin>>b;
	cout<<"\nUCLN("<< a <<","<< b <<") = " << UCLN(a,b);
}
