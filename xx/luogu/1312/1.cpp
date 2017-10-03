#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
#define ll long long
#define M 15
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool vis[M][M];
bool flag[M];
int map[M][M];
int step[M][6];
int count[M];
int n,N;

int del(){
	memset(vis,1,sizeof vis);
	int res = 0;
	int l,r,u,d,x,y,t;
	bool cs = 0;
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 7;j++)
			if(map[i][j])
				if((j >= 2 && map[i][j-1]) || j == 1){
					l = r = i;
					u = d = j;
					while(l >= 2 && map[l-1][j] == map[i][j]) l--;
					while(r < 4 && map[r+1][j] == map[i][j]) r++;
					while(d >= 2 && map[i][d-1] == map[i][j]) d--;
					while(u <= 6 && map[i][u+1] == map[i][j]) u++;
					if(r-l >= 2)
						for(int k = l;k <= r;k++)
							vis[k][j] = 0;
					if(u-d >= 2)
						for(int k = d;k <= u;k++)
							vis[i][k] = 0;
				}
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 7;j++)
			if(!vis[i][j]){
				res++;
				map[i][j] = 0; 
			}
	for(int i = 1,j;i <= 5;i++){
		for(j = 1;j <= 7;j++)
			if(!map[i][j]) break;
		x = j;
		for(;j <= 7;j++)
			if(map[i][j]) break;
		if(j == 8) continue;
		y = j-1;
		t = 0;
		for(j = x;j <= 7;j++){
			t++;
			if(!map[i][y+t]||map[i][j])
				break;
			map[i][j] = map[i][y+t];
			map[i][y+t] = 0;
			cs = 1;
		}
	}
	if(cs) res += del();
	return res;
}

bool judge(){
	memset(count,0,sizeof count);
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 7;j++)
			count[map[i][j]]++;
	for(int i = 1;i <= N;i++)
		if(count[i] >= 1  && count[i] <= 2)
			return 0;
	return 1;
}

void dfs(int num,int tot){
	if(!judge()) return;
	if(num >= n+1){
		if(!tot){
			for(int i = 1;i <= n;i++)
				printf("%d %d %d\n",step[i][1]-1,step[i][2]-1,step[i][3]);
			exit(0);
		}
		return;
	}
	int x,y;
	int temp[M][M],p,q;
	bool cs;
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 7;j++)
			temp[i][j] = map[i][j];
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 7;j++){
			if(map[i][j]){
				cs = 1;
				if(i <= 4 && map[i][j] != map[i+1][j]){
					swap(map[i][j],map[i+1][j]);
					step[num][1] = i;
					step[num][2] = j;
					step[num][3] = 1;
					p = tot-del();
					dfs(num+1,p);
					cs = 0;
				}
				if(!cs){
					cs = 1;
					for(p = 1;p <= 5;p++)
						for(q = 1;q <= 7;q++)
							map[p][q] = temp[p][q];
				}
				if(i >= 2 && !map[i-1][j]){
					swap(map[i][j],map[i-1][j]);
					step[num][1] = i;
					step[num][2] = j;
					step[num][3] = -1;
					p = tot-del();
					dfs(num+1,p);
					cs = 0;
				}
				if(!cs)
					for(p = 1;p <= 5;p++)
						for(q = 1;q <= 7;q++)
							map[p][q] = temp[p][q];
			}
		}
			
}

int main(){
	int x,y = 0;
	n = read();
	for(int i = 1,j;i <= 5;i++){
		j = 0;
		x = read();
		while(x){
			map[i][++j] = x;
			if(!flag[x]){
				flag[x] = 1;
				N++;
			}
			y++;
			x = read();
		}
	}
	dfs(1,y);
	printf("-1\n");
	return 0;
}
