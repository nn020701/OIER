#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
using namespace std;
int n,m,ans,x;
struct mat{
	ll a[105][105];
	friend mat operator *(mat a,mat b){
		static mat c;
		memset(c.a,0,sizeof(c.a));
		for (int i=0;i<=m;i++)
			for (int j=0;j<=m;j++)
				for (int k=0;k<=m;k++)
					c.a[i][k]=(c.a[i][k]+a.a[i][j]*b.a[j][k])%mo;
		return c;
	}
	friend mat operator ^(mat a,int b){
		static mat d;
		memset(d.a,0,sizeof(d.a));
		for (int i=0;i<=m;i++) d.a[i][i]=1;
		for (;b;b/=2,a=a*a)
			if (b&1) d=d*a;
		return d;
	}
}a;
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			scanf("%1d",&x),a.a[i][j]=1-x;
	for (int i=0;i<=m;i++)
		a.a[i][0]=a.a[0][i]=1;
	a=a^(n-1);
	for (int i=0;i<=m;i++)
		for (int j=0;j<=m;j++)
			ans=(ans+a.a[i][j])%mo;
	printf("%d",ans);
}
