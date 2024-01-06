#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhapn(int *n)
{
	do{
		printf("Nhap n: ");
		scanf("%d", n);
	}while(*n<=2 || *n>=30);
}
void nhapmang(int a[30], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void xuatmang(int a[30],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}
int giatrituyetdoi(int a[30], int n)
{
	int i, max = abs(a[0]);
	for(i = 1; i < n ;i++)
	{
		if(max < abs(a[i])){
			max = abs(a[i]);
		}
	}
	return max;
}
float xoaphantule(int a[30], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=a[2*i];
		if(n%2!=0){
			a[i+1]=a[n-1];
		}
	}return a[i];
}
int le(int a[30], int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if (a[0]%2!=0){
			printf("%d", a[0]);
		}else{
			return -1;
		}
	}
		return a[0];
}
int main()
{
	int n, a[30];
	nhapn(&n);
	nhapmang(a,n);
	xuatmang(a,n);
	printf("\n%d", abs(-9));
	printf("\nGia tri tuyet doi lon nhat la: %d",giatrituyetdoi(a,n));
	printf("\nPhan tu le dau tien la: %d", le(a,n));
	printf("\nMang sau khi xoa: %d", xoaphantule(a,n));
	return 0;
}


