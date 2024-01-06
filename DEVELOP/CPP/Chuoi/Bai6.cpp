#include<iostream>
#include<string.h>
using namespace std;

char a[255];

void nhap(char a[])
{
	do{
		fflush(stdin);
	    cout<<"Nhap chuoi khac rong: ";
	    gets(a);
	    cout<<endl;
	}while(strcmp(a,"") == 0);
}

void trim(char a[])
{
	while(a[0] == 32)
	{
		for(int i = 0; i< strlen(a); i++)
		{
			a[i] = a[i+1];
		}
	}
	while(a[strlen(a) - 1] == 32)
	{
		a[strlen(a) - 1] = '\0';
	}
}

void ktgiua(char a[])
{
	for(int i = 0; i < strlen(a); i++)
	{
		if(a[i] == 32 && a[i+1] == 32)
		{
			for(int j = i + 1; j < strlen(a); j++)
			{
				a[j] = a[j + 1];
			}
			i--;
		}
	}
}

void ktchamphay(char a[])
{
	for(int i = 0; i < strlen(a); i++)
	{
		if((a[i] == 32 && a[i + 1] == ',') || a[i] == 32 && a[i + 1] == '.')
		{
			for(int j = i; j < strlen(a); j++)
			{
				a[j] = a[j+1];
			}
			i--;
		}
	}
}

void hoa(char a[])
{
	a = strlwr(a);
	a[0] = a[0] - 32;
	for(int i = 1; i < strlen(a); i++)
	{
		if(a[i] == 32 && a[i + 1] != 32 )
		{
			a[i + 1] -= 32;
		}
	}
}

int main()
{
	nhap(a);
	trim(a);
	ktgiua(a);
	ktchamphay(a);
	hoa(a);
	cout<<"Chuoi sau khi chuan hoa la: "<<a<<endl;
	cout<<"Do dai cua chuoi la: "<< strlen(a)<<endl;
	return 0;
}
