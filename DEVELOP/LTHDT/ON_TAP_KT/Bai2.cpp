#include<bits/stdc++.h>
using namespace std;

class SP {
	private:
		float t,a;
	public:
		SP();
		SP(float x, float y);
	friend istream& operator>>(istream& in, SP &x);
	friend ostream& operator<<(ostream& out, SP x);
	SP operator+(SP x);
	SP operator-(SP x);
};

SP::SP() {
	a = 0;
	t = 0;
}

SP::SP(float x, float y)
{
	t = x;
	a = y;
}

istream& operator>>(istream& in, SP &x)
{
	cout<<"\n==== NHAP THONG TIN SO PHUC ====" << endl;
	cout<<"\nNhap phan thuc: ";										in>>x.t;
	cout<<"\nNhap phan ao: ";										in>>x.a;
return in;
}


ostream& operator<<(ostream& out, SP x) 
{
	if(x.a  < 0) out<< x.t << " - i*" << -x.a ;
	else out<< x.t << " + i*" << x.a ;
return out;
}

SP SP::operator+(SP x)
{
	SP k;
	k.t = t + x.t;
	k.a = a + x.a;
return k;
}

SP SP::operator-(SP x)
{
	SP k;
	k.t = t - x.t;
	k.a = a - x.a;
return k;
}

main()
{
	SP SP1, SP2;
	cin>>SP1;
	cin>>SP2;
	cout<<"\nSo phuc SP1 la: " << SP1;
	cout<<"\nSo phuc SP2 la: " << SP2;
	
	SP SP3 = SP1 + SP2;
	cout<<"\nTong hai so phuc SP1 va SP2 la SP3 = " << SP3;
	
	SP SP4 = SP1 - SP2;
	cout<<"\nHieu hai so phuc SP1 va SP2 la SP3 = " << SP4;
	
	// ghi 
	ofstream ghi("Bai2.txt");
	ghi<<"\nSo phuc SP1 la: " << SP1;
	ghi<<"\nSo phuc SP2 la: " << SP2;
	ghi<<"\nTong hai so phuc SP1 va SP2 la SP3 = " << SP3;
	ghi<<"\nHieu hai so phuc SP1 va SP2 la SP3 = " << SP4;
	
	ghi.close();
}
