#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#include <ctime>
#include <climits>
#include <cmath>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
int a[1010][4010],c[1010][4010],d[100010][4010];
bool b[100010],bk[100010];
int n,m,ak[100010],lk[1010],rk[1010];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();m=read();
	int ans=n,p=sqrt(n);
	for(int i=1;i<=n;i++){
		ak[i]=i/p+1;
		if(i%p==1)lk[i/p+1]=i,rk[i/p]=i-1;
	}
	rk[n/p+1]=n;
	memset(bk,1,sizeof bk);
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		int l=max(0,x-z),r=min(n,x+z);
		int p=y/31,q=y%31;
		for(int j=l;j<=r;){
			int k=i/p+1;
			if(j==lk[k]&&(!c[k][p])){
				if((a[k][p]|(1<<q))==a[k][p])ans+=(rk[k]-lk[k]+1)*(!bk[k]),bk[k]=1;
				else ans-=(rk[k]-lk[k]+1)*bk[k],bk[k]=0,a[k][p]=a[k][p]|(1<<q);
				j=rk[k]+1;
			}
			c[k][p]=1;
			if((d[j][p]|(1<<q))==d[j][p])ans+=(!(b[j]^bk[k])),b[j]=1^bk[k];
			else ans-=(b[j]^bk[k]),b[j]=bk[k],d[j][p]=d[j][p]|(1<<q);
			j++;
		}
	}
	printf("%d",ans);
	return 0;
}
