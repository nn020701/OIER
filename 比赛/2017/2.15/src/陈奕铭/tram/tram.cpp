#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=110;
const int INF =(1<<30);
int w[N][N];
int n,s,t;
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(w[i][k]!=INF&&w[k][j]!=INF)
					w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
}

int main()
{
	freopen("tram.in","r",stdin);
	freopen("tram.out","w",stdout);
	n=read();s=read();t=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=INF;
	for(int u=1,tmp;u<=n;u++){
		tmp=read();
		for(int j=1,v;j<=tmp;j++){
			v=read();
			if(j==1)
				w[u][v]=0;
			else
				w[u][v]=1;
		}
	}
	Floyd();
	if(w[s][t]==INF)
		printf("-1\n");
	else
		printf("%d\n",w[s][t]);
	return 0;
}
