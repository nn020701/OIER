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
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)scanf("%d",&a[i]);
	for (int i=1;i<=n;++i){
		int min1=oo,min2=oo,max1=-oo,max2=-oo;
		for (int j=i-1;j&&a[j]<=a[i];--j)
			min1=min(min1,a[j]),max1=max(max1,a[j]);
		for (int j=i+1;j<=n&&a[j]<=a[i];++j)
			min2=min(min2,a[j]),max2=max(max2,a[j]);
		if (min1==oo||min2==oo){printf("-1\n");continue;}
		printf("%d\n",max(abs(max1-min2),abs(max2-min1)));
	}
	//system("pause");
	return 0;
}


