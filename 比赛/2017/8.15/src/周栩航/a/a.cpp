#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define maxn 20010
#define y1 fuck
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
ll n,w,a[2001][2001],s1[2001][2001],s2[2001][2001],ans=0;
inline bool check(ll x,ll y,ll len)
{
	ll ty=(x+y)/2,tx=1+(ty-x);
	ll tep=0;
	if((x+y)&1)	tep=0;else tep=a[tx][ty];
	ll tmp=0;
	if((x+y)&1)	
		tmp=s1[tx+len][ty+len]-s1[tx-len][ty-len]+s2[tx+len][ty-len+1]-s2[tx-len][ty+len+1]-tep;
		else tmp=s1[tx+len][ty+len]-s1[tx-len-1][ty-len-1]+s2[tx+len][ty-len]-s2[tx-len-1][ty+len+1]-tep;
	if(tmp<=w)	return 1;else return 0;
}
inline ll getr(ll x,ll y)
{
	ll ty=(x+y)/2,tx=1+(ty-x);
	ll tmp=0;
	if((x+y)&1)	tmp=min(tx,ty);else tmp=min(ty-1,tx-1);
	tmp=min(tmp,n-ty);tmp=min(tmp,n-tx);
	return tmp;
}
int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	n=read();w=read();
	For(i,1,n)	For(j,1,n)	a[i][j]=read();
	For(i,1,n)	For(j,1,n)	s1[i][j]=s1[i-1][j-1]+a[i][j];
	For(i,1,n)	Dow(j,1,n)	s2[i][j]=s2[i-1][j+1]+a[i][j];
	check(1,4,2);
	For(i,1,n)
		For(j,i,n)
		{
			ll l=0,r=getr(i,j);
			while(l<=r)
			{
				ll mid=l+r>>1;
				if(check(i,j,mid))	ans=max(mid*2+((i+j)%2==0),ans),l=mid+1;else r=mid-1;
			}
		}
	writeln(ans);
}
/*
6 12
1 1 1 1 1 1 
1 1 1 1 1 1
1 2 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
2 1 1 1 1 1
*/
