#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 505
#define M 250005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int f[N];
double x[N],y[N],ans;
int s,n,cnt;
struct edge{
	int a,b;
	double w;
	friend bool operator <(edge a,edge b){
		return a.w < b.w;
	}
}e[M];

int getf(int x){
	if(f[x] == x) return x;
	return f[x] = getf(f[x]);
}

int main(){
	s = read(); n = read();
	for(int i = 1;i <= n;++i){
		x[i] = read(); y[i] = read();
		f[i] = i;
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			if(i != j){
				double w = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				e[++cnt].a = i;
				e[cnt].b = j;
				e[cnt].w = w;
			}
	sort(e+1,e+cnt+1);
	for(int i = 1;i <= cnt;++i){
		int fa = getf(e[i].a),fb = getf(e[i].b);
		if(fa == fb) continue;
		f[fa] = fb;
		ans = e[i].w;
		s++;
		if(s == n) break;
	}
	printf("%.2lf\n",ans);
	return 0;
}