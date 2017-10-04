#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=100010;
ll ans,Max,Max_num;
int n;
bool vis[N];
ll w[N],size[N];
int to[N*2],tot,next[N*2],head[N];
bool book[N];
inline void add(int x,int y){
	to[++tot]=y;next[tot]=head[x];head[x]=tot;
	to[++tot]=x;next[tot]=head[y];head[y]=tot;
}

void dfs(int x){
	int v;
	size[x]=1;
	for(int i=head[x];i;i=next[i]){
		v=to[i];
		if(!vis[v]){
			vis[v]=true;
			dfs(v);
			w[x]+=w[v]+size[v];
			size[x]+=size[v];
		}
	}
}

void DP(int x){
	int v;
	for(int i=head[x];i;i=next[i]){
		v=to[i];
		if(!vis[v]){
			w[v]=w[x]-size[v]*2+n;
			vis[v]=true;
			DP(v);
		}
	}
}

int main(){
	freopen("ctz.in","r",stdin);
	freopen("ctz.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		int x,y;
		x=read(); y=read();
		add(x,y);
	}
	vis[1]=1;
	dfs(1);
	memset(vis,0,sizeof vis);
	vis[1]=1;
	DP(1);
	for(int i=1;i<=n;i++)
		if(Max<w[i]){
			Max=w[i];
			Max_num=i;
		}
	cout<<Max_num<<endl;
	return 0;
}