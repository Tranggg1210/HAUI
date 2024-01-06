#include<bits/stdc++.h>
using namespace std;

struct SINHVIEN
{
	char hodem[20];
	char ten[10];
	char masv[10];
	int namsinh;
	float diemtk;
};

struct Node
{
	SINHVIEN infor;
	Node *next;
};

//typedef TRO *Node;

typedef Node *TRO;
void Create(TRO &L)
{
	L=NULL;
}

int Empty(TRO L)
{
	return L==NULL;
}

void NhapSV(SINHVIEN &sv)
{
	cout<<"\tNhap ma sinh vien: ";		fflush(stdin);	gets(sv.masv);
	if(strcmp(sv.masv,"***")==0)		
		return;
	cout<<"\tNhap ho dem sinh vien: ";	fflush(stdin);	gets(sv.hodem);
	cout<<"\tNhap ten: ";				fflush(stdin);	gets(sv.ten);
	cout<<"\tNhap nam sinh: ";			cin>>sv.namsinh;
	cout<<"\tNhap diemtk: ";			cin>>sv.diemtk;
}

void NhapDS(TRO &L)
{
	Create(L);
	SINHVIEN X;
	int i=1;
	TRO Q,P;
	do{
		cout<<"\nNhap thong tin sinh vien thu "<<i<<endl;
		NhapSV(X);
		if(strcmp(X.masv,"***")==0)		
			return;
	P=new (Node);
	P->infor=X;
	P->next=NULL;
	if(L==NULL)
		L=P;
	else
		Q->next=P;
	Q=P;
	i++;
	}while(1);
}

void HienThiDS(TRO L)
{
	if(L==NULL)
	{
		cout<<"Danh sach rong\n";
		return;
	}
		cout<<endl;
		cout<<setw(5)<<"MASV";
		cout<<setw(10)<<"HO DEM";
		cout<<setw(10)<<"TEN";
		cout<<setw(5)<<"YEAR";
		cout<<setw(5)<<"DIEMTK"<<endl;
	TRO Q=L;
	int i=1;
	while(Q!=NULL){
		SINHVIEN X=Q->infor;
		cout<<setw(5)<<X.masv;
		cout<<setw(10)<<X.hodem;
		cout<<setw(10)<<X.ten;
		cout<<setw(5)<<X.namsinh;
		cout<<setw(5)<<X.diemtk<<endl;
	Q=Q->next;
	}
}


// ham chen tai vi tri k trong danh sach
void FirstAdd(TRO &L, SINHVIEN X)
{
	TRO P;
	P=new Node;
	P->infor=X;
	P->next=L;
	L=P;
	
}

int Length(TRO &L)
{
	int d=1;
	TRO Q=L;
	while(Q!=NULL)
	{
		d++;
		Q=Q->next;
	}
	return n;
}
void InsertSort(TRO &L, TRO Q, SINHVIEN X)
{
	TRO P;
	P=new Node;
	P->infor=X;
	P->next=Q->next;
	Q->next=P;
}

void BoSung(TRO &L)
{
	int k;
	do{
		cout<<"\tNhap vi tri can chen: ";
		cin>>k;
	}while(k<1 || k> Length(L));
	cout<<"\tNhap thong tin sinh vien can chen: ";
	do{
		
	}
}
int main()
{
	TRO L;
	NhapDS(L);
	//cout<<"Nhap thong tin sinh vien\n";
	//cout<<"\n==========================================";
	cout<<"Danh sach sinh vien";
	//cout<<"\n==========================================";
	HienThiDS( L);
}

//12466
//pham
//linh
//1998
//10
