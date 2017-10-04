#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll unsigned long long
#define gc getchar
#define BASE 1000000000
inline ll read(){
	ll x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}

ll cnt,n,mo[1005];
char c[50005];
struct huge{
	ll num[2000];
	huge(){
		memset(num,0,sizeof num);
	}

	huge operator *(ll b){
		huge ans;
		for(ll i = 1;i <= num[0];i++){
			ans.num[i] += num[i]*(b%BASE);
			ans.num[i+1] += num[i]*(b/BASE);
		}
		for(ll i = 1;i <= num[0]+1;i++){
			ans.num[i+1] += ans.num[i]/BASE;
			ans.num[i] %= BASE;
		}
		ans.num[0] = num[0]+2;
		while(ans.num[0] && !ans.num[ans.num[0]])
			ans.num[0]--;
		return ans;
	}

	huge operator %(ll b){
		huge ans;
		ll x = 0;
		for(ll i = num[0];i >= 1;i--){
			x = x*BASE+num[i];
			ans.num[i] = x/b;
			x %= b;
		}
		c[++cnt] = x+'a';
		ans.num[0] = num[0];
		while(ans.num[0] && !ans.num[ans.num[0]])
			ans.num[0]--;
		return ans;
	}
}ans;


ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b,a%b);
}


int main(){
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	n = read();
	for(ll i = 1;i <= n;i++) mo[i] = read();
	for(ll i = 2;i <= n;i++)
		for(ll j = 1;j < i;j++){
			ll Gcd = gcd(max(mo[i],mo[j]),min(mo[i],mo[j]));
			mo[i] /= Gcd;
		}

	ans.num[0] = ans.num[1] = 1;
	for(ll i = 1;i <= n;i++)
		ans = ans*mo[i];
	while(ans.num[0]) ans = ans%26;
	for(ll i = 1;i <= cnt;i++) putchar('a');
	puts("");
	for(ll i = cnt;i;i--) printf("%c",c[i]);
	puts("");
	return 0;
}