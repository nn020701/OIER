#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 100005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int lnxt[N],rnxt[N];
int head,tail;
bool vis[N];
int n,m;

int main(){
	n = read();
	memset(vis,false,sizeof vis);
	rnxt[0] = 1;
	lnxt[1] = 0;
	rnxt[1] = n+1;
	lnxt[n+1] = 1;
	for(int i = 2;i <= n;i++){
		int k = read(),p = read();
		if(p == 1){
			rnxt[i] = rnxt[k];
			rnxt[k] = i;
			lnxt[rnxt[i]] = i;
			lnxt[i] = k;
		}
		else{
			lnxt[i] = lnxt[k];
			rnxt[i] = k;
			lnxt[k] = i;
			rnxt[lnxt[i]] = i;
		}
	}
	m = read();
	for(int i = 1;i <= m;i++){
		int x = read();
		if(vis[x]) continue;
		vis[x] = true;
		rnxt[lnxt[x]] = rnxt[x];
		lnxt[rnxt[x]] = lnxt[x];
	}
	int p = rnxt[0];
	while(p != n+1){
		printf("%d ",p);
		p = rnxt[p];
	}
	return 0;
}