#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 3005
#define M 400005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int n,m,q;
vector<int> to[N],from[N];
struct problem{
	int k,s,num;
};
vector<problem> pro[N];
bool vis[N];
int f[N][13];
int ans[M];

void dfs(int x){
	vis[x] = true;
	for(unsigned int i = 0;i < from[x].size();i++)
		if(!vis[from[x][i]])
			dfs(from[x][i]);
}

int main(){
	n = read(); m = read(); q = read();
	for(int i = 1;i <= m;i++){
		int a = read(),b = read();
		from[b].push_back(a);
		to[a].push_back(b);
	}
	for(int i = 1;i <= n;i++)
		sort(to[i].begin(),to[i].end());
	for(int i = 1;i <= q;i++){
		int s = read(),t = read(),k = read()-1;
		problem node;
		node.s = s; node.k = k; node.num = i;
		pro[t].push_back(node);
	}
	for(int i = 1;i <= n;i++){
		if(pro[i].size() == 0) 
			continue;
		memset(vis,false,sizeof vis);
		memset(f,0,sizeof f);
		dfs(i);
		f[n+1][0] = f[i][0] = n+1;
		for(int j = 1;j <= n;j++){
			if(j == i)
				continue;
			f[j][0] = 0;
			if(vis[j])
				for(unsigned int k = 0;k < to[j].size();k++)
					if(vis[to[j][k]]){
						f[j][0] = to[j][k];
						break;
					}
		}
		for(int j = 1;j <= 12;j++)
			for(int k = 1;k <= n+1;k++)
				f[k][j] = f[f[k][j-1]][j-1];
		// printf("%d: \n", i);
		// for(int j = 0;j <= 12;++j,puts("")){
		// 	for(int k = 1;k <= n+1;++k){
		// 		printf("%d ",f[k][j]);
		// 	}
		// }
		// puts("");
		for(unsigned int j = 0;j < pro[i].size();j++){
			problem node = pro[i][j];
			ans[node.num] = -1;
			if(f[node.s][12] == n+1 || f[node.s][12] == i){
				for(int k = 0;k <= 12;k++)
					if((node.k >> k) & 1)
						node.s = f[node.s][k];
				if(node.s != n+1)
					ans[node.num] = node.s;					
			}
		}
	}
	for(int i = 1;i <= q;i++)
		printf("%d\n",ans[i]);
	return 0;
}