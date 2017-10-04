#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <bitset>
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
int n,m,ans,k[200001],to[200001],l[200001],x[200001],cnt;
bool sit[10001];
bitset<10001> vis[10001];
int main()
{
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	n=read();m=read();
	For(i,1,m)	
	{
		x[i]=read();k[i]=read();if(!to[k[i]])	to[k[i]]=++cnt;
		k[i]=to[k[i]];
		l[i]=read();
	}
	For(i,1,m)
	{
		For(j,x[i]-l[i],x[i]+l[i])
			if(vis[k[i]][j])	sit[j]=0;else sit[j]=1,vis[k[i]][j]=1;
	}
	For(i,1,n)	if(!sit[i])	ans++;
	writeln(ans);
}
