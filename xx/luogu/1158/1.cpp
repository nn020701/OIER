#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll s1,s2;
}a[100005];
ll n,x1,y1,x2,y2;

bool cmp(node a,node b){
	return a.s1 > b.s1;
}

int main(){
	x1 = read(); y1 = read(); x2 = read(); y2 = read();
	n = read();
	for(ll i = 1;i <= n;i++){
		ll x = read(),y = read();
		a[i].s1 = (x-x1)*(x-x1)+(y-y1)*(y-y1);
		a[i].s2 = (x-x2)*(x-x2)+(y-y2)*(y-y2);
	}
	sort(a+1,a+n+1,cmp);
	ll Mx = 0,ans = 10000000;
	for(ll i = 1;i <= n;i++){
		Mx = max(Mx,a[i-1].s2);
		ans = min(ans,a[i].s1+Mx);
	}
	printf("%lld\n",ans);
	return 0;
}
