#include<bits/stdc++.h>
using namespace std;
class LopHoc;
class Nguoi{ 
protected:
	char Hoten[20];
	char Ngaysinh[20];
	char Quequan[30];
	public:
		void nhap();
		void xuat();
};
class SinhVien:public Nguoi{
	char Masv[20];
	char Nganh[20];
	int khoa; // khoa VD: K16
	public:
		void nhap();
		void xuat();
	friend void IN_Khoa11(LopHoc a);
	friend void SX_Sokhoa(LopHoc &a);
};
class LopHoc{
	char Malh[20];
	char Tenlh[20];
	char Ngaymo[20];
	SinhVien *x;
	int n;
	char GiaoVien[20];
	public:
		~LopHoc();
		void nhap();
		void xuat();
	friend void IN_Khoa11(LopHoc a);
	friend void SX_Sokhoa(LopHoc &a);
};

void Nguoi::nhap(){
	cout <<"\nNhap ho ten: "; 					fflush(stdin);					 gets(Hoten);
	cout <<"\nNhap ngay sinh: "; 				fflush(stdin); 					 gets(Ngaysinh);
	cout <<"\nNhap que quan: "; 				fflush(stdin); 					 gets(Quequan);
}

void Nguoi::xuat(){
	cout<<setw(22) << Hoten 
		<< setw(20) << Ngaysinh 
		<< setw(20) << Quequan ;
}

void SinhVien::nhap(){
	Nguoi::nhap();
	cout <<"\nNhap ma sinh vien: "; 			fflush(stdin); 					  gets(Masv);
	cout <<"\nNhap nganh: "; 					fflush(stdin);					  gets(Nganh);
	cout <<"\nNhap khoa: "; 													  cin>>khoa;
	
}

void SinhVien::xuat(){
	Nguoi::xuat();
	cout << setw(22) << Masv 
		 << setw(20) << Nganh 
		 << setw(10) << khoa << endl ;
}

void LopHoc::nhap(){
	cout <<"\nNhap ma lop hoc: "; 				fflush(stdin); 					  gets(Malh);
	cout <<"\nNhap ten lop hoc: "; 				fflush(stdin); 					  gets(Tenlh);
	cout <<"\nNhap ngay mo: ";                  fflush(stdin); 					  gets(Ngaymo);
	cout <<"\nNhap giao vien: ";                fflush(stdin);    				  gets(GiaoVien);
	cout <<"\nNhap so sinh vien trong lop: "; 									  cin >> n;
	x = new SinhVien[n];
	for(int i=0; i<n; i++){
		cout<<"\n==== NHAP THONG TIN SINH VIEN THU " << i + 1 << "====" << endl;
		x[i].nhap();
	}
	
}

void LopHoc::xuat(){
	cout<<"\n\t\t\t\t==== THONG TIN CUA LOP HOC ====" << endl;
	cout<<"\n\tMa lop hoc: " << Malh <<"\t\t\tTen lop hoc: "<< Tenlh <<endl;
	cout<<"\n\tNgay mo: "<< Ngaymo << "\t\t\tMa lop hoc: " << Malh << endl;
	cout<<"\n\t\t" << "Ho ten" 
		<< setw(20)<<"Ngay Sinh" 
		<< setw(20) << "Que quan"
	 	<< setw(22) << "Ma sv" 
		<< setw(20) << "Nganh" 
		<< setw(10) << "Khoa" << endl ;
	for(int i=0; i<n; i++){
		x[i].xuat();
	}

}

void IN_Khoa11(LopHoc a){
	int cnt =0;
	for(int i=0; i< a.n; i++){
		if(a.x[i].khoa == 11) cnt++;
	}
	cout <<"\n Co so sinh vien khoa 11 la : "<< cnt << endl;
}

// Ham nay bi loi a, khi em comment cai ham huy vao thi duoc a

void SX_Sokhoa(LopHoc &a){
	for(int i=0; i < a.n; i++){
		for(int j = i + 1; j < a.n; j++){
			if(a.x[i].khoa > a.x[j].khoa) swap(a.x[i], a.x[j]);
		}
	}
}

int main(){
	LopHoc a;
	a.nhap();
	cout << endl;
	a.xuat();
	IN_Khoa11(a);
	SX_Sokhoa(a);								
	cout << endl;
	a.xuat();
}
LopHoc::~LopHoc()
{
	delete x;
}

/*
LH01
LTHDT
12/2/2023
Nguyen Thi Lan
3
Nguyen Thi Trang
12/10/2003
Hung Yen
2021604432
KTPM03
16
Nguyen Thi Ha
12/5/2003
Ha Noi
2021605588
QTKD03
16
Nguyen Van Minh
17/8/2003
Ha Nam
2021605566
KTPM03
11
*/
