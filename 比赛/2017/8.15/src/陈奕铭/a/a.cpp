#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
#define ll long long
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

ll n,W;
ll a[N][N],p[N][N],q[N][N];
ll ans;

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n = read(); W = read();
	for(ll i = 1;i <= n;i++)
		for(ll j = 1;j <= n;j++)
			a[i][j] = read();
	for(ll i = 1;i <= n;i++)
		for(ll j = 1;j <= n;j++){
			p[i][j] = p[i-1][j-1]+a[i][j];
			q[i][j] = q[i-1][j+1]+a[i][j];
		}
/*
	puts("");
	for(ll i = 1;i <= n;i++,puts(""))
		for(ll j = 1;j <= n;j++)
			printf("%lld ",p[i][j]);
	puts("");
	for(ll i = 1;i <= n;i++,puts(""))
		for(ll j = 1;j <= n;j++)
			printf("%lld ",q[i][j]);
*/


	for(ll i = 1;i <= n;i++)		//这里枚举的是正方形的中心 
		for(ll j = 1;j <= n;j++){
			ll l=1,r=min(min(i,n-i+1),min(j,n-j+1));
			while(l<=r){
				ll mid=(l+r)>>1;
				if(p[i+mid-1][j+mid-1]-p[i-mid][j-mid]+q[i+mid-1][j-mid+1]-q[i-mid][j+mid]-a[i][j] <= W){
					l=mid+1;
					ans=max(ans,mid*2-1);
				}
				else r=mid-1;
			}
		}
	for(ll i = 1;i < n;i++)
		for(ll j = 1;j < n;j++){
			ll l=1,r=min(min(i,n-i),min(j,n-j));
			while(l<=r){
				ll mid=(l+r)>>1;
				if(p[i+mid][j+mid]-p[i-mid][j-mid]+q[i+mid][j-mid+1]-q[i-mid][j+mid+1] <= W){
					l=mid+1;
					ans=max(ans,mid*2);
				}
				else r=mid-1;
			}
		}
	printf("%lld\n",ans);
	return 0;
}
