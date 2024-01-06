#include<bits/stdc++.h>
using namespace std;

class arr {
	private:
		int n;
		float *VALUE;
	public:
		arr operator++();
		arr operator--();
		friend istream& operator>>(istream& in, arr &x);
		friend ostream& operator<<(ostream& out, arr x);
};

istream& operator>>(istream& in, arr &x)
{
	do{
		cout<<"\nNhap so luong phan tu cua mang n > 0: ";					in>>x.n;
	}while(x.n < 1);
	x.VALUE = new float[x.n];
	
		for(int i = 0; i < x.n; i++)
		{
			cout<<"\nNhap VALUE[" << i << "]: ";							in>>x.VALUE[i];
		}
return in;
}

ostream& operator<<(ostream&out, arr x)
{
	for(int i = 0; i < x.n; i++)
	{
		out<<"\t" << x.VALUE[i];
	}
return out;
}

arr arr::operator++() {
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(VALUE[i] > VALUE[j])
			{
				float tg = VALUE[i];
				VALUE[i] = VALUE[j];
				VALUE[j] = tg;
			}
		}
	}
	return *this;
}

arr arr::operator--() {
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(VALUE[i] < VALUE[j])
			{
				float tg = VALUE[i];
				VALUE[i] = VALUE[j];
				VALUE[j] = tg;
			}
		}
	}
	return *this;
}

main()
{
	arr a;
	cin>>a;
	cout<<"\nMang vua nhap la: " << a;
	cout<<"\nMang sau khi sap xep tang dan: " << ++a;
	cout<<"\nMang sau khi sap xep giam dan: " << --a;
	
	ofstream ghi("MANG.txt");
	ghi<<"\nMang vua nhap la: " << a;
	ghi<<"\nMang sau khi sap xep tang dan: " << ++a;
	ghi<<"\nMang sau khi sap xep giam dan: " << --a;
	ghi.close();
}
