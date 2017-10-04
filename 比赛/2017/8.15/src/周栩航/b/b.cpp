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
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int have[301][301][10],ANS,v[301][10],e[301][10],n,m,sum[301],last[2048];
bool vis[2048];
inline void doit(int x,int y)
{
	For(k,0,9)	For(i,1,m)	v[i][k]=have[y][i][k]-have[x-1][i][k],e[i][k]=(v[i][k]%2==0)^1;
//	For(k,0,9)	{cout<<k<<": ";For(i,1,m)cout<<e[i][k]<<' ';cout<<endl;}		
	For(i,1,m)	sum[i]=0;
	For(k,1,9)	For(i,1,m)	sum[i]+=v[i][k];	
	For(i,0,1024)	last[i]=1e9,vis[i]=0;
	last[0]=0;vis[0]=1;
	int mx=0;
	For(i,1,m)
	{
		int tmp=0;
		For(k,0,9)	tmp+=e[i][k]*(1<<k);
//		cout<<tmp<<endl;
		int ans=1e9;
		if(!vis[tmp])	last[tmp]=i;		
		if(sum[i]-sum[last[tmp]-1]>1)	ans=min(ans,last[tmp]);
		For(k,0,9)
		{
			tmp=tmp^(1<<k);
			if(!vis[tmp])	{tmp=tmp^(1<<k);continue;}
			if(sum[i]-sum[last[tmp]-1]>1)	ans=min(ans,last[tmp]);
			tmp=tmp^(1<<k);
		}
		last[tmp]=min(last[tmp],i);
		mx=max(mx,i-ans);
	}
	ANS=max(ANS,mx*(y-x+1));
}
int main()
{
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	n=read();m=read();
	For(i,1,n)	For(j,1,m)
		have[i][j][read()]++;
	For(k,0,9)	For(i,1,n)	For(j,1,m)	have[i][j][k]+=have[i][j-1][k];
	For(k,0,9)	For(i,1,n)	For(j,1,m)	have[i][j][k]+=have[i-1][j][k];
	For(i,1,n)
		For(j,i,n)
			doit(i,j);
	doit(1,3);	
	writeln(ANS);
}
/*
4 4 
1 1 2 3
2 3 1 1 
1 1 1 2
2 3 3 0
*/
