#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define gc getchar
inline ll read(){
	ll x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}

ll f[1000005];
ll n,k,ans;
ll a[1000005];
ll Scarlet[1000005],head,tail;

int main(){
	freopen("truancy.in","r",stdin);
	freopen("truancy.out","w",stdout);
	n = read()+1; k = read()+1;
	for(ll i = 1;i < n;i++){
		a[i] = read();
		ans += a[i];
	}
	memset(f,0x3f,sizeof f);
	f[0] = 0; tail = 1; Scarlet[0] = 0;
	for(ll i = 1;i <= n+1;i++){
		if(Scarlet[head] < i-k) head++;
		f[i] = f[Scarlet[head]]+a[i];
		while(head != tail && f[Scarlet[tail-1]] > f[i])
			tail--;
		Scarlet[tail++] = i;
	}
	printf("%lld\n",ans-f[n+1]);
	return 0;
}