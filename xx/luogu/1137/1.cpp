#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
#define M 200005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int f[N];
int to[M],head[N],nxt[M],cnt;
int in[N];
queue<int> q;
int n,m;

int main(){
	n = read(); m = read();
	for(int i = 1;i <= m;i++){
		int a = read(),b = read();
		to[++cnt] = b; nxt[cnt] = head[a]; head[a] = cnt;
		in[b]++;
	}
	for(int i = 1;i <= n;i++)
		if(in[i] == 0){
			f[i] = 1;
			q.push(i);
		}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = head[u];i;i = nxt[i]){
			in[to[i]]--;
			if(in[to[i]] == 0){
				q.push(to[i]);
				f[to[i]] = f[u]+1;
			}
		}
	}
	for(int i = 1;i <= n;i++)
		printf("%d\n",f[i]);
	return 0;
}
