#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll int 
#define inf 2000000001
#define maxn 80010
#define mod 1000000007
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
int main(){
	freopen("number.in","r",stdin);
	freopen("baoli.out","w",stdout);
	ll n=read(),answ=0;
	For(i,1,n){
		ll t=sqrt(i);
		For(j,1,t){
			bool flag=0;	ll now=1;
			For(k,1,30){
				now*=j;
				if (now>i)	break;
				if (now==i){
					flag=1;
					break;
				}	
			}
			if (flag){answ++;break;}
		}
	}
	writeln(answ);
}
