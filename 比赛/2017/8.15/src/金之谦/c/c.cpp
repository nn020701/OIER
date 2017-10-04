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
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
int a[10010][4010];
bool b[100010];
int n,m;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();m=read();
	int ans=n;
	memset(b,1,sizeof b);
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		int l=max(0,x-z),r=min(n,x+z);
		int p=y/31,q=y%31;
		for(int j=l;j<=r;j++){
			if((a[j][p]|(1<<q))==a[j][p])ans+=(!b[j]),b[j]=1;
			else ans-=b[j],b[j]=0,a[j][p]=a[j][p]|(1<<q);
		}
	}
	printf("%d",ans);
	return 0;
}
