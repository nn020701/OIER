#include<queue>
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
int head[N],to[M*2],nxt[M*2],cnt;
queue<int> q;
int dist[N],num[N];
bool vis[N];

void add(int a,int b){
	to[++cnt] = b; nxt[cnt] = head[a]; head[a] = cnt;
	to[++cnt] = a; nxt[cnt] = head[b]; head[b] = cnt;
}

void SPFA(){
	q.push(1); vis[1] = true;
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0; num[1] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = nxt[i]){
			if(dist[to[i]] > dist[u]+1){
				dist[to[i]] = dist[u]+1;
				num[to[i]] = num[u];
				if(!vis[to[i]]){
					vis[to[i]] = true;
					q.push(to[i]);
				}
			}
			else if(dist[to[i]] == dist[u]+1)
				num[to[i]] = (num[to[i]]+num[u])%100003;
		}
	}
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= m;i++){
		int a = read(),b = read();
		add(a,b);
	}
	SPFA();
	for(int i = 1;i <= n;i++)
		printf("%d\n",num[i]);
	return 0;
}
