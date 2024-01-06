#include<bits/stdc++.h>
using namespace std;

class truongdh;

class khoa {
	private:
		char makhoa[20];
		char tenkhoa[40];
		char tentk[40];
	public:
		friend class truongdh;
		friend void xoa(truongdh &a);
		friend void chen(truongdh &a);
};

class ban {
	private:
		char maban[20];
		char tenban[40];
		char ngaytl[20];
	public:
		friend class truongdh;
		friend void xoa(truongdh &a);
		friend void chen(truongdh &a);
};

class truong {
	protected:
		char matruong[20];
		char tentruong[40];
		char diachi[40];
	public:
		void nhap();
		void xuat();
};

class truongdh : public truong {
	private:
		int n,m; // so luong khoa va ban trong truong
		khoa x[100];
		ban y[100];
	public:
		void nhap();
		void xuat();
	friend void xoa(truongdh &a);
	friend void chen(truongdh &a);
};

void truong::nhap() {
	cout<< "\nNhap ma truong: ";					fflush(stdin);				gets(matruong);
	cout<<"\nNhap ten trong: ";						fflush(stdin);				gets(tentruong);
	cout<<"\nNhap dia chi cua truong: ";			fflush(stdin);				gets(diachi);
}

void truong::xuat() {
	cout<<"\n" << setw(19) << "Ma truong: " << matruong
		<< setw(15)<< "\t\tTen truong: " << tentruong;
	cout<<"\n"  << setw(17) << "Dia chi: " << diachi;
}

void truongdh::nhap() {
	cout<<"\n==== NHAP THONG TIN CUA TRUONG DAI HOC ====" << endl;
	truong::nhap();
	
	// nhap khoa
	do{
		cout<<"\nNhap so luong khoa cua truong n > 0: ";						cin>>n;
	}while(n < 1);
		for(int i = 0; i < n; i++)
		{
			cout<<"\n==== NHAP THONG TIN KHOA THU " << i + 1 << " ====" << endl;
			cout<<"\nNhap ma khoa: ";				fflush(stdin);				gets(x[i].makhoa);
			cout<<"\nNhap ten khoa: ";				fflush(stdin);				gets(x[i].tenkhoa);
			cout<<"\nNhap ten truong khoa: ";		fflush(stdin);				gets(x[i].tentk);
		}
		
		
	// nhap ban
	do{
		cout<<"\nNhap so luong ban cua truong m > 0: ";						cin>>m;
	}while(m < 1);
		for(int i = 0; i < m; i++)
		{
			cout<<"\n==== NHAP THONG TIN BAN THU " << i + 1 << " ====" << endl;
			cout<<"\nNhap ma ban: ";				fflush(stdin);				gets(y[i].maban);
			cout<<"\nNhap ten ban: ";				fflush(stdin);				gets(y[i].tenban);
			cout<<"\nNhap ngay thanh lap ban: ";	fflush(stdin);				gets(y[i].ngaytl);
		}
	
}


void truongdh::xuat() {
	truong::xuat();
	
	cout<<"\n\n\tBang khoa:";
	
	cout<< "\n" << setw(15) << "Ma khoa"
			<< setw(15) << "Ten khoa"
			<< setw(20) << "Ten truong ban";
	
	for(int i = 0; i < n; i++)
	{
		cout<< "\n" << setw(15) << x[i].makhoa
			<< setw(15) << x[i].tenkhoa
			<< setw(20) << x[i].tentk;
	}
	
	
	cout<<"\n\n\tBang ban:";
	
	cout<< "\n" << setw(15) << "Ma ban"
			<< setw(15) << "Ten ban"
			<< setw(20) << "Ngay thanh lap ban";
	
	for(int i = 0; i < m; i++)
	{
		cout<< "\n" << setw(15) << y[i].maban
			<< setw(15) << y[i].tenban
			<< setw(20) <<  y[i].ngaytl;
	}
}

void xoa(truongdh &a)
{
	int dem = 0;
	for(int i = 0; i < a.n; i++)
	{
		if(strcmp(a.x[i].makhoa, "KH01")==0)
		{
			dem++;
		}
	}
	
	if(dem == 0)
	{
		cout<<"\n\nTrong truong khong co khoa nao co ma KH01";
	}else {
		for(int i = 0; i < a.n; i++)
		{
			if(strcmp(a.x[i].makhoa, "KH01")==0)
			{
				for(int j = i; j < a.n; j++ )
				{
					a.x[j] = a.x[j+1];
				}
				a.n--;
				i--;
			}
		}
		cout<<"\n\n\t==== THONG TIN TRUONG DAI HOC SAU KHI XOA KHOA CO MA KH01 =====" << endl;
		a.xuat();
	}
}


void chen(truongdh &a)
{
	int k;
	do{
		cout<<"\nNhap vi tri ban can chen 0 <= k < "<< a.m <<": ";					cin>>k;
	}while(k < 0 || k > a.m);
	
	for(int i = a.m; i >= k; i--)
	{
		a.y[i] = a.y[i - 1];
	}
	cout<<"\nNhap ma ban can chen: ";				fflush(stdin);				gets(a.y[k].maban);
	cout<<"\nNhap ten ban can chen: ";				fflush(stdin);				gets(a.y[k].tenban);
	cout<<"\nNhap ngay thanh lap ban can chen: ";	fflush(stdin);				gets(a.y[k].ngaytl);
	a.m++;
	cout<<"\n\n\t==== THONG TIN TRUONG DAI HOC SAU KHI CHEN THEM BAN =====" << endl;
	a.xuat();
	
}

main()
{
	truongdh a;
	a.nhap();
	cout<<"\n\t==== THONG TIN TRUONG DAI HOC =====" << endl;	
	a.xuat();
	xoa(a);
	chen(a);
};
