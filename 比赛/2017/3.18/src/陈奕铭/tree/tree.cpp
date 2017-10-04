#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=40005;
int n,m,rt;
int q[N],cnt;
int f[N][17],depth[N];
int a[N],b[N],Mx;
vector<int> edge[N];
/*预处理用到的dfs */
void dfs(int x,int fa,int d){
	depth[x]=d;
	f[x][0]=fa;
	for(int i=0;i<edge[x].size();i++)
		if(edge[x][i]!=fa)
			dfs(edge[x][i],x,d+1);
}
/*lca */
int lca(int u,int v){
	int ans=0;
	if(depth[u]>depth[v]){swap(u,v);ans++;}
	if(depth[u]==depth[v]&&u!=v) return 0;
	int dis=depth[v]-depth[u];
	for(int k=0;k<17;k++)
		if((dis>>k)&1)
			v=f[v][k];
	if(v==u) return ans+1;
	else	 return 0;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	q[0]=-1;
	for(int i=1;i<=n;i++){
		a[i]=read(); b[i]=read();
		if(b[i]==-1) b[i]=0;
		if(q[a[i]]==0) q[a[i]]=++cnt;
		if(q[b[i]]==0) q[b[i]]=++cnt;
		if(b[i]==0) rt=q[a[i]];
		edge[q[a[i]]].push_back(q[b[i]]);
		edge[q[b[i]]].push_back(q[a[i]]);
//		printf("#%d : %d; #%d : %d\n",a[i],q[a[i]],b[i],q[b[i]]);
	}
	/*预处理st表*/
	dfs(rt,-1,0);
//	for(int i=1;i<=cnt;i++)
//		printf("#%d\n",f[i][0]);
	for(int j=0;j<16;j++)
		for(int i=1;i<=cnt;i++){
			if(f[i][j]<0) f[i][j+1]=-1;
			else f[i][j+1]=f[f[i][j]][j];
		}
//	printf("#%d\n",f[10][1]);
	/*计算*/
	int x,y; m=read();
	for(int i=1;i<=m;i++){
		x=read(); y=read();
//		printf("#%d : %d; #%d : %d\n",x,q[x],y,q[y]);
		x=q[x]; y=q[y];
//		printf("# %d , %d\n",x,y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
