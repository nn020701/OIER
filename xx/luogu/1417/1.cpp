#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define T 100005
#define N 60
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll t,n;
ll f[N][T];
struct node{
	ll a,b,c;
}x[N];

bool cmp (node a,node b){
	return a.b*b.c < b.b*a.c;
}

int main(){
	t = read(); n = read();
	for(ll i = 1;i <= n;i++)
		x[i].a = read();
	for(ll i = 1;i <= n;i++)
		x[i].b = read();
	for(ll i = 1;i <= n;i++)
		x[i].c = read();
	memset(f,0,sizeof f);
	sort(x+1,x+n+1,cmp);
	for(ll i = 1;i <= n;i++){
		for(ll j = 0; j <= t; j++)
			f[i][j] = f[i-1][j];
/*		for(ll j = i+1;j <= n;j++)
			if(x[i].b*x[j].c < x[j].b*x[i].c)
				swap(x[i],x[j]);*/
		for(ll j = x[i].c;j <= t;j++){
			if(x[i].a-x[i].b*j > 0)
				f[i][j] = max(f[i][j],f[i-1][j-x[i].c]+x[i].a-x[i].b*j);
			else break;
		}
	}
	ll ans = 0;
	for(ll i = 1;i <= t;i++)
		ans = max(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}