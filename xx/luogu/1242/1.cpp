#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 50
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ans;
int st[N],ed[N];

void dfs(int x,int a,int b,int flag){
	int c = 1;
	if(a == b){
		if(x > 1){
			if(flag) dfs(x-1,st[x-1],ed[x-1],true);
			else dfs(x-1,st[x-1],b,false);
		}
		return;
	}
	while(a == c || b == c) c++;
	if(x > 1) dfs(x-1,st[x-1],c,false);
	st[x] = b;
	printf("move %d from %c to %c\n",x,a+'A'-1,b+'A'-1);
	ans++;
	if(x > 1){
		if(flag) dfs(x-1,st[x-1],ed[x-1],true);
		else dfs(x-1,st[x-1],b,false);
	}
}

int main(){
	n = read();
	for(int i = 1;i <= 3;i++){
		int x = read();
		for(int j = 1;j <= x;j++){
			int y = read();
			st[y] = i;
		}
	}
	for(int i = 1;i <= 3;i++){
		int x = read();
		for(int j = 1;j <= x;j++){
			int y = read();
			ed[y] = i;
		}
	}
	dfs(n,st[n],ed[n],true);
	printf("%d\n",ans);
	return 0;
}
