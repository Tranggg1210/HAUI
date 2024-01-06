#include<bits/stdc++.h>
using namespace std;

class truongdh;

class khoa {
	private:
		char makhoa[20];
		char tenkhoa[50];
		char truongkhoa[50];
	friend class truongdh;
	friend void deleteItem(truongdh &dh);
};

class ban {
	private:
		char maban[20];
		char tenban[50];
		char ngaythanhlap[20];
	friend class truongdh;
};

class truong {
	private:
		char matruong[20];
		char tentruong[50];
		char diachi[50];
	public:
		void nhap();
		void xuat();
};

class truongdh: public truong {
	private:
		int n,m; // so luong khoa va ban
		khoa *x;
		ban *y;
	public:
		void nhap();
		void xuat();
		~truongdh();
	friend void deleteItem(truongdh &dh);
};

void truong::nhap() {
	cout<<"\nNhap ma truong: ";					fflush(stdin);			gets(matruong);
	cout<<"\nNhap ten truong: ";				fflush(stdin);			gets(tentruong);
	cout<<"\nNhap dia chi truong: ";			fflush(stdin);			gets(diachi);
}

void truong::xuat() {
	cout<<"\n\tMa truong: " << matruong << "\t\t\tTen truong: " << tentruong << endl;
	cout<<"\n\tDia chi: " << diachi << endl;
}

void truongdh::nhap() {
	truong::nhap();
	cout<<"\nNhap so luong khoa n: ";								cin >> n;
	x = new khoa[n];
	for(int i = 0; i < n; i++)
	{
		cout<<"\n======== NHAP THONG TIN KHOA THU " << i + 1 << " ========" << endl;
		cout<<"\nNhap ma khoa: ";				fflush(stdin);			gets(x[i].makhoa);
		cout<<"\nNhap ten khoa: ";				fflush(stdin);			gets(x[i].tenkhoa);
		cout<<"\nNhap ten truong khoa: ";		fflush(stdin);			gets(x[i].truongkhoa);
	}
	cout<<"\n\nNhap so luong ban m: ";								cin >> m;
	y = new ban[m];
	for(int i = 0; i < m; i++)
	{
		cout<<"\n======== NHAP THONG TIN BAN THU " << i + 1 << " ========" << endl;
		cout<<"\nNhap ma ban: ";				fflush(stdin);			gets(y[i].maban);
		cout<<"\nNhap ten ban: ";				fflush(stdin);			gets(y[i].tenban);
		cout<<"\nNhap ngay thanh lap ban: ";	fflush(stdin);			gets(y[i].ngaythanhlap);
	}
}

void truongdh::xuat() {
	truong::xuat();
	cout<<"\n\n\tBang khoa: "<< endl;
	cout<<"\n\t" << setw(15) << "Ma khoa"
		<< setw(15) << "Ten khoa"
		<< setw(25) << "Truong khoa" << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\n\t" << setw(15) << x[i].makhoa
			<< setw(15) << x[i].tenkhoa
			<< setw(25) << x[i].truongkhoa << endl;
	}
	cout<<"\n\n\tBang ban: "<< endl;
	cout<<"\n\t" << setw(15) << "Ma ban"
		<< setw(15) << "Ten ban"
		<< setw(15) << "Truong ban" << endl;
	for(int i = 0; i < m; i++)
	{
		cout<<"\n\t" << setw(15) << y[i].maban
			<< setw(15) << y[i].tenban
			<< setw(15) << y[i].ngaythanhlap << endl;
	}
}

truongdh::~truongdh(){
	delete[] x;
	delete[] y;
}

void deleteItem(truongdh &dh)
{
	int count = 0;
	for(int i = 0; i < dh.n; i++)
	{
		if(strcmp(dh.x[i].makhoa,"QTKD") == 0)
		{
			count++;
			break;
		}
	}
	if(count == 0)
	{
		cout<<"\n\nTrong truong khong khoa nao co ma QTKD" << endl;
	}else {
		cout<<"\n\n\t================ THONG TIN TRUONG DAI HOC SAU KHI SUA ================" << endl;
		for(int i = 0; i < dh.n ; i++)
		{
			if(strcmp(dh.x[i].makhoa,"QTKD") == 0)
			{
				for(int j = i; j < dh.n; j++)
				{
					dh.x[j] = dh.x[j+1];
				}
				dh.n--;
			}
		}
		dh.xuat();
	}
}

int main()
{
	truongdh dh;
	dh.nhap();
	cout<<"\n\t================ THONG TIN TRUONG DAI HOC ================" << endl;
	dh.xuat();
	deleteItem(dh);
	return 0;
}
/*
DHCNHN
CONG NGHIEP HA NOI
HA NOI
5
CNTT
CNTT
Nguyen Van Lan
QTKD
QTKD
Nguyen Thi Anh
DT
Dien Tu
Nguyen Van Nam
KT
Kinh te
Nguyen Van Anh
HH
Hoa Hoc
Nguyen Ha Trang
3
B01
Truyen thong
12/5/2008
B02
Dao tao
6/7/2009
B03
Phat trien
10/11/2017
*/
