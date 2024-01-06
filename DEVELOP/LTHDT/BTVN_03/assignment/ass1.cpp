#include<bits/stdc++.h>
using namespace std;

class PS {
	private:
		float ts, ms;
	public:
		friend istream& operator>>(istream& in, PS &x);
		friend ostream& operator<<(ostream& out, PS x);	
		PS();
		PS(float a, float b);	
		PS operator*(PS a);
		float operator++();
		
};

PS::PS(){
	ts = 0;
	ms = 1;
}

PS::PS(float a, float b)
{
	ts = a;
	if(b == 0)
	{
		cout<<"\nDo ban nhap mau so bang 0 (vi pham dieu kien phan so) nen mau so se tro thanh 1";
		ms = 1;
	}else{
		ms = b;
	}
}

istream& operator>>(istream& in, PS &x)
{
	cout<<"\n==== NHAP THONG TIN PHAN SO ====" << endl;
	cout<<"\nNhap tu so: ";											in>>x.ts;
	cout<<"\nNhap mau so: ";										in>>x.ms;
return in;
}

ostream& operator<<(ostream& out, PS x)
{
	if(x.ts < 0)
	{
		if(x.ms < 0) out<< -x.ts << "/" << -x.ms;
		else out<< "-(" << -x.ts << "/" << x.ms << ")";
	}else {
		if(x.ms < 0) out<< "-(" <<x.ts << "/" << -x.ms << ")";
		else out<< x.ts << "/" << x.ms;
	}
return out;
}

PS PS::operator*(PS a)
{
	PS k;
	k.ts = ts * a.ts;
	k.ms = ms*a.ms;
return k;
}

float PS::operator++()
{
	return ts/ms;
}


main()
{
	PS a, b(5,0);
	cin>>a;
	cout<<"\nPhan so A la: " << a;
	cout<<"\nPhan so B la: " << b;
	cout<<"\nTich cua hai phan so A va B la: " << a*b;
	cout<<"\nGia tri cua phan so A la: " << ++a;
	
	// ghi file;
	ofstream ghi("ASS1.txt");
	ghi<<"\nPhan so A la: " << a;
	ghi<<"\nPhan so B la: " << b;
	ghi<<"\nTich cua hai phan so A va B la: " << a*b;
	ghi<<"\nGia tri cua phan so A la: " << ++a;
	ghi.close();
}
