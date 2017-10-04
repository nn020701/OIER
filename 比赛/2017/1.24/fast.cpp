#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[20];
int data[20];
int n,i,h,ans,len;
void merge()
{
	data[h-1]=data[h-1]+data[h];
	h--;
	ans++;
}
int main()
{
	scanf("%d",&len);
	scanf("%s",&a);
	for(i=0;i<len;i++)
		n=n*2+a[i]-'0';
	h=1;
	data[h]=1;
	ans=0;
	for(i=2;i<=n;i++)
	{
		h++;
		data[h]=1;
		while(h>1&&data[h]==data[h-1])
			merge();
	}
	printf("%d",ans);
	return 0;
}
