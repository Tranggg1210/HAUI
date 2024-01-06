#include<bits/stdc++.h>
using namespace std;

class HTG {
	private:
		float a,b,c;
	public:
		float operator++();
		friend istream& operator>>(istream& in, HTG &x);
		friend ostream& operator<<(ostream& out, HTG x);
};

istream& operator>>(istream& in, HTG &x) {
	cout<<"\n==== NHAP CAC THONG SO CUA TAM GIAC ====" << endl;
	do{
		do{
			cout<<"\nNhap do dai canh a > 0: ";							in>>x.a;
		}while(x.a < 1);
		do{
			cout<<"\nNhap do dai canh b > 0: ";							in>>x.b;
		}while(x.b < 1);
		do{
			cout<<"\nNhap do dai canh c > 0: ";							in>>x.c;
		}while(x.b < 1);
	}while(x.a + x.b < x.c || x.a > x.b + x.c || x.a + x.c < x.b);
return in;
}

ostream& operator<<(ostream& out, HTG x){
	out<<"\nCac canh cua HTG la: " << x.a << "\t" << x.b << "\t" << x.c;
return out;
}

main()
{
	HTG a;
	cin>>a;
	cout<<a;
}
