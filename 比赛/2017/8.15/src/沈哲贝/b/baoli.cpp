#include<cstdio>
#include<memory.h>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
ll bin[100],hash[310][310],a[310][310],sum[310][310],n,m,answ;
ll mark[2010];
int main(){
	freopen("b.in","r",stdin);
	freopen("baoli.out","w",stdout);
	bin[0]=1;	For(i,1,10)	bin[i]=bin[i-1]<<1;
	For(i,0,9)	mark[bin[i]]=i+1;	mark[0]=1;
	n=read();	m=read();	answ=1;
	For(i,1,n)	For(j,1,m){
		a[i][j]=read();
		sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
		hash[i][j]=hash[i][j-1]^hash[i-1][j]^hash[i-1][j-1]^bin[a[i][j]];
	}
	For(i,1,n)	For(j,1,m)	For(x,0,i-1)	For(y,0,j-1)
	if (mark[hash[i][j]^hash[x][y]^hash[x][j]^hash[i][y]]&&(sum[i][j]+sum[x][y]-sum[x][j]-sum[i][y]+1)>mark[hash[i][j]^hash[x][y]^hash[x][j]^hash[i][y]])	answ=max(answ,(i-x)*(j-y));
	writeln(answ);
}
