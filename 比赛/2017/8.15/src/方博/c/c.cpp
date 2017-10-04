#include<bits/stdc++.h>
using namespace std;
bool a[10005][10005];
int f[50005];
bool b[10005];
int n,m,t;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();
	m=read();
//	n=10000;
//	m=50000;
//	srand(time(0));
	for(int i=1;i<=m;i++){
		int x,l,k;
		x=read();
//		x=rand()%n+1;
		l=read();
//		l=rand()%5000;
		if(f[l]==0)t++,f[l]=t;
		l=f[l];
//		k=rand()%n;
		k=read();
		for(int j=max(x-k,0);j<=x+k&&j<=n;j++)
			if(a[l][j]==0)a[l][j]=1,b[j]=true;
			else b[j]=false;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(b[i]==false)ans++;
	printf("%d",ans);
	return 0;
}
