#include<bits/stdc++.h>
using namespace std;
//
//float acker(float m, float n)
//{
//	if(m == 0) return (n+1);
//	if(n == 0) return acker(m-1,1);
//	return acker(m-1, acker(m,n-1));
//}
//
//main()
//{
//	cout<<"\nGia tri cua acker(1,2) = " << acker(1,2);
//}



//#define PI 3.14
//
//double F(float x) {
//    if (x < 0) return x;
//    if (x == 0) return 1;
//    return F(x - 3.14) + F(x - 1.57);
//}
//
//main()
//{
//	cout<<"\nGia tri cua bieu thuc can tinh la: " << F(4.71);
//}



//int UCLN (int p, int q)
//{
//	while(p > q)
//	{
//		int r = p % q;
//		if(r==0) return q;
//		p = q; 
//		q = r;
//	}
//	return 0;
//}
//main()
//{
//	cout<<"\nUCLN (9,6): "	<< UCLN(9,5);
//}


//string reverse(string str) {
//    if (str.length() == 0) {
//        return str;
//    }
//    else {
//        return reverse(str.substr(1)) + str[0];
//    }
//}
//
//int main() {
//    string str = "PASCAL";
//    string reversed_str = reverse(str);
//    cout << reversed_str << endl; 
//    return 0;
//}

//int count(int n, int dem)
//{
//	if(n <= 0)	return dem;
//	else {
//		dem++;
//		return count(n / 10, dem);
//	}
//}
//
//main()
//{
//	cout<<"\nSo chi so nguyen duong cua 123456: " << count(1,0);
//}

void selectionSort(int x[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		
		for(int j = i + 1; j < n-i-1; j++)
		{
			if(x[j] > x[j+1]) 
		}
		if(m != i)
		{
			int tg = x[i];
			x[i] = x[m];
			x[m] = tg;
		}	
	}	
}

main()
{
	int x[5] = {8, 12,4,23,16};
	selectionSort(x,5);
	for(int i = 0; i < 5; i++)
	{
		cout<<x[i] << "\t";
	}
}


