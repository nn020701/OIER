#include<cstdio>
#include<bitset>
using namespace std;
#define ll long long
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

const int p[10]={961339,964793,907723,990637,945631,959333,955039,925063,924323,905269};

void exgcd(ll a,ll b,ll &d,ll &x,ll &y){//ax+by=d
	if(!b){
		d = a; x = 1; y = 0;
		return;
	}
	else{
		exgcd(b,a%b,d,y,x);
		y -= x*(a/b);
	}
}

ll crt(ll a,ll m,ll b,ll n){//x=km+a=tn+b->km-tn=b-a
	ll d,k,t;
	exgcd(m,n,d,k,t);
	ll w = (b-a);
	ll lcm = m*n;
	return ((k*w*m+a)%lcm+lcm)%lcm;
}

bool can[10];
bitset<1000001> cnt[10];
int p0[501],p1[501];
ll ans[501];
int id0,id1;

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n = read(),k = read();
	while(n--){
		ll x = read();
		for(int i = 0;i < 10;i++)
			cnt[i][x%p[i]].flip();
	}
	int tat = 0;
	for(int i = 0;i < 10;i++){
		if(cnt[i].count() == k){
			can[i] = true;
			if(!tat){
				int cur = 0;
				id0 = i;
				for(int j = 0;j < p[i];j++)
					if(cnt[i][j])
						p0[++cur] = j;
			}
			else if(tat == 1){
				int cur = 0;
				id1 = i;
				for(int j = 0;j < p[i];j++)
					if(cnt[i][j])
						p1[++cur] = j;
			}
			tat++;
		}
	}
	int cur = 0;
	for(int i = 1;i <= k;i++)
		for(int j = 1;j <= k;j++){
			ll qwq = crt(p0[i],p[id0],p1[j],p[id1]);
			bool flag = true;
			for(int o = 0;o < 10;o++)
				if(can[o] && !cnt[o][qwq%p[o]]){
					flag = false;
					break;
				}
			if(flag)
				ans[++cur] = qwq;
		}
	for(int i = 1;i <= k;i++)
		for(int j = i+1;j <= k;j++)
			if(ans[j] < ans[i]){
				ll t=ans[j];
				ans[j]=ans[i];
				ans[i]=t;
			}
	for(int i = 1;i <= k;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
