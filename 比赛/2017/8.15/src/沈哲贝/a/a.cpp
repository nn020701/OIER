#include<ctime>
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
	freopen("a.out","w",stdout);
	n=read();	mx=read();
	For(i,1,n)	For(j,1,n)	mp[i][j]=read();
	For(i,1,n)	For(j,1,n)	a[i][j]=mp[i][j]+a[i-1][j-1],b[i][j]=mp[i][j]+b[i-1][j+1];
	For(i,1,n)	For(j,1,n){
		ll l=1,r=min(min(i,n-i+1),min(j,n-j+1));
		while(l<=r){
			ll mid=(l+r)>>1;
			if (a[i+mid-1][j+mid-1]-a[i-mid][j-mid]+b[i+mid-1][j-mid+1]-b[i-mid][j+mid]<=mx+mp[i][j])	l=mid+1,answ=max(answ,mid*2-1);
			else	r=mid-1;
		}
	}
	For(i,1,n-1)	For(j,1,n-1){
		ll l=1,r=min(min(i,n-i),min(j,n-j));
		while(l<=r){
			ll mid=(l+r)>>1;
			if (a[i+mid][j+mid]-a[i-mid][j-mid]+b[i+mid][j-mid+1]-b[i-mid][j+mid+1]<=mx)	l=mid+1,answ=max(answ,mid*2);
			else	r=mid-1;
		}
	}
	writeln(answ);
}
