#include<bits/stdc++.h>
using namespace std;

int char_in_string(char a, char *p)
{
	for(int i = 0; i < strlen(p); i++)
	{
		if(a == p[i]) return i;
	}
	return -1;
}

int BMH(char *p, char *t)
{
	int dem = 0,v = strlen(p), i = v - 1;
	while(i < strlen(t))
	{
		int x = v - 1;
		while(p[x] == t[i] && x > -1) { x--;i--;}
		if(x < 0) {
			dem++; i += 2*v;
		}else{
			int k = char_in_string(t[i],p);
			if(k < 0) i += v;
			else i = i + v - k - 1;
		}
	}
	return dem;
}

//void z_algo(char *s, int *z)
//{
//	int n = strlen(s), l = 0, r = 0;
//	for(int i = 1; i < n; i++)
//	{
//		if(i > r)
//		{
//			r = l = i;
//			while(r < n && s[r - l] == s[r])
//				r++;
//			z[i] = r - l; r--;
//		}else if(z[i - l] < r - i + 1)
//		{
//			z[i] = z[i-l];
//		}else{
//			l = i;
//			while(r < n && s[r-l] == s[r])
//				r++;
//			z[i] = r - l; r--;
//		}
//	}
//}

void z_algo(char *s, int *z)
{
	int n = strlen(s), l = 0, r = 0;
	for(int i = 0; i < n; i++)
	{
		if(i > r)
		{
			l = r = i;
			while(r < n && s[r-l] == s[r])
				r++;
			z[i] = r - l; r--;
		}else if(z[i - l] < r - i +1)
		{
			z[i] = z[i-l];
		}else{
			l = i;
			while(r < n && s[r-l] == s[r])
				r++;
			z[i] = r - l; r--;
		}
	}
}

int main()
{
	char t[] ="homnaythatdepdobantrangdepcothayhomnaydepkhumquadep";
	char p[] ="dep";
	cout<<"Chuoi t: " << t << endl;
	cout<<"Chuoi p: " << p << endl;
	cout<<"\nSo lan xuat hien cua chuoi p trong chuoi t la: " << BMH(p,t);
	
	int *z;
	z = new int[strlen(t)];
	z[0] = 0;
	z_algo(t,z);
	cout<< "\nMang z la: "<<endl;
	for(int i = 0; i < strlen(t); i++)
	{
		cout<< z[i] << "  ";
	}
	int max = z[0];
	for(int i = 1; i < strlen(t); i++)
	{
		if(max < z[i]) max = z[i];
	}
	cout<<"\nChuoi dai nhat la: ";
	for(int i = 0; i < strlen(t); i++)
	{
		if(z[i] == max)
		{
			for(int j = i; j < i+max; j++)
			{
				cout<<t[j];
			}
		}
		
	}
	delete[] z;
	return 0;
}
