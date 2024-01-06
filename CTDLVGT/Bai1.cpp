#include<bits/stdc++.h>
using namespace std;
#define n 5

struct SV {
	char hoten[40];
	int age;
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

int full(LIST L) {
	return (L.count == n - 1);
}

int add(LIST &L, SV a)
{
	if(full(L))
	{
		return 0;
	}
	L.count++;
	L.sv[L.count] = a;
	return 1;
}

void input(SV &sv)
{
	cout<<"\nNhap ho ten sinh vien: ";			fflush(stdin);			gets(sv.hoten);
	if(strcmp(sv.hoten,"**") == 0) return ;
	cout<<"\nNhap tuoi cua sinh vien: ";								cin>>sv.age;
	cout<<"\nNhap diem cua sinh vien: ";								cin>>sv.diem;
}

void inputList(LIST &L)
{
	create(L);
	SV a;
	int i = 1;
	do{
		cout<<"\nNhap thong tin sinh vien thu " << i << endl;
		input(a);
		if(strcmp(a.hoten,"**")==0) return;
		if(!add(L,a)) return;
		i++;
	}while(1);
}

void xuat(LIST L)
{
	cout<<"\n\t" << "STT"
		<< setw(23) << "Ho ten"
		<< setw(10) << "Tuoi"
		<< setw(10) << "Diem";
	for(int i = 0; i <= L.count; i++)
	{
		cout<<"\n\t" << i + 1
		<< setw(25) << L.sv[i].hoten
		<< setw(10) << L.sv[i].age
		<< setw(10) << L.sv[i].diem;
	}
}

void xoa(LIST &L)
{
	int k;
	if(empty(L))
	{
		cout<<"\nDanh sach dang rong nen khong the xoa duoc!";
		return;
	}else{
		do{
			cout<<"\nNhap vi tri xoa 0 <= k <= " << L.count << ": ";			cin>>k;
		}while(k < 0 || k > L.count);
		for(int i = k; i <= L.count; i++)
		{
			L.sv[i] = L.sv[i+1];
		}
		L.count--;
		cout<<"\n\t==== DANH SACH SINH VIEN SAU KHI XOA SINH VIEN THU " << k + 1 << " ====" << endl;
		xuat(L);
	}
}

void chen(LIST &L)
{
	if(full(L)){
		cout<<"\nDanh sach da day nen khong the chen!";
		return;
	}else{
		int k;
		do{
			cout<<"\nNhap vi tri can chen 0 <= k <= " << L.count << ": ";			cin>>k;
		}while(k < 0 || k > L.count);
		SV a;
		cout<<"\nNhap thong tin sinh vien can bo sung"<< endl;
		input(a);
		if(strcmp(a.hoten,"**")==0)
		{
			cout<<"\nXin loi vi thong tin ban nhap sai nen chuong trinh khong the chen!";
			return;
		}
		L.count++;
		for(int i = L.count ; i >= k; i--)
		{
			L.sv[i] = L.sv[i-1];
		}
		L.sv[k] = a;
		cout<<"\n==== DANH SACH SINH VIEN SAU KHI BO SUNG ====" << endl;
		xuat(L);
	}
}

void sx(LIST &L)
{
	for(int i = 0; i <= L.count; i++)
	{
		for(int j = i + 1; j <= L.count; j++)
		{
			if(strcasecmp(L.sv[i].hoten, L.sv[j].hoten) > 0)
			{
				SV a = L.sv[i];
				L.sv[i] =L.sv[j];
				L.sv[j] = a;
			}
		}
	}
}

main()
{
	LIST a;
	inputList(a);
	xuat(a);
	xoa(a);
	chen(a);
	sx(a);
	cout<<"\n\t==== DANH SACH SINH VIEN SAU KHI SAP XEP TANG DAN THEO TEN ====" << endl;
	xuat(a);
}

/*
Nguyen Thi Trang
18
10
Dao Thu Trang
18
10
Luong Thi Thao Trang
18
10
*/
