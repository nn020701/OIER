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
struct node{
	int d,b;
	int x,y;
}ship[100010];
int a[100010];
int n,m,ans;
int f1[100010],f2[100010];
int main(){
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	n=read();
	int l;
	for(int i=1;i<=n;i++){
		l=read();
		a[i]=a[i-1]+l;
	}
	m=read();
	for(int i=1;i<=m;i++){
		ship[i].b=read();
		ship[i].d=read();
		ship[i].x=max(1,ship[i].b-ship[i].d+1);
		ship[i].y=min(n,ship[i].b+ship[i].d-1)-ship[i].d+1;
	}
	for(int i=ship[1].x;i<=ship[1].y;i++){
		f2[i]=a[i+ship[1].d-1]-a[i-1];
		ans=max(ans,f2[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=ship[i].x;j<=ship[i].y;j++){
			for(int k=ship[i-1].x;k<=ship[i-1].y;k++)
				if(k+ship[i-1].d-1<j)
					f1[j]=max(f1[j],f2[k]+a[j+ship[i].d-1]-a[j-1]);
				else
					break;
			ans=max(ans,f1[j]);
		}
		for(int j=ship[i].x;j<=ship[i].y;j++)
			f2[j]=f1[j];
	}
	printf("%d\n",ans);
	return 0;
}
