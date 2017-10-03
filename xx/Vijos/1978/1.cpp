#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 45
#define M 1605
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n;
int map[N][N];
int x[M],y[M];

int main(){
	n = read();
	x[1] = 1; y[1] = (n+1)/2; map[x[1]][y[1]] = 1;
	for(int i = 2;i <= n*n;i++){
		// ( 1 )
		if(x[i-1] == 1 && y[i-1] != n){
			x[i] = n; y[i] = y[i-1]+1;
			map[x[i]][y[i]] = i;
			continue;
		}
		// ( 2 )
		if(y[i-1] == n && x[i-1] != 1){
			y[i] = 1; x[i] = x[i-1]-1;
			map[x[i]][y[i]] = i;
			continue;
		}
		// ( 3 )
		if(x[i-1] == 1 && y[i-1] == n){
			x[i] = x[i-1]+1; y[i] = y[i-1];
			map[x[i]][y[i]] = i;
			continue;
		}
		// ( 4 )
		if(map[x[i-1]-1][y[i-1]+1] == 0){
			x[i] = x[i-1]-1; y[i] = y[i-1]+1;
			map[x[i]][y[i]] = i;
			continue;
		}
		x[i] = x[i-1]+1; y[i] = y[i-1];
		map[x[i]][y[i]] = i;
	}
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= n;j++)
			printf("%d ",map[i][j]);
	return 0;
}