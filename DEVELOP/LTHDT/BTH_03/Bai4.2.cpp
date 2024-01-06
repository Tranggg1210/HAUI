#include<iostream>
#include<stdio.h>
using namespace std;

class printer {
	protected:
		float trongluong;
		char hangsx[40];
		int namsx;
		float tocdo;
	friend void update(printer &p);
};

class dotprinter: public printer {
	private:
		int matdokim;
	public:
		void nhap();
		void xuat();
};

class laserprinter: public printer {
	private:
		int dophangiai;
	public:
		void nhap();
		void xuat();
};

void dotprinter::nhap()
{
	cout<<"\n================ NHAP THONG TIN MAY IN DOT ================" << endl;
	cout<<"\nTrong luong: ";										cin >> trongluong;
	cout<<"\nTen hang san xuat: ";			fflush(stdin);			gets(hangsx);
	cout<<"\nNam san xuat: ";										cin >> namsx;
	cout<<"\nToc do: ";												cin >> tocdo;
	cout<<"\nMat do kim: ";											cin >> matdokim;
}

void dotprinter::xuat()
{
	cout<<"Trong luong: " << trongluong << endl;
	cout<<"Ten hang sx: " << hangsx << endl;
	cout<<"Nam sx: " << namsx << endl;
	cout<<"Toc do: " << tocdo << endl;
	cout<<"Mat do kim: " << matdokim << endl;
}

void laserprinter::nhap()
{
	cout<<"\n================ NHAP THONG TIN MAY IN LASER ================" << endl;
	cout<<"\nTrong luong: ";										cin >> trongluong;
	cout<<"\nTen hang san xuat: ";			fflush(stdin);			gets(hangsx);
	cout<<"\nNam san xuat: ";										cin >> namsx;
	cout<<"\nToc do: ";												cin >> tocdo;
	cout<<"\nDo phan giai: ";										cin >> dophangiai;
}

void laserprinter::xuat()
{
	cout<<"Trong luong: " << trongluong << endl;
	cout<<"Ten hang sx: " << hangsx << endl;
	cout<<"Nam sx: " << namsx << endl;
	cout<<"Toc do: " << tocdo << endl;
	cout<<"Do phan giai: " << dophangiai << endl;
}

void update(printer &p)
{
	p.namsx = 2020;
}

int main()
{
	dotprinter d;
	laserprinter l;
	d.nhap();
	cout<<endl;
	l.nhap();
	cout<<"\n================ THONG TIN MAY IN DOT ================" << endl;
	d.xuat();
	cout<<"\n================ THONG TIN MAY IN LASER ================" << endl;
	l.xuat();    
	cout<<"\n================ THONG TIN MAY IN DOT SAU KHI SUA DOI NAM SX================" << endl;
	update(d);
	d.xuat();
	cout<<"\n================ THONG TIN MAY IN LASER SAU KHI SUA DOI NAM SX================" << endl;
	update(l);   
	l.xuat(); 
	return 0;
}
