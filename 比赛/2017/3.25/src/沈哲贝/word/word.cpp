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
struct data{
	ll m[4][4];
}a,b,c,tmp;
data cheng(data a,data b){
	For(i,1,3)	For(j,1,3)	tmp.m[i][j]=0;
	For(i,1,3)	For(j,1,3)	For(k,1,3)	(tmp.m[i][k]+=a.m[i][j]*b.m[j][k])%=mod;
	return tmp;
}
ll work(ll p,ll k){
	For(i,1,3)	For(j,1,3)	a.m[i][j]=b.m[i][j]=c.m[i][j]=0;
	ll tmp=1,ans=0;
	b.m[1][1]=p;
	b.m[2][1]=1;
	b.m[2][2]=p;
	b.m[3][2]=1;
	b.m[3][3]=1;
	a.m[1][1]=a.m[2][2]=a.m[3][3]=1;
	while(k){
		if (k&1)	a=cheng(a,b);	b=cheng(b,b);
		k>>=1;
	}
	c.m[1][1]=p*p%mod;	c.m[2][1]=2*p;	c=cheng(a,c);
	return c.m[3][1];
}
int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	p=read(),q=read(),n=read(),mod=read();
	ll ans1=work(p,n),ans2=work(q,n);
	writeln((ans1+ans2+ans1*ans2)%mod);
}
