#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1505
#define M 2250005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int st1,ed1,st2,ed2;
int dist1[N],dist2[N],dist3[N],dist4[N];
bool vis[N];
int n,m,ans;
int head[N],nxt[M],to[M],from[M],w[M],cnt;
int Head[N],Nxt[M],To[M],W[M],Cnt;
int ru[N];

void add_edge(int a,int b,int c){
	from[++cnt] = a; to[cnt] = b; nxt[cnt] = head[a]; head[a] = cnt; w[cnt] = c;
	from[++cnt] = b; to[cnt] = a; nxt[cnt] = head[b]; head[b] = cnt; w[cnt] = c;
}

void Add_Edge(int a,int b,int c){
	To[++Cnt] = b; Nxt[Cnt] = Head[a]; Head[a] = Cnt; W[Cnt] = c;
	ru[b]++;
}

void spfa(int st,int dist[]){
	queue<int> q;
	memset(vis,false,sizeof vis);
	q.push(st);
	memset(dist,0x3f,sizeof dist1);
	dist[st] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = nxt[i])
			if(dist[to[i]] > dist[u]+w[i]){
				dist[to[i]] = dist[u]+w[i];
				if(vis[to[i]]) continue;
				vis[to[i]] = true;
				q.push(to[i]);
			}
	}
}

void topo(){
	queue<int> q;
	for(int i = 1;i <= n;++i)
		if(ru[i] == 0)
			q.push(i);
	int dist[N];
	memset(dist,0,sizeof dist);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = Head[u];i;i = Nxt[i]){
			dist[To[i]] = max(dist[To[i]],dist[u]+W[i]);
			ans = max(ans,dist[To[i]]);
			ru[To[i]]--;
			if(ru[To[i]] == 0)
				q.push(To[i]);
		}
	}
}

int main(){
	n = read(); m = read();
	st1 = read(); ed1 = read(); st2 = read(); ed2 = read();
	for(int i = 1;i <= m;++i){
		int a = read(),b = read(),c = read();
		add_edge(a,b,c);
	}
	spfa(st1,dist1);
	spfa(ed1,dist2);
	spfa(st2,dist3);
	spfa(ed2,dist4);
	// for(int i = 1;i <= n;++i){
	// 	printf("%d %d %d %d\n", dist1[i],dist2[i],dist3[i],dist4[i]);
	// }
	for(int i = 1;i <= cnt;i += 2){
		int x = from[i],y = to[i];
		int k1 = min(dist1[x]+w[i]+dist2[y],dist1[y]+w[i]+dist2[x]);
		int k2 = min(dist3[x]+w[i]+dist4[y],dist3[y]+w[i]+dist4[x]);
		// int k1 = min(dist1[x],dist1[y])+w[i]+min(dist2[x],dist2[y]);
		// int k2 = min(dist3[x],dist3[y])+w[i]+min(dist4[x],dist4[y]);
		if(k1 == dist1[ed1] && k2 == dist3[ed2]){
			if(dist1[x] < dist1[y]) Add_Edge(x,y,w[i]);
			else Add_Edge(y,x,w[i]);
		}
	}
	/*for(int i = 1;i <= cnt;i += 2){
		int x = from[i],y = to[i];
		if(dist1[x]+w[i]+dist2[y] < dist1[y]+w[i]+dist2[x]){
			if(dist1[x]+w[i]+dist2[y] == dist1[ed1] && dist3[x]+w[i]+dist4[y] == dist3[ed2])
				Add_Edge(x,y,w[i]);	
		}
		else{
			if(dist1[y]+w[i]+dist2[x] == dist1[ed1] && dist3[y]+w[i]+dist4[x] == dist3[ed2])
				Add_Edge(y,x,w[i]);
		}
	}*/
	topo();
	printf("%d\n", ans);
	return 0;
}