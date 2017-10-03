#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 5012
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n;
ll a[N];
ll lon[N];
ll q[N];
ll top,b[N];
map<ll,bool> mp;

int main(){
	n = read();
	for(ll i = 1;i <= n;i++) a[i] = read();
	for(ll i = 1;i <= n;i++) lon[i] = 1;
	for(ll i = 1;i <= n;i++) q[i] = 1;
	for(ll i = 2;i <= n+1;i++){
		ll maxlon = 0;
		for(ll j = i-1;j >= 1;j--){
			if(a[j] > a[i] && lon[j] > maxlon){
				maxlon = lon[j];
				mp.clear();
				top = 0;
				b[++top] = a[j];
				mp[a[j]] = true;
				q[i] = q[j];
			}
			else{
				if(a[j] > a[i] && lon[j] == maxlon && (!mp[a[j]])){
					q[i] += q[j];
					b[++top] = a[j];
					mp[a[j]] = true;
				}
			}
		}
		lon[i] = maxlon+1;
	}
	printf("%lld %lld",lon[n+1]-1,q[n+1]);
	return 0;
}
