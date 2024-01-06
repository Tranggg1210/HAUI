#include<iostream>
#include<fstream>
using namespace std;

void taofile(char *a, char *b)
{
	ofstream f1(a, ios::out);
	f1 << "7 2"<<endl;
	f1 << "1 2 3 1"<<endl;
	f1 << "2 2 4 1"<<endl;
	f1 << "3 3 5 1" << endl;
	f1.close();
	f1.open(b, ios::out);
	f1 << "4 1 1 2"<<endl;
	f1 << "5 2 2 2"<<endl;
	f1 << "6 3 3 2"<<endl;
	f1 << "7 4 4 2" << endl;
	f1.close();
}

void docFile(char *a)
{
	ifstream f(a, ios::in);
	char s[255];
	while(!f.eof())
	{
		f.getline(s,255);
		cout<< s << endl;
	}
	f.close();
}

void ghepfile(char *a, char *b, char *c)
{
	ofstream f(c, ios::out);
	ifstream f1(a, ios::in);
	char s[255];
	while(!f1.eof())
	{
		f1.getline(s,255);
		f << s <<endl;
	}
	f.close();
	f1.close();
	f.open(c, ios::app);
	f1.open(b, ios::in);
	while(!f1.eof())
	{
		f1.getline(s,255);
		f << s <<endl;
	}
	f.close();
	f1.close();
}

int main()
{
	char a[255];
	fflush(stdin);
	cout<<"Nhap ten file dau: ";
	gets(a);
	cout<<endl;
	char b[100];
	fflush(stdin);
	cout<<"Nhap ten file thu hai: ";
	gets(b);
	taofile(a,b);
	cout<<"FILE1.txt la: "<<endl;
	docFile(a);
	cout<<"FILE2.txt la: "<<endl;
	docFile(b);
	cout<<endl;
	char c[100];
	fflush(stdin);
	cout<<"Nhap ten file ghep giua a va b: ";
	gets(c);
	ghepfile(a,b,c);
	cout<<"FILE3.txt la: "<<endl;
	docFile(c);
	return 0;
}
