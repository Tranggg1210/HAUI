#include<iostream>
#include<fstream>
using namespace std;

class hhcn {
	private:
		float d, r, c;
	public:
		hhcn();
		hhcn(float a, float b, float c1);
		friend istream& operator>>(istream& in, hhcn &x);
		friend ostream& operator<<(ostream& out, hhcn x);
		bool operator+(hhcn c);
		bool operator++();
};

hhcn::hhcn() {
	d = 0;
	r = 0;
	c = 0;
}

hhcn::hhcn(float a, float b, float c1)
{
	d = a;
	r = b;
	c = c1;
}

istream& operator>>(istream& in, hhcn &x)
{
	cout<<"\nNhap chieu dai: ";					in>>x.d;
	cout<<"\nNhap chieu rong: ";				in>>x.r;
	cout<<"\nNhap chieu cao: ";					in>>x.c;
return in;
}

ostream& operator<<(ostream& out, hhcn x)
{
	out<<"\nChieu dai la: " << x.d;
	out<<"\nChieu rong la: " << x.r;
	out<<"\nChieu cao la: " << x.c;
return out;	
}

bool hhcn::operator+(hhcn c)
{
	float tt1, tt2;
	tt1 = r*d*c;
	tt2 = c.d * c.r * c.c;
	if(tt1 == tt2) return 
}

main()
{
	ofstream ghi("Bai3.txt");
	hhcn x,y;
	cout<<"\n============ NHAP THONG TIN HHCN X ============" <<endl;
	cin>>x;
	
	cout<<"\n============ NHAP THONG TIN HHCN Y ============" <<endl;
	cin>>y;
	
	ghi<<"\n============ THONG TIN HHCN X ============";
	ghi<<x;
	
	cout<<"\n============ THONG TIN HHCN X ============"<<endl;
	cout<<x;
	
	ghi<<"\n============ THONG TIN HHCN Y ============";
	ghi<<y;
	
	cout<<"\n============ THONG TIN HHCN Y ============"<<endl;
	cout<<y;
	
	
}
