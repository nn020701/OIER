#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long 
#define inf 200000000
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
ll p,q,n,mod,ans1,ans2;
ll work(ll p,ll n){
	ll tmp=1,ans=0;
	For(i,1,n){
		(tmp*=p)%=mod;
		(ans+=tmp*(i+1)%mod)%=mod;
	}
	return ans;
}
int main(){
	freopen("word.in","r",stdin);
	freopen("baoli.out","w",stdout);
	p=read(),q=read(),n=read(),mod=read();
	ll ans1=work(p,n),ans2=work(q,n);
	writeln((ans1+ans2+ans1*ans2)%mod);
}
