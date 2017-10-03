#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200001
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n;
ll ans,Mx;
ll w[N];
ll nxt[N*2],to[N*2],head[N],cnt;

void insert(ll u,ll v){
	to[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt;
	to[++cnt] = u; nxt[cnt] = head[v]; head[v] = cnt;
}

void dfs(ll x,ll f1,ll f2){
	ll num = 0,Max = 0;
	ans = (ans+w[x]*w[f2])%10007;
	Mx = max(w[x]*w[f2],Mx);
	for(ll i = head[x];i;i = nxt[i])
		if(to[i] != f1){
			ans = (ans+w[to[i]]*num)%10007;
			Mx = max(w[to[i]]*Max,Mx);
			Max = max(Max,w[to[i]]);
			num = (num+w[to[i]])%10007;
			dfs(to[i],x,f1);
		}
	return;
}

int main(){
	n = read();
	for(ll i = 1;i < n;i++){
		ll u = read(),v = read();
		insert(u,v);
	}
	for(ll i = 1;i <= n;i++)
		w[i] = read();
	dfs(1,0,0);
	printf("%lld %lld\n",Mx,(ans*2)%10007);
	return 0;
}
