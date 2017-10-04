#include<bits/stdc++.h>
#define N 500005
#define a(x,y) a[x*(m+10)+(y)]
#define b(x,y) b[x*(m+10)+(y)]
#define c(x,y) c[x*(m+10)+(y)]
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=x*10-48+ch;
	return x*f;
}
int a[N],b[N],c[N],d[N];
int bin[1050],vis[1050];
int n,m,ans;
int main(){
	freopen("b.in","r",stdin);
	freopen("bl.out","w",stdout);
	n=read(); m=read();
	for (int i=0;i<=9;i++) bin[1<<i]=i;
	if (n<m){
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				a(i,j)=read();
	}
	else{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				a[j*(n+10)+i]=read();
		swap(n,m);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			b(i,j)=b(i-1,j)+a(i,j);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			b(i,j)=b(i,j-1)+b(i,j);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			c(i,j)=c(i-1,j)^(1<<a(i,j));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			c(i,j)=c(i,j-1)^c(i,j);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=i;k++)
				for (int l=1;l<=j;l++){
					int x=c(i,j)^c(k-1,j)^c(i,l-1)^c(k-1,l-1);
					int s=b(i,j)-b(k-1,j)-b(i,l-1)+b(k-1,l-1);
					if (x==(x&(-x))&&s!=bin[x]&&(i-k+1)*(j-l+1)>ans)
						ans=(i-k+1)*(j-l+1);
				}
	printf("%d",ans);
}
