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
#define sz(a,i,j) (a)[(i)*(m+1)+(j)+1]
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
struct ppap{int y[10];}s[300010];
ppap operator +(ppap a,ppap b){
	ppap c;for(int i=0;i<=9;i++)c.y[i]=a.y[i]+b.y[i];return c;
}
ppap operator -(ppap a,ppap b){
	ppap c;for(int i=0;i<=9;i++)c.y[i]=a.y[i]-b.y[i];return c;
}
inline bool check(ppap a){
	bool flag=1;int sum=0;
	for(int i=0;i<=9;i++)if(a.y[i]){
		flag=(i==0)?0:1;sum+=(a.y[i]&1);
	}
	return flag&&(sum<2);
}
int a[300010],n,m;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)sz(a,i,j)=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			sz(s,i,j)=sz(s,i,j-1)+sz(s,i-1,j)-sz(s,i-1,j-1);sz(s,i,j).y[sz(a,i,j)]++;
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(n<m){
			for(int k=n;k>=i;k--){
				if((k-i+1)*(m-j+1)<=ans)break;
				for(int l=m;l>=j;l--){
					if((k-i+1)*(l-j+1)<=ans)break;
					ppap r=sz(s,k,l)-sz(s,i-1,l)-sz(s,k,j-1)+sz(s,i-1,j-1);
					if(check(r)){ans=max(ans,(k-i+1)*(l-j+1));break;}
				}
			}
		}else{
			for(int k=m;k>=j;k--){
				if((k-j+1)*(n-i+1)<=ans)break;
				for(int l=n;l>=i;l--){
					if((k-j+1)*(l-i+1)<=ans)break;
					ppap r=sz(s,l,k)-sz(s,i-1,k)-sz(s,l,j-1)+sz(s,i-1,j-1);
					if(check(r)){ans=max(ans,(k-j+1)*(l-i+1));break;}
				}
			}
		}
	printf("%d",ans);
	return 0;
}
