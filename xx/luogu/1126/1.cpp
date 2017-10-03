#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 55
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int step_x[4][3] = {{0,0,0},{1,2,3},{0,0,0},{-1,-2,-3}};
const int step_y[4][3] = {{1,2,3},{0,0,0},{-1,-2,-3},{0,0,0}};
bool flag[N][N][4];
int n,m,st_x,st_y,ed_x,ed_y;
char c;
int map[N][N];
struct node{ int x,y,f,ans; };
queue<node> q;

bool check(int x,int y){
	if(x && x <= n && y && y <= m) return true;
	return false;
}

void bfs(){
	node a;
	a.x = st_x; a.y = st_y;
	if(c == 'E') a.f = 0;
	else if(c == 'S') a.f = 1;
	else if(c == 'W') a.f = 2;
	else a.f = 3;
	flag[st_x][st_y][a.f] = true;
	a.ans = 0;
	q.push(a);
	while(!q.empty()){
		a = q.front(); q.pop();
		node b = a; b.ans++;
		b.f = (a.f+1)%n;
		if(!flag[b.x][b.y][b.f]){
			flag[b.x][b.y][b.f] = true;
			q.push(b);
		}
		b.f = (a.f+n-1)%n;
		if(!flag[b.x][b.y][b.f]){
			flag[b.x][b.y][b.f] = true;
			q.push(b);
		}
		b.f = a.f;
		for(int k = 0;k < 3;k++){
			b.x = a.x + step_x[b.f][k];
			b.y = a.y + step_y[b.f][k];
			if(!check(b.x,b.y) || map[b.x][b.y]) break;
			if(b.x == ed_x && b.y == ed_y){
				printf("%d\n",b.ans);
				exit(0);
			}
			if(!flag[b.x][b.y][b.f]){
				flag[b.x][b.y][b.f] = true;
				q.push(b);
			}
		}
	}
	return;
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(i == 1||j == 1) map[i][j] = 1;
			if(i == n) map[i+1][j] = 1;
			if(j == m) map[i][j+1] = 1;
			int x = read();
			if(x == 0) continue;
			map[i][j] = 1; map[i][j+1] = 1;
			map[i+1][j] = 1; map[i+1][j+1] = 1;
		}
	n++; m++; map[n][m] = 1;
	st_x = read()+1; st_y = read()+1;
	ed_x = read()+1; ed_y = read()+1;
	if(st_x == ed_x && st_y == ed_y){
		printf("0\n");
		return 0;
	}
	scanf("%c",&c);
	bfs();
	printf("-1\n");
	return 0;
}
