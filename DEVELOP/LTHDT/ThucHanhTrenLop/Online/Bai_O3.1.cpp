//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

class SoPhuc {
	private:
		int phanthuc, phanao;
	public: 																										
//		SoPhuc(int a, int b);
//		SoPhuc();
//		void xuat();
	// ham toan tu cong co friend
//	friend SoPhuc operator+(SoPhuc sp1, SoPhuc sp2);

	// phuong thuc toan tu cong 2 so thuc - ko co friend
		//SoPhuc operator+(SoPhuc d); // cong hai so phuc
	
		//SoPhuc operator-(); // doi dau so phuc
	
	//Ham toan tu nhap
	friend istream& operator>>(istream& in, SoPhuc &a);
	//Ham toan tu xuat
	friend ostream& operator<<(ostream& out, SoPhuc b);
	
};

//SoPhuc::SoPhuc(int a, int b) {
//	phanthuc = a;
//	phanao = b;
//}
//
//SoPhuc::SoPhuc() {
//	phanthuc = 0;
//	phanao = 0;
//}

//void SoPhuc::xuat() {
//	if(phanao < 0){
//		cout<<"\nBieu thuc: " << phanthuc << " - " << -phanao << "i" << endl;
//	}else{
//		cout<<"\nBieu thuc: " << phanthuc << " + " << phanao << "i" << endl;
//	}
//}

//SoPhuc operator+(SoPhuc sp1, SoPhuc sp2)
//{
//	SoPhuc sum;
//	sum.phanthuc = sp1.phanthuc + sp2.phanthuc;
//	sum.phanao = sp1.phanao + sp2.phanao;
//return sum;
//}

//SoPhuc SoPhuc::operator+(SoPhuc d)
//{
//	SoPhuc s;
//	s.phanthuc = phanthuc + d.phanthuc;
//	s.phanao = phanao + d.phanao;
//return s;
//}
//
//SoPhuc SoPhuc::operator-(){
//	SoPhuc x;
//	x.phanthuc = -phanthuc;
//	x.phanao = -phanao;
//return x;
//}


istream& operator>>(istream& in, SoPhuc &a){
	cout<<"\nNhap phan thuc: ";					in>>a.phanthuc;
	cout<<"\nNhap phan ao: ";					in>>a.phanao;
	
return in;
}

ostream& operator<<(ostream& out, SoPhuc b)
{
	if(b.phanao < 0){
		out<<"\nBieu thuc: " << b.phanthuc << " - " << -b.phanao << "i" << endl;
	}else{
		out<<"\nBieu thuc: " << b.phanthuc << " + " << b.phanao << "i" << endl;
	}
}

int main()
{
//	SoPhuc sp1(3,-4);
//	sp1.xuat();
//	SoPhuc sp2(-6,-4);
//	sp2.xuat();
//	SoPhuc s;
//	s = sp1 + sp2;
//	s.xuat();
//	SoPhuc doidau;
//	doidau = -sp1;
//	doidau.xuat();
	
	SoPhuc a,b;
	cin>>a;
	cout<<endl;
	cin>>b;
	cout<<a;
	cout<<b;
	return 0;
}
