#include<iostream>
#include<fstream>
using namespace std;

void taoFILE(char *k)
{
	ofstream f(k,ios::out);
	f << "Problem name: exp1" << endl;
	f << "Maximize"<<endl;
	f << "obj:\t\t x1 + 2 x2 + 3 x3 + x4" << endl;
	f << "Subject To"<< endl;
	f << "c1:\t x2 - 3.5 x4 = 0" << endl;
	f << "Bounds"<<endl;
	f << "0 <= x1 <= 40"<<endl;
	f << "General"<<endl;
	f << "   \t x4"<<endl;
    f << "End"<<endl;
    f.close();
}

void docFILE(char *k)
{
	ifstream f(k, ios::in);
	char s[255];
	while( !f.eof())
	{
		f.getline(s,255);
		cout<< s << endl;
	}
	f.close();
}

int main()
{
	char k[100];
	cout<<"Nhap ten File: ";
	gets(k);
	taoFILE(k);
	docFILE(k);
	return 0;
}
