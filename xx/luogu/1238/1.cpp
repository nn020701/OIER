#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 16
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y;
}path[400];
const int step_x[4] = {0,-1,0,1};
const int step_y[4] = {-1,0,1,0};
int n,m,tot;
int st_x,st_y;
int ed_x,ed_y;
bool mp[N][N],flag = false;

void dfs(int x,int y){
	if(x == ed_x && y == ed_y){
		for(int i = 1;i < tot;i++)
			printf("(%d,%d)->",path[i].x,path[i].y);
		printf("(%d,%d)\n",ed_x,ed_y);
		flag = true;
		return;
	}
	for(int i = 0;i < 4;i++){
		int xx = x+step_x[i];
		int yy = y+step_y[i];
		if(xx <= 0 || xx > n || yy <= 0 || yy > m || mp[xx][yy]) continue;
		mp[xx][yy] = true;
		path[++tot] = (node){xx,yy};
		dfs(xx,yy);
		tot--;
		mp[xx][yy] = false;
	}
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			int a = read();
			if(a == 1) mp[i][j] = false;
			else mp[i][j] = true;
		}
	st_x = read(); st_y = read();
	ed_x = read(); ed_y = read();
	mp[st_x][st_y] = true;
	path[++tot] = (node){st_x,st_y};
	dfs(st_x,st_y);
	if(!flag) puts("-1");
	return 0;
}
