#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#include<map>
#define ll long long 
#define eps (1e-6)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
ll n,m,answ;
ll calc(ll n,ll m){
	return n*n*m*m+3*n*m-n*n*m-3*n*m*m+(2*m*m*m-2*m)/3;
//	return (n*m-n-m+5)*n*m-2*n*m*m-2*n*m-2*m*m*m-4*m*m-2*m+4*m*m+(8*m*m*m+4*m)/3;
}
int main(){
	freopen("queen.in","r",stdin);
	freopen("baoli.out","w",stdout);
	ll T=read();
	while(T--){
		n=read();	m=read();
		if (n<m)	swap(n,m);
		writeln(calc(n,m));
	}
}
