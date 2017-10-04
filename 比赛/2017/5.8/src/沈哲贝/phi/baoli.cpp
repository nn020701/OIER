#include<algorithm>
#include<memory.h>
#include<cstdio>
#define ll long long
#define maxn 100010
#define mod 1000000007
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
ll answ,n,m,v[20010],f[10010];
int main(){
	freopen("bag.in","r",stdin);
	freopen("baoli.out","w",stdout);
	n=read();	m=read();
	For(i,1,n)	v[i]=read();
	For(i,1,n){
		memset(f,0,sizeof f);	f[0]=1;
		For(j,1,n)	if(j!=i)	FOr(k,m,v[j])	(f[k]+=f[k-v[j]])%=mod;
		writeln(f[m]);
	}
}
