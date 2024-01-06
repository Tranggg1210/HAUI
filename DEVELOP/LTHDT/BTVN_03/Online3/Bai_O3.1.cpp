#include<bits/stdc++.h>
using namespace std;

class arr {
	private:
		float *VALUE;
		int n;
	public:
		friend istream& operator>>(istream& in, arr &x);
		friend ostream& operator<<(ostream& out, arr x);
		arr operator++();
		arr operator--();
};

arr arr::operator++() {
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(VALUE[i] > VALUE[j])
			{
				swap(VALUE[i],VALUE[j]);
			}
		}
	}
	return *this;
}

arr arr::operator--() {
		for(int i = 0; i < n; i++)
	{
		for(int j =  i + 1; j < n; j++)
		{
			if(VALUE[i] < VALUE[j])
			{
				swap(VALUE[i],VALUE[j]);
			}
		}
	}
	return *this;
}

istream& operator>>(istream& in, arr &x) {
	do{
		cout<<"\nNhap so luong phan tu mang n > 0: ";						in>>x.n;
	}while(x.n < 1);
	
	x.VALUE = new float[x.n];
	for(int i = 0; i < x.n; i++)
	{
		cout<<"\nNhap value[" << i << "]: ";								in>>x.VALUE[i];
	}
return in;
}

ostream& operator<<(ostream& out, arr x)
{
	for(int i = 0; i < x.n; i++)
	{
		out<<x.VALUE[i] << "\t";
	}
return out;
}

main()
{
	arr a;
	cin >> a;
	cout<<"\nMang vua nhap la: "<< a;
	cout<<"\nMang sau khi sap xep tang dan la: " << ++a;
	cout<<"\nMang sau khi sap xep giam dan la: " << --a;
	
	ofstream ghi("MANG.txt");
	ghi<<"\nMang vua nhap la: "<< a;
	ghi<<"\nMang sau khi sap xep tang dan la: " << ++a;
	ghi<<"\nMang sau khi sap xep giam dan la: " << --a;
}
