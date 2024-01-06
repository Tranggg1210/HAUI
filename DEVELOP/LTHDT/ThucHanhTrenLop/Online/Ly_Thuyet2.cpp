#include<iostream>
#include<fstream>
using namespace std;

class ps{
	private:
		int ts,ms;
	public:
		friend istream& operator>>(istream& in, ps &a);
		friend ostream& operator<<(ostream& out, ps a);
		ps operator+(ps a);
		float operator++();
};

istream& operator>>(istream& in, ps &a){
	cout<<"\n============ NHAP THONG TIN PHAN SO ============" <<endl;
	cout<<"\nNhap phan so: ";							in >> a.ts;
	cout<<"\nNhap phan so: ";							in >> a.ms;
return in;
}

ostream& operator<<(ostream& out, ps a)
{
	out<<"\t" << a.ts << "/" << a.ms;
return out;
}

ps ps::operator+(ps a)
{
	ps sum;
	sum.ts = (ts * a.ms) + (ms * a.ts);
	sum.ms = ms * a.ms;
return sum;
}

float ps::operator++(){
	return (float)ts / ms;
}

int main()
{
	ps a,b;
	ofstream ghi("Ly_Thuyet2.txt");
	cin>>a;
	cout<<"\nPhan so a la: ";				cout<<a;					ghi<<a;
	cout<<endl;
	cin>>b;
	cout<<"\nPhan so b la: ";				cout<<b;					ghi<<b;
	cout<<"\nPhan so a + b la: ";			cout<<a + b <<endl;			ghi<<a + b;
	cout<<"\n TS chia MS la: ";
	cout<<++a;
	return 0;
}
