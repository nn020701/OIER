#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000005
#define oo (1<<30)
int a[N],n;
inline void read(int &x){
	char ch;int bo=0;x=0;
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
	for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
	if (bo)x=-x;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)read(a[i]);//scanf("%d",&a[i]);
	a[0]=a[n+1]=1<<30;
	for (register int i=1;i<=n;++i){
		int min1=oo,min2=oo,max1=-oo,max2=-oo;
		for (register int j=i-1;a[j]<=a[i];--j){
			if (a[j]<min1)min1=a[j];
			if (a[j]>max1)max1=a[j];
		}
		//min1=min(min1,a[j]),max1=max(max1,a[j]);
		for (register int j=i+1;a[j]<=a[i];++j){
			if (a[j]<min2)min2=a[j];
			if (a[j]>max2)max2=a[j];
		}
		if (min1==oo||min2==oo){printf("-1\n");continue;}
		printf("%d\n",max(abs(max1-min2),abs(max2-min1)));
	}
	//system("pause");
	return 0;
}


