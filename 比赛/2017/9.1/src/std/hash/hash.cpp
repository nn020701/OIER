#include<bits/stdc++.h>
#define ll unsigned long long
#define mo 1000000000 
using namespace std;
int n,top,b[50005];
ll a[1005];
struct big{
	ll a[2000];
	big(){
		memset(a,0,sizeof(a));
	}
	friend big operator *(const big &a,ll b){
		big c;
		for (int i=1;i<=a.a[0];i++){
			c.a[i]+=a.a[i]*(b%mo);
			c.a[i+1]+=a.a[i]*(b/mo);
		}
		for (int i=1;i<=a.a[0]+1;i++){
			c.a[i+1]+=c.a[i]/mo;
			c.a[i]%=mo;
		}
		c.a[0]=a.a[0]+2;
		while (c.a[0]&&!c.a[c.a[0]]) c.a[0]--;
		return c;
	}
	friend big operator %(big a,ll b){
		big c; ll x=0;
		for (int i=a.a[0];i;i--){
			x=x*mo+a.a[i];
			c.a[i]=x/b;
			x%=b;
		}
		::b[++top]=x;
		c.a[0]=a.a[0];
		while (c.a[0]&&!c.a[c.a[0]]) c.a[0]--;
		return c;
	}
}ans;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%llu",&a[i]);
	for (int i=2;i<=n;i++)
		for (int j=1;j<i;j++){
			ll tmp=gcd(a[i],a[j]);
			a[i]/=tmp;
		}
	ans.a[0]=ans.a[1]=1;
	for (int i=1;i<=n;i++) ans=ans*a[i];
	while (ans.a[0]) ans=ans%26;
	for (int i=1;i<=top;i++) putchar('a');
	puts("");
	for (int i=top;i;i--) putchar('a'+b[i]);
	puts("");
}
