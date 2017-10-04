#include<bits/stdc++.h>
#define N 500005
#define a(x,y) a[x*(m+10)+(y)]
#define b(x,y) b[x*(m+10)+(y)]
#define c(x,y) c[x*(m+10)+(y)]
#define e(x,y,z) e[x][y*(m+10)+z]
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
int a[N],b[N],c[N],d[N],e[12][N];
int bin[1050],vis[1050];
int n,m,ans=1;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
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
			b(i,j)=b(i,j)+b(i,j-1);
	for (int p=0;p<10;p++){
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				e(p,i,j)=e(p,i-1,j)+(a(i,j)==p);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				e(p,i,j)=e(p,i,j)+e(p,i,j-1);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			c(i,j)=c(i-1,j)^(1<<a(i,j));
	d[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			memset(vis,-1,sizeof(vis));
			for (int k=1;k<=m;k++)
				d[k]=d[k-1]^(c(j,k)^c(i-1,k));
			vis[0]=0;
			for (int k=1;k<=m;k++){
				for (int x=0;x<=10;x++){
					int p=d[k]^(x==10?0:1<<x);
					if (vis[p]!=-1){
						int la=vis[p];
						if (b(j,k)-b(j,la)-b(i-1,k)+b(i-1,la)!=x)
							if (e(x,j,k)-e(x,j,la)-e(x,i-1,k)+e(x,i-1,la)&&(j-i+1)*(k-la)>ans)
								ans=(j-i+1)*(k-la);
					}
				}
				if (vis[d[k]]==-1)
					vis[d[k]]=k;
			}
		}
	printf("%d\n",ans);
}
