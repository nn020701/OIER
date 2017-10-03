#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 3605
#define M 18025
#define num(x,y) (((x-1)*m+(y-1))*4)
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int step_x[4] = {-1,0,1,0};
const int step_y[4] = {0,1,0,-1};
int head[N],nxt[M],to[M],w[M],cnt;
int step[35][35];
bool mp[35][35];
bool vis[N];
int dist[N];
int n,m,q;
struct node{
	int x,y;
};
queue<node> que;
queue<int> que1;

inline bool check(int x,int y){
	if(x > 0 && y > 0 && x <= n && y <= m && mp[x][y])
		return true;
	return false;
}

inline void add(int u,int v,int wi){
	to[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt; w[cnt] = wi;
}

void Bfs(int wx,int wy,int bx,int by){
	memset(step,-1,sizeof step);
	step[wx][wy] = 0;
	step[bx][by] = 1;
	que.push((node){wx,wy});
	while(!que.empty()){
		node u = que.front(); que.pop();
		for(int k = 0;k < 4;k++){
			int x = u.x + step_x[k];
			int y = u.y + step_y[k];
			if(check(x,y) && step[x][y] == -1){
				step[x][y] = step[u.x][u.y] + 1;
				que.push((node){x,y});
			}
		}
	}
}

void bfs(int wx,int wy,int bx,int by,int p){
	memset(step,-1,sizeof step);
	step[wx][wy] = 0;
	step[bx][by] = 1;
	que.push((node){wx,wy});
	while(!que.empty()){
		node u = que.front(); que.pop();
		for(int k = 0;k < 4;k++){
			int x = u.x + step_x[k];
			int y = u.y + step_y[k];
			if(check(x,y) && step[x][y] == -1){
				step[x][y] = step[u.x][u.y] + 1;
				que.push((node){x,y});
			}
		}
	}
	int tmp = num(bx,by);
	for(int k = 0;k < 4;k++){
		int x = bx + step_x[k];
		int y = by + step_y[k];
		if(step[x][y] > 0)
			add(tmp+p,tmp+k,step[x][y]);
	}
	add(tmp+p,num(wx,wy)+(p+2)%4,1);
}

void spfa(int sx,int sy){
	int tmp = num(sx,sy);
	memset(dist,-1,sizeof dist);
	for(int k = 0;k < 4;k++){
		int x = sx + step_x[k];
		int y = sy + step_y[k];
		if(step[x][y] != -1){
			dist[tmp+k] = step[x][y];
			que1.push(tmp+k);
			vis[tmp+k] = true;
		}
	}
	while(!que1.empty()){	
		int u = que1.front(); que1.pop();
		vis[u] = false;
		for(int i = head[u];i;i = nxt[i]){
			int v = to[i];
			if(dist[v] == -1 || dist[v] > dist[u]+w[i]){
				dist[v] = dist[u]+w[i];
				if(!vis[v]){
					vis[v] = true;
					que1.push(v);
				}
			}
		}
	}
}

int main(){
	n = read(); m = read(); q = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			int x = read();
			if(x == 1) mp[i][j] = 1;
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(check(i,j))
				for(int k = 0;k < 4;k++){
					int x = i + step_x[k];
					int y = j + step_y[k];
					if(check(x,y))
						bfs(x,y,i,j,k);
				}
	int ex,ey,sx,sy,tx,ty;
	while(q--){
		ex = read(); ey = read();
		sx = read(); sy = read();
		tx = read(); ty = read();
		if(sx == tx && sy == ty){
			puts("0");
			continue;
		}
		Bfs(ex,ey,sx,sy);
		spfa(sx,sy);
		int ans = 1e9;
		int tmp = num(tx,ty);
		for(int k = 0;k < 4;k++)
			if(dist[tmp+k] != -1)
				ans = min(ans,dist[tmp+k]);
		if(ans == 1e9)
			ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}