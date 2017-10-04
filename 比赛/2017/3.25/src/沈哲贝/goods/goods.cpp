#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll int
#define inf 2000000001
#define mod 999983
#define maxn 200020
#define ld double
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}

struct data{
	double x;
	ll y;
}q[120];

ll bin[7],st[7],jump[7],tt[120],sum[120];
ll n,m;
ld mark[120],ans;

void changee(ll t,ll tt){
	For(i,1,bin[m]-1)
		if (i&bin[t-1]){
			if (tt!=1)
				mark[i]-=1.0/(tt-1);
			mark[i]+=(double)1/tt;
		}
}
bool cmp(data x,data y){
	return x.x>y.x;
}
int main(){
	freopen("goods.in","r",stdin);
	freopen("goods.out","w",stdout);
	bin[0]=1;
	For(i,1,6)
		bin[i]=bin[i-1]<<1;
	n=read();	m=read();
	For(i,1,m)
		st[i]=read()+1;
	For(i,1,m)
		jump[i]=read();
	For(i,1,n){
		ll now=0;
		For(j,1,m)
			if (i>=st[j]&&!((i-st[j])%jump[j])){
				tt[j]++;
				changee(j,tt[j]);
				now+=bin[j-1];
			}
		sum[now]++;
		if (i*9>=n){
			ld zyy=0;
			ll Sum=n-i;
			For(j,0,bin[m]-1)
				q[j].x=mark[j],q[j].y=sum[j];
			sort(q,q+bin[m],cmp);
			For(j,0,bin[m]-1){
				if (8*q[j].y<=Sum){
					Sum-=8*q[j].y;
					zyy+=8*q[j].y*q[j].x;
				}
				else{
					zyy+=q[j].x*Sum;
					Sum=0;
				}
				zyy+=q[j].x*q[j].y;
			}
			ans=max(ans,zyy*i);
		}
	}
	printf("%.5lf",ans/m);
}
