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
char s[N]; ll n,k; 
int main(){
	scanf("%s",s+1); k=read(); n=strlen(s+1);
	ll ans=1,num=1;
	rep(i,1,n){
		if (s[i]=='L') ans=(ans*2)%mod;
		if (s[i]=='R') ans=(ans*2+num)%mod;
		if (s[i]=='*'){
			ans=(ans*5+num)%mod;
			num=num*3%mod;
		}
	}
	printf("%d",ans);
}
