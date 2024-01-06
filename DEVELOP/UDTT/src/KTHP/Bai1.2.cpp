#include<bits/stdc++.h>
using namespace std;

void hienThiMang(int n, double a[])
{
	cout<<"------------- MANG KHOI TAO -------------" << endl;
	for(int i = 0; i< n; i++)
		cout<<a[i] <<"\t";
	cout<<endl;
}

// chien luoc tham lam
bool chienLuocThamLam(long *z, double a[], int n, double c)
{
	int i = 0;
	while(i < n && c >= 0)
	{
		c -= a[i];
		if(c >= 0) z[i] = 1;
		i++;
	}
	if(c > 0) return false;
	else return true;
}

void hienThiKetQua(long *z, int n, double a[])
{
	int dem = 0;
	double d = 0;
	for(int i = 0; i < n; i++) 
	{
		dem += z[i];
		if(z[i] != 0) d += a[i];
			
	}
	cout<<"So luong phan tu nhieu nhat co the lay trong day a de duoc mot gia tri khong vuot qua C la: " << dem << endl;
	cout<<"Tong gia tri cua cac phan tu lay la: " << d << endl;
	cout<<"------------- MANG CAC PHAN TU DUOC CHON -------------" << endl;
	for(int i = 0; i< n; i++)
		if(z[i] != 0) cout<<a[i] <<"\t";
	cout<<endl;
}


//Boyer Moore Horspool
int char_in_string(char a, char *q)
{
	for(int i = 0; i < strlen(q); i++)
	{
		if(q[i] == a) return i;
	}
	return -1;
}

bool BMH(char *q, char *p)
{
	int v = strlen(q), i = v - 1;
	while(i < strlen(p))
	{
		int x = v - 1;
		while(p[i] == q[x] && x > -1)
		{
			x--; i--;
		}
		if(x < 0) return true;
		else {
			int k = char_in_string(p[i], q);
			if(k < 0)
				i += v;
			else i = i + v - k - 1;
		}
		
	}
	return false;
}

int main()
{
	// khoi tao
	int n = 9;
	double a[n] = {5.9, 6.5, 6.7, 7.8, 8.4, 8.9, 9.9, 10, 10.1};
	double c = 19.9;
	long *z = new long[n];
	memset(z,0,sizeof(long)*n);
	char p[] ="homnaythatdepdobantrangdepcothayhomnaydepkhumquadep";
	char q[] ="khongdep";
	
	// Mang khoi tao
	hienThiMang(n,a);
	
	// Tham lam
	if(chienLuocThamLam(z,a,n,c))
		hienThiKetQua(z,n,a);
	else cout<< "Khong the tim thay";
	
	
	// hien thi chuoi
	cout<<"Chuoi P: " << p<< endl;
	cout<<"Chuoi Q: " << q << endl;
	if(BMH(q,p))
	{
		cout<< "Chuoi Q la chuoi con cua chuoi P";
	}else cout<< "Chuoi Q la KHONG chuoi con cua chuoi P";
	// huy con tro
	delete[] z;
}
