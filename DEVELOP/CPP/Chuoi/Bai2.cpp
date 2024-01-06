#include<iostream>
#include<string.h>
using namespace std;

char str[100], str1[100], str3[200];
int t,t1;

void nhap(char str[])
{
	fflush(stdin);
	cout<<"Nhap chuoi cua ban: "<< endl;
	gets(str);
}

void demhoathuong(char str[])
{
	int dem = 0, dem1 = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z') dem++;
		if(str[i] >= 'a' && str[i] <= 'z') dem1++;
	}
	cout<<"So chu cai in hoa trong chuoi la: "<<dem<<endl;
	cout<<"So chu cai in thuong trong chuoi la: "<<dem1<<endl;
}

void daochuoi(char str1[100], char str[100])
{
	t = 0;
	for(int i = strlen(str) - 1; i >= 0 ; i--)
	{
		str1[t++] = str[i];
	}
	cout<<"Chuoi str1 dao nguoc cua chuoi str la: "<< str1 <<endl;
}

void thaythe(char str1[])
{
	t1 = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		
		if(str[i] <= '9' && str[i] >= '0')
		{
			switch (str[i])
			{
				case '0':
					str3[t1++] = 'k';
					str3[t1++] = 'h';
					str3[t1++] = 'o';
					str3[t1++] = 'n';
					str3[t1++] = 'g';
					str3[t1++] = ' ';
					break;
				case '1':
					str3[t1++] = 'm';
					str3[t1++] = 'o';
					str3[t1++] = 't';
					str3[t1++] = ' ';
					break;
				case '2':
					str3[t1++] = 'h';
					str3[t1++] = 'a';
					str3[t1++] = 'i';
					str3[t1++] = ' ';
					break;
				case '3':
					str3[t1++] = 'b';
					str3[t1++] = 'a';
					str3[t1++] = ' ';
					break;
				case '4':
					str3[t1++] = 'b';
					str3[t1++] = 'o';
					str3[t1++] = 'n';
					str3[t1++] = ' ';
					break;
				case '5':
					str3[t1++] = 'n';
					str3[t1++] = 'a';
					str3[t1++] = 'm';
					str3[t1++] = ' ';
					break;
				case '6':
					str3[t1++] = 's';
					str3[t1++] = 'a';
					str3[t1++] = 'u';
					str3[t1++] = ' ';
					break;
				case '7':
					str3[t1++] = 'b';
					str3[t1++] = 'a';
					str3[t1++] = 'y';
					str3[t1++] = ' ';
					break;
				case '8':
					str3[t1++] = 't';
					str3[t1++] = 'a';
					str3[t1++] = 'm';
					str3[t1++] = ' ';
					break;
				case '9':
					str3[t1++] = 'c';
					str3[t1++] = 'h';
					str3[t1++] = 'i';
					str3[t1++] = 'n';
					str3[t1++] = ' ';
					break;
			}
		}else str3[t1++] = str[i];
		
	}
	cout<<"Chuoi sau khi duoc thay the cac con so la: "<<str3<<endl;
}

int main()
{
	nhap(str);
	demhoathuong(str);
	daochuoi(str1, str);
	thaythe(str);
	return 0;
}
