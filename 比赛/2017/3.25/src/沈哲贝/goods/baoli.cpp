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
int main(){
	freopen("goods.in","r",stdin);
	freopen("goods.out","w",stdout);
	sum=n=read();	m=read();
	For(i,1,m)	st[i]=read()+1;
	For(i,1,m)	jump[i]=read();
	For(i,1,n){
		ans=ans/(i-1)*i;
		For(j,1,m)if (!((i-st[j])%jump)){
			influese[i]*=(i-st[j])%jump)/((i-st[j])%jump+1);
			change[i][j]=1;	
		}
		while(!q[1].empty||!q[2].empty()||!q[3].empty||!q[4].empty||!q[5].empty){
		}
		For(j,1,m)	if (change[i][j])	q[j].push(i);
		if (i*9>=n)	answ=max(answ,ans);
	}
	printf("%.5lf",answ/m);
}
