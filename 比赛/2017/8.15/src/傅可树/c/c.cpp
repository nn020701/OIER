#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10005;
int n,m;
bool flag[maxn],lis[maxn][maxn];
int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d%d",&n,&m);
	memset(flag,1,sizeof(flag));
	for (int i=1;i<=m;i++){
		int k,l,x,s,t;
		scanf("%d%d%d",&x,&l,&k);
		if (x-k<0){
			s=1;
		}else{
			s=x-k;
		}
		if (x+k>n){
			t=n;
		}else{
			t=x+k;
		}
		for (int j=s;j<=t;j++){
			if (lis[j][l]){
				flag[j]=1;
			}else{
				flag[j]=0;
				lis[j][l]=1;
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (flag[i]){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
