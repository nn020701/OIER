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
ll answ;
bool mp[1010][100010];
ll a[1010],n,Q;
bool mark[1010];
int main(){
	freopen("c.in","r",stdin);
	freopen("baoli.out","w",stdout);
	n=read();	Q=read();
	For(i,1,n)	mark[i]=1;
	For(i,1,Q){
		ll x=read(),l=read(),k=read();
		For(j,1,n)	if (abs(j-x)<=k)	mp[j][l]?mark[j]=1:(mark[j]=0,mp[j][l]=1);
	}
	For(i,1,n)	answ+=mark[i];
	writeln(answ);
}
