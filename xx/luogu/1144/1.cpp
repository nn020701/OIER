//会T，感觉就算加上堆优化还是会T 
//打一遍SPFA吧 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1000005
#define M 2000005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int head[N],nxt[M*2],to[M*2],cnt;
int dist[N],num[N];
bool vis[N];

void add(int u,int v){
	to[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt;
}

void dij(){
	memset(dist,0x3f,sizeof dist);
	num[1] = 1; dist[1] = 0;
	for(int k = 1;k < n;k++){
		int p,Min=1<<28,numMin;
		for(int i = 1;i <= n;i++)
			if(!vis[i]){
				if(dist[i] < Min){
					Min = dist[i];
					p = i;
				}
			}
		numMin = num[p];
		vis[p] = true;
		for(int i = head[p];i;i = nxt[i])
			if(!vis[to[i]]){
				if(dist[to[i]] > dist[p]+1){
					dist[to[i]] = dist[p]+1;
					num[to[i]] = num[p];
				}
				else if(dist[to[i]] == dist[p]+1)
					num[to[i]] += num[p];
			}
	}
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= m;i++){
		int a = read(),b = read();
		add(a,b); add(b,a);
	}
	dij();
	for(int i = 1;i <= n;i++)
		printf("%d\n",num[i]);
	return 0;
}
