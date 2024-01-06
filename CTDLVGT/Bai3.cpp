//#include<bits/stdc++.h>
//using namespace std;
//#define n 100
//
//struct SV {
//	char hoten[40];
//	char gioitinh[15];
//	int age;
//	float diem;
//};
//
//struct LIST {
//	int count;
//	SV sv[n];
//};
//
//int empty(LIST L)
//{
//	return (L.count == -1);
//}
//
//int full(LIST L)
//{
//	return (L.count == n - 1);
//}
//
//void create(LIST &L)
//{
//	L.count = -1;
//}
//
//int add(LIST &L, SV a)
//{
//	if(full(L)) return 0;
//	else{
//		L.count++;
//		L.sv[L.count] = a;
//		return 1;
//	}
//}
//
//void nhap(SV &sv)
//{
//	cout<<"\nNhap ho ten sinh vien: ";				fflush(stdin);			gets(sv.hoten);
//	if(strcmp(sv.hoten,"**") == 0) return;
//	cout<<"\nNhap gioi tinh cua sinh vien: ";		fflush(stdin);			gets(sv.gioitinh);
//	do{
//		cout<<"\nNhap tuoi cua sinh vien: ";								cin>>sv.age;
//	}while(sv.age < 0);
//	do{
//		cout<<"\nNhap diem tong ket cua sinh vien: ";						cin>>sv.diem;
//	}while(sv.diem < 0 || sv.diem > 10);
//}
//
//void nhapds(LIST &L)
//{
//	SV a;
//	int i = 1;
//	create(L);
//	do{
//		cout<<"\nNhap thong tin sinh vien thu " << i << endl;
//		nhap(a);
//		if(strcmp(a.hoten, "**")==0) return;
//		if(!add(L,a)) return;
//		i++;
//	}while(1);
//}
//
//void xuat(LIST L)
//{
//	if(empty(L)){
//		cout<<"\nDanh sach rong!";
//		return;
//	}else{
//		cout<<"\n\t" << "STT"
//			<<setw(30) << "Ho ten"
//			<<setw(15) << "Gioi tinh"
//			<<setw(15) << "Tuoi"
//			<<setw(15) << "Diem TK";
//		for(int i = 0; i <= L.count; i++)
//		{
//			cout<<"\n\t" << i + 1
//				<<setw(32) << L.sv[i].hoten
//				<<setw(15) << L.sv[i].gioitinh
//				<<setw(15) << L.sv[i].age
//				<<setw(15) << L.sv[i].diem;
//		}
//	}
//}
//
//main()
//{
//	LIST a;
//	nhapds(a);
//	xuat(a);
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//struct SV {
//	char hoten[40];
//	char gioitinh[15];
//	int tuoi;
//	float diem;
//};
//
//struct NODE {
//	SV infor;
//	NODE *next;
//};
//
//
//typedef NODE* TRO;
//
//int empty(TRO L)
//{
//	return L == NULL;
//}
//
//void create(TRO &L)
//{
//	L = NULL;
//}
//
//void nhap(SV &sv)
//{
//	cout<<"\nNhap ho ten sinh vien: ";			fflush(stdin);		gets(sv.hoten);
//	if(strcmp(sv.hoten,"**") == 0) return;
//	cout<<"\nNhap gioi tinh cua sinh vien: ";	fflush(stdin);		gets(sv.gioitinh);
//	do{
//		cout<<"\nNhap tuoi cua sinh vien: ";						cin>>sv.tuoi;
//	}while(sv.tuoi < 0);
//	do{
//		cout<<"\nNhap diem tong ket cua sinh vien: ";				cin>>sv.diem;
//	}while(sv.diem < 0 || sv.diem > 10);
//}
//
//void nhapds(TRO &L)
//{
//	create(L);
//	SV a;
//	TRO Q,P;
//	int i = 1;
//	do{
//		cout<<"\nNhap thong tin sinh vien thu " << i << endl;
//		nhap(a);
//		if(strcmp(a.hoten, "**") == 0) return;
//		P = new (NODE);
//		P->infor = a;
//		P->next = NULL;
//		if(L == NULL) L = P;
//		else Q->next = P;
//		Q = P;
//		i++;
//	}while(1);
//}
//
//void hienthi(TRO L)
//{
//	if(empty(L))
//	{
//		cout<<"\nDanh sach rong!";
//		return;
//	}else{
//		cout<<"\n\t" << "STT"
//			<<setw(30) << "Ho ten"
//			<<setw(15) << "Gioi tinh"
//			<<setw(15) << "Tuoi"
//			<<setw(15) << "Diem";
//			TRO Q = L;
//			int i = 0;
//			while(Q != NULL)
//			{
//				SV a = Q->infor;
//				cout<<"\n\t" << i + 1
//					<<setw(32) << a.hoten
//					<<setw(15) << a.gioitinh
//					<<setw(15) << a.tuoi
//					<<setw(15) << a.diem;
//				Q = Q->next;
//				
//			}
//	}
//}
//
//main()
//{
//	TRO a;
//	nhapds(a);
//	hienthi(a);
//}

