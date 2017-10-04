#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<ll,int>
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}


int get(ll x,pli* res){
	int cur = 0;
	for(int i = 39;i >= 0;i--)
		if((x>>i)&1)
			res[++cur]=make_pair(x^(1LL<<i),i);
	return cur;
}

pli xl[41],yl[41];
ll sum[41];

ll calc(pli t){
	int tat = 64-__builtin_clzll(t.first); //算有多少位数 
	if(tat <= t.second)
		return sum[t.second];
	int w = tat/2;
	if(t.second < w){
		for(int i = t.second;i < w;i++)
			if(((t.first>>i)&1) != ((t.first>>(tat-i-1))&1))
				return 0;
		return 1;
	}
	else return 1LL<<(t.second-w);
}

ll work(ll x,ll y){
	int tx = get(x,xl),ty = get(y,yl);
	ll ans = 0;
	for(int i = 1;i <= tx;i++)
		for(int j = 1;j <= ty;j++){
			pli qwq = make_pair(xl[i].first^yl[j].first,max(xl[i].second,yl[j].second));
			ll tat = calc(qwq)<<(min(xl[i].second,yl[j].second));
			ans += tat;
		}
	return ans;
} 

int main(){
	freopen("sg.in","r",stdin);
	freopen("sg.out","w",stdout);
	sum[0] = 1;
	for(int i = 1;i <= 39;i++){
		int qwq = (i-1)/2;
		sum[i] = sum[i-1]+(1LL<<qwq);
	}
	int t = read();
	while(t--){
		ll x1,y1,x2,y2;
		x1 = read(); y1 = read(); x2 = read(); y2 = read();
		printf("%lld\n",work(x2+1,y2+1)-work(x1,y2+1)-work(x2+1,y1)+work(x1,y1));
	}
}
