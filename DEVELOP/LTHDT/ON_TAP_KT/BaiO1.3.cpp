#include<bits/stdc++.h>
using namespace std;

class PHIEU;

class NV {
	private:
		char hoten[40];
		char chucvu[40];
	public:
		void nhap();
		void xuat();
};

class PHONG{
	private:
		char tenphong[40];
		char maphong[20];
		char tentp[40];
	public:
		void nhap();
		void xuat();
};

class MAY {
	private:
		char tents[40];
		int sl;
		char tinhtrang[40];
	public:
		void nhap();
		void xuat();
	friend class PHIEU;
	friend void sua(PHIEU a);
	friend void sx(PHIEU &a);
};

class PHIEU {
	private:
		char maphieu[20];
		char ngaykiem[40];
		NV a;
		PHONG b;
		int n;
		MAY *c;
	public:
		void nhap();
		void xuat();
	friend void sua(PHIEU a);
	friend void sx(PHIEU &a);
};

void NV::nhap(){
	cout<<"\nNhap ten nhan vien kiem ke: ";				fflush(stdin);			gets(hoten);
	cout<<"\nNhap chuc vu cua nhan vien: ";				fflush(stdin);			gets(chucvu);
}

void NV::xuat() {
	cout<<"\n\tNhan vien kiem ke: " << hoten << "\t\tChuc vu: " << chucvu;
}

void PHONG::nhap() {
	cout<<"\nNhap ma phong: ";							fflush(stdin);			gets(maphong);
	cout<<"\nNhap ten phong kiem ke: ";					fflush(stdin);			gets(tenphong);
	cout<<"\nNhap ten truong phong: ";					fflush(stdin);			gets(tentp);
}

void PHONG::xuat(){
	cout<<"\n\tKiem ke tai phong: " << tenphong << "\t\tMa phong: " << maphong;
	cout<<"\n\tTruong phong: " << tentp;
}

void MAY::nhap() {
	cout<<"\nNhap ten tai san: " ;						fflush(stdin);			gets(tents);
	cout<<"\nNhap so luong tai san: ";											cin>>sl;
	cout<<"\nNhap tinh trang tai san: ";				fflush(stdin);			gets(tinhtrang);
}

void MAY::xuat() {
	cout<<"\n\t" << setw(15) << tents
		<< setw(15) << sl
		<<setw(25) << tinhtrang;
}

void PHIEU::nhap() {
	cout<<"\n============ NHAP THONG TIN CUA PHIEU ============" << endl;
	cout<<"\nNhap ma phieu: ";							fflush(stdin);			gets(maphieu);
	cout<<"\nNhap ngay kiem ke: ";						fflush(stdin);			gets(ngaykiem);
	a.nhap();
	b.nhap();
	
	do{
		cout<<"\nNhap so luong tai san cua phong n > 0: ";							cin>>n;
	}while(n < 1);
	
	c = new MAY[n];
		for(int i = 0; i < n; i++)
		{
			cout<<"\n==== NHAP THONG TIN TAI SAN THU " << i + 1 << " ====" << endl;
			c[i].nhap();
		}
}


void PHIEU::xuat() {
	cout<<"\n\tMa phieu: " << maphieu << "\t\t\t\t\tNgay kiem ke: " << ngaykiem;
	a.xuat();
	b.xuat();
	cout<<endl;
	cout<<"\n\t" << setw(15) << "Ten tai san"
		<< setw(15) << "So luong"
		<<setw(25) << "Tinh trang";
	for(int i = 0; i < n; i++) {
		c[i].xuat();
	}
	
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += c[i].sl;
	}
	
	cout<<"\n\n\tSo tai san da kiem ke: " << n << "\t\tTong so luong: " << sum;
}

void sua(PHIEU a)
{
	int dem ;
	for(int i = 0; i < a.n; i++) {
		if(strcmp(a.c[i].tents, "May vi tinh") == 0)
		{
			dem = 1;
		}
	}
	if(dem == 1)
	{
		for(int i = 0; i < a.n; i++) {
			if(strcmp(a.c[i].tents, "May vi tinh") == 0)
			{
				a.c[i].sl = 20;
			}
		}
		cout<<"\n\nDa sua so luong cua tai san co ten la May vi tinh thanh 20";
	}else{
		cout<<"\n\nKhong co tai san co ten la May vi tinh nen khong the sua";
	}
}

void sx(PHIEU &a)
{
	for(int i = 0; i < a.n - 1; i++)
	{
		for(int j =  i + 1; j < a.n; j++){
			if(a.c[i].sl > a.c[j].sl)
			{
				MAY tg = a.c[i];
				a.c[i] = a.c[j];
				a.c[j] = tg;
			}
		}
	}
}

main()
{
	PHIEU a;
	a.nhap();
	cout<<"\n\t\t\t============ PHIEU KIEM KE TAI SAN ============" << endl;
	a.xuat();
	sua(a);
	sx(a);
	cout<<"\n\n============ PHIEU KIEM KE TAI SAN SAU KHI SAP XEP TANG DAN THEO SO LUONG ============" << endl;
	a.xuat();
}

/*
PH01
1/1/2007
Kieu Thi Thanh
Ke toan vien
PTC
To chuc hanh chinh
Hoang Bich Hao
3
May vi tinh
5
Tot
May vi tinh
3
Het khau hao - hong
Ban lam viec
6
Tot
*/
