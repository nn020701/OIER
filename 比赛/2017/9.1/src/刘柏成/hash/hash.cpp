#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
ll a[30002];
int cur;
ll get(ll x){
	ll ans=0;
	for(int i=cur;i>=0;i--)
		ans=(ans*26+a[i])%x;
	return ans;
}
void mul(ll x){
	for(int i=0;i<=cur;i++)
		a[i]*=x;
	for(int i=0;i<=cur;i++){
		if (a[i]>=26){
			a[i+1]+=a[i]/26;
			a[i]%=26;	
		}
	}
	while(a[cur+1]){
		cur++;
		if (a[cur]>=26){
			a[cur+1]+=a[cur]/26;
			a[cur]%=26;
		}
	}
}
ll mod[1002];
int main(){
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	int n;
	scanf("%d",&n);
	a[0]=1;
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%llu",&x);
		ll tmp=x/__gcd(get(x),x);
		//printf("%llu\n",get(1e9));
		mul(tmp);
	}
	for(int i=cur;i>=0;i--)
		putchar('a');
	puts("");
	for(int i=cur;i>=0;i--)
		putchar(a[i]+'a');		
}
