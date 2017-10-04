#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 0x7ffffff
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node{
	int v;
	int len;
};
int k,n;
int dist[1010];
bool book[1010];
vector<node> e[1010];
void add(int u,int v){
	node e1;
	e1.v=v;
	e1.len=abs(u-v)*2;
	e[u].push_back(e1);
}
void Dij(int s){
	memset(dist,0x3f,sizeof dist);
	for(int i=0;i<e[s].size();i++){
		dist[e[s][i].v]=e[s][i].v-s;
	}
	dist[1]=0;
	book[s]=1;
	int Min,p,u=s;
	for(int t=1;t<=n-1;t++){
		Min=INF;
		for(int i=1;i<=k;i++)
			if(!book[i]&&Min>dist[i]){
				p=i;
				Min=dist[i];
			}
		book[p]=1;
		if(p==k){
			printf("%d\n",dist[p]*5);
			return;
		}
		u=p;
		int len;
		for(int i=0;i<e[u].size();i++){
			if(!book[e[u][i].v]){
				len=e[u][i].len-dist[u]%e[u][i].len;
				if(e[u][i].v<u){
					if(len>=e[u][i].len/2)
						len-=e[u][i].len/2;
					else
						len+=e[u][i].len/2;
				}
				else if(len==e[u][i].len)
					len=0;
				if(dist[e[u][i].v]>len+dist[u]+e[u][i].len/2)
					dist[e[u][i].v]=len+dist[u]+e[u][i].len/2;
			}
		}
	}
}
int main(){
	freopen("lift.in","r",stdin);
	freopen("lift.out","w",stdout);
	k=read();n=read();
	int u,v;
	for(int i=1;i<=n;i++){
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	Dij(1);
	return 0;
}
