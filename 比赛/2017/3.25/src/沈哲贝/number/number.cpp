#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define inf 2000000001
#define maxn 80010
#define mod 1000000007
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
ll n,mark[100],pd[maxn],ans;
bool poww(ll x,ll k){
	double ans=1;
	For(i,1,k){
		ans=ans*x;
		if (ans>n)	return 0;
	}
	return 1;
}
void dfs(ll x,ll sum,ll cho){
	if (sum>62)	return;
	if (x>62){	mark[sum]+=cho&1?1:-1;	return;	}
	if (pd[x])	dfs(x+1,sum,cho);
	else{
		dfs(x+1,sum,cho);
		dfs(x+1,sum*x,cho+1);
	}
}
ll query(ll k){
	ll l=1,r=sqrt(n),ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if (poww(mid,k))	l=mid+1,ans=mid;
		else	r=mid-1;
	}
	return ans;
}
bool qqq(ll x){
	ll t=sqrt(x);
	For(i,2,t)	if (!(x%i))	return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=read();
	For(i,2,62)	pd[i]=qqq(i);
	dfs(2,1,0);
	For(i,2,62){
		ll t=query(i)-1;
		ans+=mark[i]*t;
	}
	writeln(ans+1);
}
