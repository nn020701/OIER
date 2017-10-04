#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=105,mod=10000,inf=1e9;
struct pp{
	int l,r,step;
}q[mod+5];
char s[maxn];
bool vis[maxn][11][11];
int h,t,a[maxn],f[maxn][11][11];
inline void update(int l,int r,int step,int ll,int rr,int ss)
{
	if (ll<1||ll>10||rr<1||rr>10||ll>=rr) return;
	if (f[ss][ll][rr]>f[step][l][r]+1){
		f[ss][ll][rr]=f[step][l][r]+1;
		if (!vis[ss][ll][rr]){
			vis[ss][ll][rr]=1;
			q[t=t%mod+1]=(pp){ll,rr,ss}; 
		}
	}
}
int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	while (gets(s+1)){
		int n=strlen(s+1);
		if (n==0){
			puts("0"); 
			continue; 
		}
		for (int i=1;i<=n;i++) {
			a[i]=s[i]-'0';
			if (!a[i]) a[i]=10;
		}
		h=0; 
		t=1;
		q[1]=(pp){5,6,0};
		memset(f,127/3,sizeof(f));
		memset(vis,0,sizeof(vis));
		f[0][5][6]=0;
		vis[0][5][6]=1;
		while (h!=t){
			pp now=q[h=h%mod+1];
			int l=now.l,r=now.r,step=now.step;
			vis[step][l][r]=0;
			for (int i=-1;i<=1;i++)
				for (int j=-1;j<=1;j++) {
					update(l,r,step,l+i,r+j,step);
				}
			if (step<n){
				if (l==a[step+1]){
					for (int i=-1;i<=1;i++){
						update(l,r,step,l,r+i,step+1);
					}
				}
				if (r==a[step+1]){
					for (int i=-1;i<=1;i++){
						update(l,r,step,l+i,r,step+1);
					}
				}
			}
		}
		int ans=inf;
		for (int i=1;i<10;i++)
			for (int j=i+1;j<=10;j++) ans=min(ans,f[n][i][j]);
		printf("%d\n",ans);
	}
	return 0;
}