#include<bits/stdc++.h>
using namespace std;

struct SV {
	char hoten[40];
	char gioitinh[15];
	int tuoi;
	float diem;
};

struct NODE {
	SV infor;
	NODE *next;
};

typedef NODE* TRO;

int empty(TRO L)
{
	return (L==NULL);
}

void create(TRO &L)
{
	L = NULL;
}

void nhap(SV &a)
{
	cout<<"\nNhap ho ten sinh vien: ";				fflush(stdin);			gets(a.hoten);
	if(strcmp(a.hoten, "**") == 0) return;
	cout<<"\nNhap gioi tinh sinh vien: ";			fflush(stdin);			gets(a.gioitinh);
	do{
		cout<<"\nNhap tuoi cua sinh vien: ";								cin>>a.tuoi;
	}while(a.tuoi < 0);
	do{
		cout<<"\nNhap diem tong ket cua sinh vien: ";						cin>>a.diem;
	}while(a.diem < 0 || a.diem > 10);
}

void nhapds(TRO &L)
{
	create(L);
	SV a;
	int i = 1;
	TRO P, Q;
	do{
		cout<<"\nNhap thong tin cua sinh vien thu " << i << endl;
		P = new (NODE);
		nhap(a);
		if(strcmp(a.hoten, "**") == 0) return;
		P->infor = a;
		P->next = NULL;
		if(empty(L)) L = P;
		else Q->next = P;
		Q = P;
		i++;
	}while(1);
}

void xuat(TRO L)
{
	if(empty(L))
	{
		cout<<"\nDanh sach rong!";
		return;
	}else{
		int i = 0;
		TRO Q = L;
		cout<<"\n\t" << "STT"
			<< setw(30) << "Ho ten"
			<< setw(15) << "Gioi tinh"
			<< setw(15) << "Tuoi"
			<< setw(15) << "Diem TK";
		while(Q != NULL)
		{
			SV a = Q->infor;
			cout<<"\n\t" << i + 1
				<< setw(32) << a.hoten
				<< setw(15) << a.gioitinh
				<< setw(15) << a.tuoi
				<< setw(15) << a.diem;
			Q = Q->next;
		}
	}
}

// xac dinh chieu dai cua danh sach
int size(TRO L)
{
	int count = 0;
	TRO Q = L;
	while(!empty(Q))
	{
		Q = Q->next;
		count++;
	}
	return count;
}

// Xoa sinh vien dau tien cua danh sach
void xoasvdau(TRO &L)
{
	if(empty(L))
	{
		cout<<"\nDanh sach rong nen khong the xoa!";
		return;
	}else{
		TRO Q = L;
		L = L->next;
		delete Q;
		cout<<"\n\t==== DANH SACH SINH VIEN SAU KHI XOA SINH VIEN DAU ====" << endl;
		xuat(L);
	}
}

TRO timkiem(TRO L, char *hoten)
{
	TRO Q = L;
	while(!empty(Q) && strcmp(Q->infor.hoten, hiten)!=0)
	{
		Q = Q->next;
	}
	return TRO;
}

void xoa(TRO &L, TRO T)
{
	TRO Q;
	if(T == L)
	{
		L = T->next;
	}else{
		Q = L;
		while(Q->next != T)
		{
			
		}
	}
}
main()
{
	TRO a;
	nhapds(a);
	xuat(a);
	cout<<"\nDo dai cua danh sach la: " << size(L);
}
