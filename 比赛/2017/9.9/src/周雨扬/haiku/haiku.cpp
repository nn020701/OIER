#include<bits/stdc++.h>
#define N 40005
#define mo 1000000007
using namespace std;
int ch[N][10],f[2][N][2],a[5],fail[N];
int n,b[20],q[N],ans,cnt,sum,ed[N];
void dfs(int x,int y,int z){
	if (z==a[y]) y++,z=0;
	if (y>3){
		int tmp=0; sum++;
		for (int i=1;i<x;i++){
			if (ch[tmp][b[i]]==-1)
				ch[tmp][b[i]]=++cnt;
			tmp=ch[tmp][b[i]];
		}
		ed[tmp]=1;
		return;
	}
	for (int i=1;z+i<=a[y];i++)
		b[x]=i,dfs(x+1,y,z+i);
}
int main(){
	freopen("haiku.in","r",stdin);
	freopen("haiku.out","w",stdout);
	scanf("%d%d%d%d",&n,&a[1],&a[2],&a[3]);
	memset(ch,-1,sizeof(ch));
	dfs(1,1,0);
	int h=0,t=0;
	for (int i=1;i<=10;i++)
		if (ch[0][i]==-1) ch[0][i]=0;
		else{
			fail[ch[0][i]]=0;
			q[++t]=ch[0][i];
		}
	while (h!=t){
		int x=q[++h];
		for (int i=1;i<=10;i++){
			int fa=fail[x];
			while (fa!=0&&ch[fa][i]==-1)
				fa=fail[fa];
			if (ch[x][i]==-1) ch[x][i]=ch[fa][i];
			else fail[ch[x][i]]=ch[fa][i],q[++t]=ch[x][i];
		}
	}
	f[0][0][0]=1;
	for (int i=1;i<=n;i++){
		memset(f[i&1],0,sizeof(f[i&1]));
		for (int j=0;j<=cnt;j++)
			for (int k=0;k<2;k++)
				for (int l=1;l<=10;l++)
					(f[i&1][ch[j][l]][ed[ch[j][l]]|k]+=f[(i&1)^1][j][k])%=mo;
	}
	for (int i=0;i<=cnt;i++)
		ans=(ans+f[n&1][i][1])%mo;
	printf("%d\n",ans);
}
