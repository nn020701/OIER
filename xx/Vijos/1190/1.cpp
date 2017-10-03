#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 305
#define M 10005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int f[N];
int n,m;
int Maxans,num;
struct edge{
	int u,v,w;
	bool friend operator <(edge a,edge b){
		return a.w < b.w;
	}
}e[M];

inline int getf(int x){
	if(x == f[x]) return x;
	return f[x] = getf(f[x]);
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		f[i] = i;
	for(int i = 1;i <= m;i++){
		e[i].u = read(); e[i].v = read(); e[i].w = read();
	}
	sort(e+1,e+m+1);
	for(int i = 1;i <= m;i++){
		int x = getf(e[i].u);
		int y = getf(e[i].v);
		if(x == y) continue;
		num++; Maxans = e[i].w;
		f[x] = y;
		if(num == n-1) break;
	}
	printf("%d %d\n",num,Maxans);
	return 0;
}