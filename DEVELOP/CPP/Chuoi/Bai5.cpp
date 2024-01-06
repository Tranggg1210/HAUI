#include<iostream>
#include<string.h>
using namespace std;

char str[255];

void nhap(char str[])
{
	fflush(stdin);
	cout<<"Nhap chuoi: ";
	gets(str);
	cout<<endl;
}

void demtu(char str[])
{
	int dem;
	if(str[0] != 32) dem = 1;
	else dem = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == 32 && str[i+1] != 32) dem++;
	}
	cout<<"So tu trong chuoi la: "<<dem<<endl;
}

int main()
{
	nhap(str);
	demtu(str);
	return 0;
}
