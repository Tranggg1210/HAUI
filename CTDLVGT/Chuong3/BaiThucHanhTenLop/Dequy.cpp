#include<bits/stdc++.h>
using namespace std;

//float F(float m, float n)
//{
//	if(n <= 0) return (m+1);
//	if(m <= 0)  return (n+1);
//	return (F(m-1,n) + F(m, n-1) );
//}

float F(int n)
{
	if(n <= 0) return 0;
	return (2*n + F(n - 1));
}

main()
{
	cout<<"\nGia tri bieu thuc F(5): " << F(5);
}
