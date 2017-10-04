#include<algorithm>
#include<memory.h>
#include<cstdio>
#define ll int
#define maxn 800010
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
ll Q,a[maxn],b[maxn],n;	char s[10];
ll work(){
	ll ans=0,last=0;
	For(i,1,n)	if (a[i-1]!=a[i])	++ans,last=a[i];
	return max(1,ans-(a[1]==a[n]));
}
int main(){
	n=read();read();
	For(i,1,n)	a[i]=read();
	Q=read();
	For(i,1,Q){
		scanf("%s",s);
		if (s[0]=='R'){
			ll d=read();
			For(i,1,n)	b[i]=a[(i-d+n)%n];
			memcpy(a,b,sizeof b);
		}else	if (s[0]=='F')	For(i,2,n/2)	swap(a[i],a[n-i+2]);
		else if (s[0]=='S'){
			ll x=read(),y=read();
			swap(a[x],a[y]);
		}else if (s[0]=='P'){
			ll x=read(),y=read(),kk=read();
			if (x>y){
				For(i,x,n)	a[i]=kk;
				For(i,1,y)	a[i]=kk;
			}else For(i,x,y)	a[i]=kk;
		}else if (s[0]=='C'&&s[1]!='S')	writeln(work());
		else{
			ll x=read(),y=read();
			if ((x-1+n)%n==y)	writeln(work());
			else	if (x<=y){
				ll last=0,ans=0;
				For(i,x,y)	if (a[i-1]!=a[i])	++ans,last=a[i];
				writeln(max(1,ans));
			}else{
				ll last=0,ans=-(a[n]==a[1]);
				For(i,x,n)	if (a[i-1]!=a[i])	++ans,last=a[i];
				For(i,2,y)	if (a[i-1]!=a[i])	++ans,last=a[i];
				writeln(max(1,ans));
			}
		}
	}
}
