#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

const int step_x[4][3] = {{0,0,0},{1,2,3},{0,0,0},{-1,-2,-3}};
const int step_y[4][3] = {{1,2,3},{0,0,0},{-1,-2,-3},{0,0,0}};
struct node{
	int x,y,f,ans;
};
bool map[61][61];
queue<node> q;
int n,m;
int st_x,st_y,ed_x,ed_y;
int a[60][60];
bool vis[60][60][5];

bool check(int x,int y){
	if(x < 1 || x >= n || y < 1 || y >= m)
		return true;
	return false;
}

void bfs(){
	while(!q.empty()){
		node a = q.front(); q.pop(); 
		node p;
		p.x = a.x; p.y = a.y ;p.ans = a.ans+1;
		p.f = (a.f+1)%4;
		if(!vis[a.x][a.y][p.f]){
			vis[a.x][a.y][p.f] = true;
			q.push(p);
		}
		p.f = (a.f-1+4)%4;
		if(!vis[a.x][a.y][p.f]){
			vis[a.x][a.y][p.f] = true;
			q.push(p);
		}
		p.f = a.f;
		for(int i = 0;i <= 2;i++){
			p.x = a.x+step_x[p.f][i];
			p.y = a.y+step_y[p.f][i];
			if(check(p.x,p.y)) break;
			if(vis[p.x][p.y][p.f]) continue;
			if(map[p.x][p.y]) continue;
			if(p.x == ed_x && p.y == ed_y){
				printf("%d\n",p.ans);
				return;
			}
			vis[p.x][p.y][p.f] = true;
		}
	}
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			a[i][j] = read();
			if(a[i][j] == 1){
				map[i-1][j-1] = true;
				map[i-1][j] = true;
				map[i][j-1] = true;
				map[i][j] = true;
			}
		}
	st_x = read(); st_y = read(); ed_x = read(); ed_y = read();
	char c; scanf("%c",&c); int f;
	if(st_x == ed_x && st_y == ed_y){
		printf("0\n");
		return 0;
	}
	if(c == 'E') f = 0;
	if(c == 'S') f = 1;
	if(c == 'W') f = 2;
	if(c == 'N') f = 3;
	node p; p.x = st_x; p.y = st_y; p.ans = 0; p.f = f;
	map[st_x][st_y] = true;
	q.push(p);
	vis[st_x][st_y][f] = true;
	bfs();
	printf("-1\n");
	return 0;
}
