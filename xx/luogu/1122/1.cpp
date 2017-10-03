#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 16005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[N];
int f[N][2];		//有没有包括该节点 
int ans;
vector<int> edge[N];

void dfs(int x,int fa){
	int Max = 0; f[x][1] = a[x];
	for(int i = 0;i < edge[x].size();i++){
		if(edge[x][i] == fa) continue;
		dfs(edge[x][i],x);
		Max = max(f[edge[x][i]][1],f[edge[x][i]][0]);
		if(f[edge[x][i]][1] > 0) f[x][1] += f[edge[x][i]][1];
	}
	f[x][0] = Max;
}

int main(){
	n = read();
	bool flag = true;
	for(int i = 1;i <= n;i++){
		a[i] = read();
		if(a[i] > 0) flag = false;
	}
	if(flag){
		int Max = -99999999;
		for(int i = 1;i <= n;i++)
			Max = max(Max,a[i]);
		printf("%d\n",Max);
		return 0;
	}
	for(int i = 1;i < n;i++){
		int a = read(),b = read();
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1,1);
	int Max = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 0;j < 2;j++)
			Max = max(Max,f[i][j]);
	printf("%d\n",Max);
	return 0;
}
