#include<bits/stdc++.h>
using namespace std;

class PTBH {
	private:
		float a,b,c;
	public:
		void nhap();
		void xuat();
	PTBH operator+(PTBH A);
};

void PTBH::nhap()
{
	cout<<"\n====NHAP HE SO CUA PHUONG TRINH====";
	cout<<"\nNhap a: ";								cin>>a;
	cout<<"\nNhap b: ";								cin>>b;
	cout<<"\nNhap c: ";								cin>>c;
}

void PTBH::xuat()
{
	if(b > 0)
	{
		if(c < 0)
		{
			cout<<"\nPhuong trinh bac hai la: " << a << "x*x + " << b << "x - " << -c <<" = 0";
		}else cout<<"\nPhuong trinh bac hai la: " << a << "x*x + " << b << "x + " << c <<" = 0";
	}else{
		if(c < 0) cout<<"\nPhuong trinh bac hai la: " << a << "x*x - " << -b << "x - " << -c <<" = 0";
		else cout<<"\nPhuong trinh bac hai la: " << a << "x*x - " << -b << "x + " << c <<" = 0";
	}
}

PTBH PTBH::operator+(PTBH A ){
	PTBH K;
	K.a = a + A.a ;
	K.b = b + A.b;
	K.c = c + A.c;
	return K;
}

main()
{
	ofstream ghi("PTBH.txt");
	PTBH a,b,c;
	a.nhap();
	b.nhap();
	a.xuat();
	b.xuat();
	c = a + b;
	c.xuat();
//	ghi<< "\nPhuong trinh A la: "<< a;
//	ghi<<"\nPhuong trinh B la: " << b;
}
