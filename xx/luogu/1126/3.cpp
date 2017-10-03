#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 60
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int m,n,map[N][N],bx,by,ex,ey,ans;
char d;
int xx[5][4] = {{0,0,0,0},{0,-1,-2,-3},{0,0,0,0},{0,1,2,3},{0,0,0,0}};
int yy[5][4] = {{0,0,0,0},{0,0,0,0},{0,-1,-2,-3},{0,0,0,0},{0,1,2,3}};
struct tt{
	int x,y;
	int dic;
	int step;
}t[N*N*6];
bool s[N][N][5];

void bfs(){
	int head = 0,tail = 1;
	t[1].x = bx; t[1].y = by;
	if(d == 'N') t[1].dic = 1;
	if(d == 'W') t[1].dic = 2;
	if(d == 'S') t[1].dic = 3;
	if(d == 'E') t[1].dic = 4;
	while(head < tail){
		head++;
		int x1 = t[head].x,y1 = t[head].y;
		for(int i = 1;i <= 4;i++){
			if(t[head].dic != i && abs(t[head].dic-i) != 2 && !s[x1][y1][i] && map[x1][y1] == 0){
				s[x1][y1][i] = true;
				t[++tail].x = t[head].x;
				t[tail].y = t[head].y;
				t[tail].dic = i;
				t[tail].step = t[head].step+1;
			}
		}
		for(int i = 1;i <= 3;i++){
			x1 = t[head].x+xx[t[head].dic][i];
			y1 = t[head].y+yy[t[head].dic][i];
			if(x1 >= 1 && x1 <= m && y1 >= 1 && y1 <= n && !s[x1][y1][t[head].dic] && map[x1][y1] == 0){
				if(i >= 2 && (map[t[head].x+xx[t[head].dic][i-1]][t[head].y+yy[t[head].dic][i-1]]))
					continue;
				if(i == 3 && (map[t[head].x+xx[t[head].dic][i-2]][t[head].y+yy[t[head].dic][i-2]]))
					continue;
				s[x1][y1][t[head].dic] = true;
				t[++tail].x = x1;
				t[tail].y = y1;
				t[tail].dic = t[head].dic;
				t[tail].step = t[head].step+1;
				if(x1 == ex && y1 == ey){
					head = tail;
					ans = t[tail].step;
					break;
				} 
			}
		}
	}
} 

int main(){
	int temp;
	m = read(); n = read();
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++){
			if(i == 1 || j == 1) map[i][j] = 1;
			if(i == m) map[i+1][j] = 1;
			if(j == n) map[i][j+1] = 1;
			temp = read();
			if(temp){
				map[i+1][j+1] = 1;
				map[i][j+1] = 1;
				map[i+1][j] = 1;
				map[i][j] = 1;
			}
		}
	m++; n++;
	map[m][n] = 1;
	bx = read(); by = read(); ex = read(); ey = read();
	bx++; by++; ex++; ey++;
	if(bx == ex && by == ey){
		printf("0\n");
		return 0;
	}
	getchar();
	scanf("%c",&d);
	bfs();
	if(ans != 0) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
