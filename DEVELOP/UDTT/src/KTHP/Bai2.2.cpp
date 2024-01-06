#include<bits/stdc++.h>
using namespace std;

void hienThiMang(int n, double a[])
{
	cout<< "------------ MANG VUA KHOI TAO ------------" << endl;
	for(int i = 0; i < n; i++)
		cout<< a[i] << "\t";
	cout<< endl;
}

// sap xep
bool cmp(double a, double b)
{
	return a > b;
}

// chien luoc tham lam
bool chienLuocThamLam(int *z, double a[], int n, double c)
{
	sort(a, a+n, cmp);
	int i = 0;
	while (i < n && c >= 0)
	{
		c -= a[i];
		z[i] = 1;
		i++;
	}
	if(c > 0) return false;
	return true;
}

void ketQua(int n, double a[], int *z)
{
	int d = 0;
	double m = 0;
	for(int i = 0; i < n; i++)
	{
		d += z[i];
		if(z[i] != 0) m += a[i];
	}
	
	cout<< "So luong phan tu it nhat co the lay trong a la: " << d << endl;
	cout<<"Gia tri M la: " << m << endl;
	cout<<"------------ CAC PHAN TU DUOC CHON ------------" << endl;
	for(int i = 0; i < n; i++)
		if(z[i] != 0)
			cout<< a[i] << "\t";
	cout<< endl;
}

// y 2
int char_in_string(char a, char *p)
{
	for(int i = 0; i < strlen(p); i++)
	{
		if(a == p[i]) return i;
	}
	return -1;
}

int BMH(char *p, char *q,int *vitri)
{
	int v = strlen(p), i = v - 1, dem = 0;
	while(i < strlen(q))
	{
		int x = v - 1;
		while(p[x] == q[i] && x > -1)
		{
			x--; i--;
		}
		if(x < 0)
		{
			if(i < 0) vitri[dem] = 0 ;
			else vitri[dem] = i + 2;
			dem++;
			i += (2*v);
		}else{
			int k = char_in_string(q[i], p);
			if(k < 0) i += v;
			else i = i + v - k -1;
		}
	}
	return dem;
}

// ket qua y 2
void ketQuaY2(char *p, char *q,int *vitri)
{
	cout<< "Chuoi Q la: " << q << endl;
	cout<< "Chuoi P la: " << p << endl;
	if(BMH(p,q,vitri) != 0)
	{
		cout<< "So lan xuat hien cua chuoi P trong chuoi Q la: " <<BMH(p,q,vitri) <<endl; 
		cout<< "------------ DANH SACH VI TRI XUAT HIEN CHUOI P TRONG CHUOI Q ------------" << endl;
		for(int i = 0; i < BMH(p,q,vitri); i++)
			cout<< vitri[i] << "\t";
		cout<< endl;	
	} else cout<< "Chuoi P khong xuat hien trong chuoi Q"<< endl;
}

int main()
{
	// khoi tao
	int n = 9;
	double a[n] = {1.2,2.3,3.5,6.5,7.6,9.9,10.9,18.4,20};
	double c = 39.9;
	int *z = new int[n];
	memset(z,0,sizeof(int)*n);
	char p[] = "dep";
	char q[] = "dep qua hom nay troi that dep va ban cung rat dep do";
	// hien thi mang khoi tao
	hienThiMang(n,a);
	
	// y 1
	if(chienLuocThamLam(z,a,n,c))
		ketQua(n,a,z);
	else cout<< "Khong the tim duoc" << endl;
	
	// y 2
	memset(z,0,sizeof(int)*n);
	ketQuaY2(p,q,z);
	
	// huy con tro
	delete[] z;
	return 0;
}
