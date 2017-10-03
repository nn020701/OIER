#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

map<string,int> mp;
int heap[500000][101];
int top[500000];
int n,m,cnt;

int main(){
	n = read(); string s;
	for(int i = 1;i <= n;i++){
		int l = read();
		for(int j = 1;j <= l;j++){
			cin>>s;
			if(mp[s] == 0) mp[s] = ++cnt;
			int x = mp[s];
			if(heap[x][top[x]] == i) continue;
			heap[x][++top[x]] = i;
		}
	}
	m = read();
	for(int i = 1;i <= m;i++){
		cin>>s;
		int x = mp[s];
		if(top[x] == 0) puts("");
		else{
			for(int i = 1;i < top[x];i++)
				printf("%d ",heap[x][i]);
			printf("%d\n",heap[x][top[x]]);		
		}
	}
	return 0;
}
