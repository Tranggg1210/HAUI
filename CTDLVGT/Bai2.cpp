#include<bits/stdc++.h>
using namespace std;
#define n 100

struct SV {
	char masv[10];
	char hodem[30];
	char ten[10];
	char gioitinh[15];
	int namsinh;
	float diem;
};

struct LIST {
	int count;
	SV sv[n];
};

void create(LIST &L)
{
	L.count = -1;
}

int empty(LIST L)
{
	return (L.count == -1);
}

int full(LIST L)
{
	return (L.count == n - 1);
}

int add(LIST &L, SV a)
{
	if(full(L)) return 0;
	else{
		L.count++;
		L.sv[L.count] = a;
		return 1;
	}
}

void nhap(SV &sv)
{
	cout<<"\nNhap ma sinh vien: ";				fflush(stdin);				gets(sv.masv);
	if(strcmp(sv.masv, "**")==0) return;
	cout<<"\nNhap ho dem cua sinh vien: ";		fflush(stdin);				gets(sv.hodem);
	cout<<"\nNhap ten sinh vien: ";				fflush(stdin);				gets(sv.ten);
	cout<<"\nNhap gioi tinh cua sinh vien: ";	fflush(stdin);				gets(sv.gioitinh);
	do{
		cout<<"\nNhap nam sinh cua sinh vien: ";							cin>>sv.namsinh;
	}while(sv.namsinh <= 0);
	do{
		cout<<"\nNhap diem tong ket cua sinh vien: ";						cin>>sv.diem;
	}while(sv.diem < 0 && sv.diem > 10);
}

void nhapDS(LIST &L)
{
	int i = 1;
	create(L);
	SV a;
	do{
		cout<<"\nNhap thong tin sinh vien thu " << i << endl;
		nhap(a);
		if(strcmp(a.masv, "**") == 0) return;
		if(!add(L,a)) return;
		i++;
	}while(1);
}

void xuat(LIST L)
{
	if(empty(L))
	{
		cout<<"\nDanh sach rong!";
		return;
	}else{
		cout<<"\n\t" << "STT"
			<<setw(10) << "Ma SV"
			<<setw(16) << "Ho dem"
			<<setw(15) << "Ten"
			<<setw(16) << "Gioi tinh"
			<<setw(15) << "Nam sinh"
			<<setw(15) << "Diem TK";
		for(int i = 0; i <= L.count; i++)
		{
			cout<<"\n\t" << i + 1
				<<setw(12) << L.sv[i].masv
				<<setw(16) << L.sv[i].hodem
				<<setw(15) << L.sv[i].ten
				<<setw(16) << L.sv[i].gioitinh
				<<setw(15) << L.sv[i].namsinh
				<<setw(15) << L.sv[i].diem;
		}
	}
//	cout<<L.count;
}

void xoa(LIST &L)
{
	if(empty(L))
	{
		cout<<"\nDanh sach rong nen khong the xoa!" << endl;
		return;
	}else{
		int k;
		do{
			cout<<"\nNhap vi tri phan thu can xoa 0 <= k <= " << L.count << ": ";		cin>>k;
		}while(k < 0 || k > L.count);
		for(int i = k; i <= L.count; i++)
		{
			L.sv[i] = L.sv[i+1];
		}
		L.count--;
		cout<<"\n\t\t==== DANH SACH SINH VIEN SAU KHI XOA PHAN TU THU " << k << " ====" << endl;
		xuat(L);
	}
}

void chen(LIST &L)
{
	SV a;
	int k;
	if(full(L))
	{
		cout<<"\nDanh sach da day len khong the chen";
		return;
	}else{
		if(empty(L))
		{
			cout<<"\nVi danh sach rong nen ta them phan tu vao cuoi danh sach";
			cout<<"\nNhap thong tin sinh vien can bo sung" << endl;
			nhap(a);
			add(L,a);
			cout<<"\n\t\t==== DANH SACH SINH VIEN SAU KHI CHEN ====" << endl;
			xuat(L);
			return;
		}else{
			do{
				cout<<"\nNhap vi tri phan thu can chen 0 <= k <= " << L.count + 1 << ": ";		cin>>k;
			}while(k < 0 || k > L.count + 1);
			nhap(a);
			for(int i = L.count; i >= k - 1; i--)
			{
				L.sv[i + 1] = L.sv[i];
			}
			L.count++;
			L.sv[k] = a;
			cout<<"\n\t\t==== DANH SACH SINH VIEN SAU KHI CHEN ====" << endl;
			xuat(L);
		}
	}
}

void sx(LIST &L)
{
	for(int i = 0; i <= L.count; i++)
	{
		for(int j = i + 1; j <= L.count; j++)
		{
			if(strcasecmp(L.sv[i].ten, L.sv[j].ten) > 0)
			{
				swap(L.sv[i], L.sv[j]);
			}
		}
	}
	cout<<"\n\t\t==== DANH SACH SINH VIEN SAU KHI SAP XEP ====" << endl;
	xuat(L);
}

main()
{
	LIST a;
	nhapDS(a);
	xuat(a);
	xoa(a);
	chen(a);
	sx(a);
}
/*
SV1001
Tran Van
Thanh
Nam
1999
7.5
SV1002
Nguyen Thi
Huong
Nu
2000
7.3
SV1003
Nguyen Van
Binh
Nam
1998
6.4
SV1004
Bui Thi
Hong
Nu
2000
5.8
SV1005
Duong Van
Giang 
Nam
2998
8.3
*/
