#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const Ll N=1e3+5;
int a[N][N],b[N][N][10];
int n,m,ans;
bool check(int x,int y,int xx,int yy){
	int o=0,oo=0;
	for(int k=9;k>=0;k--){
		int sum=b[xx][yy][k]-b[x-1][yy][k]-b[xx][y-1][k]+b[x-1][y-1][k];
		if(sum==0)continue;
		if(sum&1)o++;else if(k)oo=1;
	}
	if(o>1||!oo)return 0;return 1;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int k=0;k<=9;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				b[i][j][k]=b[i-1][j][k]+b[i][j-1][k]-b[i-1][j-1][k]+(int)(a[i][j]==k);
	for(int i=n;i;i--)
		for(int j=m;j;j--)if(i*j<=ans)break;else
			for(int ii=1;ii<=i;ii++)
				for(int jj=1;jj<=j;jj++)
					if((i-ii+1)*(j-jj+1)<=ans)break;else
					if(check(ii,jj,i,j))ans=(i-ii+1)*(j-jj+1);
	printf("%d",ans);
	
}

