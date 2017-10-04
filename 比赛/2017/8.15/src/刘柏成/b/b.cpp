#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();
	while(c<'0' || c>'9')
		c=getchar();
	int val=0;
	while(c>='0' && c<='9')
		val=val*10+c-'0',c=getchar();
	return val;
}
int a[301][301],sum[301][301][10];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read(),sum[i][j][a[i][j]]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<10;k++)
				sum[i][j][k]+=sum[i][j-1][k]+sum[i-1][j][k]-sum[i-1][j-1][k];
	//puts("WTF");
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=i;k++)
				for(int t=1;t<=j;t++){
					int tat=0,cnt=0;
					for(int o=0;o<10;o++){
						int qwq=sum[i][j][o]-sum[k-1][j][o]-sum[i][t-1][o]+sum[k-1][t-1][o];
						if (qwq%2)
							cnt++;
						if (o)
							tat+=qwq;
					}
					if (tat>1 && cnt<=1)
						ans=max(ans,(i-k+1)*(j-t+1));
				}
	printf("%d",ans);
}

