#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 100005
#define mod 1000000007
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
struct matrix{ ll p[2][2]; }L,R,X,tmp,ans;
matrix operator *(matrix x,matrix y){
    ll i,j,k; matrix z;
    rep(i,0,1) rep(j,0,1){
        ll tmp=0;
        rep(k,0,1) tmp+=(ll)x.p[i][k]*y.p[k][j];
        z.p[i][j]=tmp%mod;
    }
    return z;
}
matrix ksm(matrix x,ll y){
    matrix z=x;
    for (y--;y;y>>=1,x=x*x) if (y&1) z=z*x; return z;
}
char s[N]; ll n,k; 
int main(){
	freopen("heap.in","r",stdin);
	freopen("heap.out","w",stdout);
	scanf("%s",s+1); n=strlen(s+1); k=read();
	L.p[0][0]=2; L.p[1][1]=1;
	R.p[0][0]=2; R.p[1][0]=R.p[1][1]=1;
	X.p[0][0]=5; X.p[1][0]=1; X.p[1][1]=3;
	tmp.p[0][0]=tmp.p[1][1]=ans.p[0][0]=ans.p[0][1]=1;
	rep(i,1,n){
		if (s[i]=='L') tmp=tmp*L;
		if (s[i]=='R') tmp=tmp*R;
		if (s[i]=='*') tmp=tmp*X;
	}
	ans=ans*(ksm(tmp,k));
	printf("%lld",ans.p[0][0]);
}
