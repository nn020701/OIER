#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=305;
int c[10],n,m,ans,s[maxn][maxn][10],a[maxn][maxn];
inline bool judge(int x,int y,int l,int r)
{
	int xx=x+l-1,yy=y+r-1,sum=0,sum2=0;
	memset(c,0,sizeof(c));
	for (int i=0;i<10;i++){
		c[i]=s[xx][yy][i]+s[x-1][y-1][i]-s[x-1][yy][i]-s[xx][y-1][i];
		if (c[i]&1){
			sum++;
		}else{
			if (c[i]){
				sum2++;
			}
		}
	}
	if (sum>1){
		return 0;
	}
	if (c[0]==l*r){
		return 0;
	}
	if (sum2==1&&c[0]>0&&c[0]%2==0){
		return 0;
	}
	return 1;
}
inline void work(int l,int r)
{
	for (int i=1;i<=n-l+1;i++){
		for (int j=1;j<=m-r+1;j++){
			if (judge(i,j,l,r)){
				ans=l*r;
				return;
			}
		}
	}
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<=9;k++){
				s[i][j][k]=s[i-1][j][k]+s[i][j-1][k]-s[i-1][j-1][k]+(a[i][j]==k);
			}
		}
	}
	for (int i=n;i;i--){
		for (int j=m;j;j--){
			if (i*j>ans){
				work(i,j);
			}
		}
	}
	printf("%d\n",ans);
}
