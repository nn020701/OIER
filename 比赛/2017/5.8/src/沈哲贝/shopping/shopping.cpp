#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#define maxn 200010
#define ll long long 
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
ll n,a[maxn],tmp,ans;
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout); 
	n=read();
	For(i,1,n)	ans+=(a[i]=read());
	if (ans&1)	return writeln(ans),0;
	For(i,1,n)	if (a[i]&1)	tmp=max(tmp,ans-a[i]);
	writeln(tmp);
}
