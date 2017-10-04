#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define N 205
using namespace std;
int f[N][N][N],a[N],b[N],c[N],nxt[N],v[N];
int n,T,cnt,x,s;
inline void max(int &x,int y){
	x=x<y?y:x;
}
inline int dp(int l,int r,int pre){
	if (l==r) return pre*pre;
	if (f[l][r][pre]!=-1) return f[l][r][pre];
	int mx=pre*pre+dp(l+1,r,b[l+1]);
	for (int i=nxt[l];i<=r;i=nxt[i])
		max(mx,dp(l+1,i-1,b[l+1])+dp(i,r,pre+b[i]));
	return f[l][r][pre]=mx;
} 
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		memset(f,-1,sizeof(f));
		scanf("%d",&n); cnt=0;
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if (x!=a[cnt]) a[++cnt]=x;
			b[cnt]++;
		}
		for (int i=1;i<=n;i++) v[i]=cnt+1;
		for (int i=cnt;i;i--)
			nxt[i]=v[a[i]],v[a[i]]=i;
		printf("Case %d: %d\n",cas,dp(1,cnt,b[1]));
	}
}
