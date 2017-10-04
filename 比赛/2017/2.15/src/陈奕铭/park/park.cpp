#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
int a[1010];
int p[1010];
long long num,now;
int main(){
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
		a[i]=read();
	long long l=1,r=(1LL<<60);
	while(l<r){
		long long mid=(l+r)/2;
		num=0;
		for(int i=1;i<=m;i++){
			num+=mid/a[i]+1;
			if(num>=n)
				break;
		}
		if(num>=n)
			r=mid;
		else
			l=mid+1;
	}
	for(int i=1;i<=m;i++)
		now+=(r-1)/a[i]+1;
	for(int i=1;i<=m;i++)
		if(r%a[i]==0)
		{
			now++;
			if(now==n)
			{
				printf("%d\n",i);
				return 0;
			}
		}
	return 0;
}
