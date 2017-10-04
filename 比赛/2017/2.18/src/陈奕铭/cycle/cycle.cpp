#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int e[5010][5010];
int len_e[5010];
char ss[5010][5010];
int n;
int s[5];
int top;
bool vis[5010];
int p;
void dfs(int u,int step){
	int len=len_e[u];
	if(step==3){
		if(ss[u][s[0]-1]=='1'){
			printf("%d %d %d\n",s[0],s[1],u);
			exit(0);
		}
		return;
	}
	vis[u]=true;
	s[top++]=u;
	for(int i=0;i<len;i++){
		if(!vis[e[u][i]])
			dfs(e[u][i],step+1);
	}
	vis[u]=false;
	top--;
}
int main(){
//	freopen("cycle.in","r",stdin);
//	freopen("cycle.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		gets(ss[i]);
		for(int j=1;j<=n;j++)
			if(ss[i][j-1]=='1')
				e[i][len_e[i]++]=j;
	}
	for(int i=1;i<=n;i++)
		dfs(i,1);
	printf("-1\n");
	return 0;
}
