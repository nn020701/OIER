#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 205
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

const int st_x[4] = {-1,0,1,0};
const int st_y[4] = {0,-1,0,1};
bool vis[N][N];
bool map[N][N];
bool win[N][N];
int n,m;
struct node{
	int x,y,t;
};
queue<node> q;
int sx,sy,ex,ey;

void dfs(){
	memset(win,0,sizeof win);
	win[ex][ey] = true;
	for(int i = ex-1;i > 0;i--) // up
		if(map[i][ey]) win[i][ey] = true;
		else break;
	for(int i = ex+1;i <= n;i++) // down
		if(map[i][ey]) win[i][ey] = true;
		else break;
	for(int j = ey-1;j > 0;j--)	//left
		if(map[ex][j]) win[ex][j] = true;
		else break;
	for(int j = ey+1;j <= m;j++) //right
		if(map[ex][j]) win[ex][j] = true;
		else break;
	for(int i = ex-1,j = ey-1;i > 0 && j > 0;i--,j--) //up - left
		if(map[i][j]) win[i][j] = true;
		else break;
	for(int i = ex-1,j = ey+1;i > 0 && j <= m;i--,j++) //up - right
		if(map[i][j]) win[i][j] = true;
		else break;
	for(int i = ex+1,j = ey-1;i <= n && j > 0;i++,j--) //down - left
		if(map[i][j]) win[i][j] = true;
		else break;
	for(int i = ex+1,j = ey+1;i <= n && j <= m;i++,j++) //down - right
		if(map[i][j]) win[i][j] = true;
		else break;
}

bool check(int x,int y){
	if(x > 0 && y > 0 && x <= n && y <= m && map[x][y] && !vis[x][y]) return true;
	return false;
}

int bfs(){
	while(!q.empty()) q.pop();	//清空q 
	if(win[sx][sy]) return 0;	//判断初始位置是不是长者 
	memset(vis,0,sizeof vis);
	vis[sx][sy] = true;
	q.push((node){sx,sy,0});
	while(!q.empty()){
		node u = q.front(); q.pop();
		for(int i = 0;i < 4;i++){
			int xx = u.x+st_x[i];
			int yy = u.y+st_y[i];
			if(check(xx,yy)){
				if(win[xx][yy]) return u.t+1;
				vis[xx][yy] = true;
				q.push((node){xx,yy,u.t+1});
			}
		}
	}
	return -1;
}

int main(){
	freopen("journalist.in","r",stdin);
	freopen("journalist.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= n;i++){
		char s[N];
		scanf("%s",s+1);
		for(int j = 1;j <= m;j++)
			if(s[j] == 'O') map[i][j] = true;
	}
/*	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%d ",map[i][j]); */
	while(1){
		sx = read(); sy = read(); ex = read(); ey = read();
		if(sx == 0 && sy == 0 && ex == 0 && ey == 0) break;
		dfs();
		/*for(int i = 1;i <= n;i++,puts(""))
			for(int j = 1;j <= m;j++)
				printf("%d ",win[i][j]);*/
		int ans = bfs();
		if(ans == -1) puts("Naive!");
		else printf("%d\n",ans);
	}
	return 0;
}
