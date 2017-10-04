#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
int get(ll x,pli* res){
	int cur=0;
	for(int i=39;i>=0;i--)
		if ((x>>i)&1)
			res[++cur]=make_pair(x^(1LL<<i),i);
	return cur;
}
pli xl[41],yl[41];
ll sum[41];
ll calc(pli t){
	int tat=64-__builtin_clzll(t.first);
	if (tat<=t.second)
		return sum[t.second];
	if (tat%2){
		int w=tat/2;
		if (t.second<w){
			for(int i=t.second;i<w;i++)
				if (((t.first>>i)&1)!=((t.first>>(tat-i-1))&1))
					return 0;
			return 1;
		}else{
			return 1LL<<(t.second-w);
		}
	}else{
		int w=tat/2;
		if (t.second<w){
			for(int i=t.second;i<w;i++)
				if (((t.first>>i)&1)!=((t.first>>(tat-i-1))&1))
					return 0;
			return 1;
		}else{
			return 1LL<<(t.second-w);
		}
	}
}
ll work(ll x,ll y){
	int tx=get(x,xl),ty=get(y,yl);
	ll ans=0;
	for(int i=1;i<=tx;i++)
		for(int j=1;j<=ty;j++){
			//printf("%lld %lld %d %d\n",xl[i].first,yl[j].first,xl[i].second,yl[j].second);
			pli qwq=make_pair(xl[i].first^yl[j].first,max(xl[i].second,yl[j].second));
			ll tat=calc(qwq)<<(min(xl[i].second,yl[j].second));
			//printf("%lld %d %d %lld\n",qwq.first,qwq.second,min(xl[i].second,yl[j].second),tat);
			ans+=tat;
		}
	return ans;
} 
int main(){
	freopen("sg.in","r",stdin);
	freopen("sg.out","w",stdout);
	int T;
	sum[0]=1;
	for(int i=1;i<=39;i++){
		int qwq=(i-1)/2;
		sum[i]=sum[i-1]+(1LL<<qwq);
		//printf("%lld\n",sum[i]);
	}
	scanf("%d",&T);
	while(T--){
		ll x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		printf("%lld\n",work(x2+1,y2+1)-work(x1,y2+1)-work(x2+1,y1)+work(x1,y1));
	}
}