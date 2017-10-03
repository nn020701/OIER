#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define mk(x,y) make_pair(x,y)
#define pii pair<int,int>
#define ll long long
#define N 405
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int step_x[8] = {-2,-2,-1,-1,1,1,2,2};
const int step_y[8] = {-1,1,-2,2,-2,2,-1,1};
int n,m;
int f[N][N];
queue<pii > q;

void bfs(){
	while(!q.empty()){
		pii u = q.front(); q.pop();
		for(int i = 0;i < 8;i++){
			int x = u.first+step_x[i];
			int y = u.second+step_y[i];
			if(x < 1 || y < 1 || x > n || y > m)
				continue;
			if(f[x][y] != -1)
				continue;
			f[x][y] = f[u.first][u.second]+1;
			q.push(mk(x,y));
		}
	}
}

int main(){
	n = read(); m = read();
	int x = read(), y = read();
	memset(f,-1,sizeof f);
	f[x][y] = 0;
	q.push(mk(x,y));
	bfs();
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%-5d",f[i][j]);
	return 0;
}