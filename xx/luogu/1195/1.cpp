//并查集，贪心 

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define M 10005
#define N 1005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
struct edge{
	int x,y,w;
}e[M];
int f[N];
int ans,t;

bool cmp(edge a,edge b){
	return a.w < b.w;
}

int getf(int x){
	if(x == f[x]) return x;
	f[x] = getf(f[x]);
	return f[x];
}

int main(){
	n = read(); m = read(); k = read(); t = n;
	for(int i = 1;i <= m;i++){
		e[i].x = read(); e[i].y = read(); e[i].w = read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= m;i++){
		int fx = getf(e[i].x);
		int fy = getf(e[i].y);
		if(fx == fy) continue;
		f[fx] = fy;
		ans += e[i].w;
		t--;
		if(t == k) break;
	}
	if(t > k) printf("No Answer\n");
	else printf("%d\n",ans);
	return 0;
}
