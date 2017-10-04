#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=50005;
ll a[N],b[N];
ll ans;
ll la[N],lb[N],lb2[N];
ll n,cnt;

int main(){
	freopen("mat.in","r",stdin);
	freopen("mat.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	sort(a+1,a+n+1); sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		la[i]=a[i]+la[i-1];
		lb[i]=b[i]+lb[i-1];
		lb2[i]=lb2[i-1]+b[i]*b[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]>b[cnt+1]&&cnt<n) cnt++;
		ans+=a[i]*a[i]*(cnt*2-n);
		ans+=lb2[cnt]*2-lb2[n];
		ans-=2*a[i]*(lb[cnt]*2-lb[n]);
	}
	printf("%.1lf",(double)ans/n);
	return 0;
}
