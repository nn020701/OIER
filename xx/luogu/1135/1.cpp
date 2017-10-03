#include<cstdlib>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 205
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,ans;
};
int x[N];
int flag[N];
int n,A,B;
queue<node> q;

void bfs(){
	while(!q.empty()){
		node a = q.front(); q.pop();
		int b = a.x;
		if(b-x[b] > 0 && !flag[b-x[b]]){
			b = b-x[a.x];
			flag[b] = true;
			node p;
			p.x = b; p.ans = a.ans+1;
			if(b == B){
				printf("%d\n",p.ans);
				exit(0);
			}
			q.push(p);
		}
		b = a.x;
		if(b+x[b] <= n && !flag[b+x[b]]){
			b = b+x[a.x];
			flag[b] = true;
			node p;
			p.x = b; p.ans = a.ans+1;
			if(b == B){
				printf("%d\n",p.ans);
				exit(0);
			}
			q.push(p);
		}
	}
}

int main(){
	n = read(); A = read(); B = read();
	if(A == B){
		puts("0");
		return 0;
	}
	for(int i = 1;i <= n;i++) x[i] = read();
	node p; p.x = A; p.ans = 0;
	flag[p.x] = true;
	q.push(p);
	bfs();
	puts("-1");
	return 0;
}
