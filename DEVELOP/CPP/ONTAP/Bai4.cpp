#include<iostream>
#include<string.h>
using namespace std;

void nhap(char *&s)
{
	s = new char[255];
	fflush(stdin);
	cout<<"Nhap chuoi s: ";
	gets(s);
}

bool tim_BIS(char *s)
{
	for(int i = 0; i < strlen(s) - 2; i++)
	{
		if(s[i] == 'B' && s[i+1] == 'I' && s[i+2] == 'S')
		   return true;
	}
	return false;
}

void xoa(char *s, char C)
{
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] == C)
		{
			for(int j = i; j < strlen(s); j++)
			{
				s[j] = s[j + 1];
			}
			i--;
		}
	}
}

void chen(char *s, char T, int k)
{
	if(k >= 0 && k < strlen(s))
	{
		for(int i = strlen(s); i >= k; i--)
		{
			s[i] = s[i - 1];
		}
		s[k] = T;
		cout<< "Chuoi sau khi chen ky tu " << T << " vao vi tri thu " << k << " la: " << s << endl;
	}else cout<<"Vi tri chen ky tu " << T << "khong hop le!" << endl;
}

int main()
{
	char *s;
	nhap(s);
	if(tim_BIS(s)) cout<< "\nYES : BIS" << endl;
	else cout<< "\nNO : BIS" << endl;
	char C;
	fflush(stdin);
	cout << "Nhap ky tu C: ";
	cin>>C;
	xoa(s,C);
	cout<<"\nChuoi sau khi xoa di cac ky tu " << C << " la: "<< s << endl;
	char T;
	fflush(stdin);
	cout << "Nhap ky tu T: ";
	cin>>T;
	int k;
	cout<<"Nhap vi tri can chen k: ";
	cin >> k;
	chen(s,T,k);
	delete s;
	return 0;
}
