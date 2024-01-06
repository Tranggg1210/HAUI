#include<iostream>
#include<string.h>
using namespace std;

char str1[255], str2[255];

void nhapchuoi(char str1[255], char str2[255])
{
	fflush(stdin);
	cout<<"Nhap chuoi str1: "<<endl;
	gets(str1);
	fflush(stdin);
	cout<<"Nhap chuoi str2: "<<endl;
	gets(str2);
}

void hienthi(char str1[255], char str2[255])
{
	cout<<"Chuoi str1 la: "<< str1 << endl;
	cout<<"Chuoi str2 la: "<< str2 << endl;
}

void sosanhhoathuong(char str1[255], char str2[255])
{
	cout<<"----------So sanh phan biet hoa thuong----------"<<endl;
	if(strlen(str1) != strlen(str2))
	{
		cout<<"Hai chuoi str1 va str2 khong bang nhau"<<endl;
	}else{
		int dem = 0;
		for(int i = 0; i < strlen(str1); i++)
		{
			if(str1[i] != str2[i])
			{
				dem = 1;
				break;
			}
		}
		if(dem == 0) cout<<"Hai chuoi str1 va str2 bang nhau"<<endl;
		else cout<<"Hai chuoi str1 va str2 khong bang nhau"<<endl;
	}
}

void sosanhkhonghoathuong(char str1[255], char str2[255])
{
	cout<<"----------So sanh khong phan biet hoa thuong----------"<<endl;
	if(strlen(str1) != strlen(str2))
	{
		cout<<"Hai chuoi str1 va str2 khong bang nhau"<<endl;
	}else{
		int dem = 0;
		char str3[255], str4[255];
	    for(int i = 0; i < strlen(str1); i++)
	    {
	    	str3[i] = str1[i];
	    	str4[i] = str2[i];
		}
		for(int i = 0; i < strlen(str1); i++)
		{
			if(str1[i] >= 'A' && str1[i] <= 'Z') str3[i] = str1[i] + 32;
			if(str2[i] >= 'A' && str2[i] <= 'Z') str4[i] = str2[i] + 32;
			if(str3[i] != str4[i])
			{
				dem = 1;
				break;
			}
		}
		if(dem == 0) cout<<"Hai chuoi str1 va str2 bang nhau"<<endl;
		else cout<<"Hai chuoi str1 va str2 khong bang nhau"<<endl;
	}
}

void sosanh3kytudau(char str1[255], char str2[255])
{
	cout<<"----------So sanh ba ky tu dau----------"<<endl;
	if(strlen(str1) < 3 ||  strlen(str2) < 3)
	{
		cout<<"Hai chuoi str1 va str2 khong bang nhau"<<endl;
	}else{
		int dem = 0;
		for(int i = 0; i < 3; i++)
		{
			if(str1[i] != str2[i])
			{
				dem = 1;
				break;
			}
		}
		if(dem == 0) cout<<"Hai chuoi str1 va str2 bang nhau"<<endl;
		else cout<<"Hai chuoi str1 va str2 khong bang nhau"<<endl;
	}
}

int main()
{
	nhapchuoi(str1,str2);
	hienthi(str1,str2);
	sosanhhoathuong(str1, str2);
	sosanhkhonghoathuong(str1,str2);
	sosanh3kytudau(str1, str2);
	return 0;
}
