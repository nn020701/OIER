#include<cstdio>
#include<memory.h>
#include<algorithm>
#define ll long long
#define maxn 1010
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
ll n,mx,mp[maxn][maxn],a[maxn][maxn],b[maxn][maxn],answ;
int main(){
	freopen("a.in","r",stdin);
 	freopen("baoli.out","w",stdout);
	n=read();	mx=read();
	For(i,1,n)	For(j,1,n)	mp[i][j]=read();
	For(i,1,n)	For(j,1,n)	a[i][j]=mp[i][j]+a[i-1][j-1],b[i][j]=mp[i][j]+b[i-1][j+1];
	For(i,1,n)	For(j,1,n)	for(ll t=min(i,j),k=1;k<=t;k++){
		ll ned=a[i][j]-a[i-k][j-k]+b[i][j-k+1]-b[i-k][j+1];
		if (k&1)	ned-=mp[i-k/2][j-k/2];
		if (ned<=mx)	answ=max(answ,k);
	}writeln(answ);
}
