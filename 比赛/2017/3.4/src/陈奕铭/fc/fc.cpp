#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll A,B,X;
struct node{
	ll ans[164];
	node(){
		for(ll i=0;i<=162;i++) ans[i]=0;
	}
	
}f[20][10];

node operator -(node a,node b){
	node p;
	for(ll i=1;i<=162;i++) p.ans[i]=a.ans[i]-b.ans[i];
	return p;
}

void dp(){
	for(ll i=0;i<=9;i++)
		f[1][i].ans[i]=1;
	for(ll k=2;k<=18;k++)
		for(ll i=0;i<=9;i++)
			for(ll z=i;z<=162;z++)
				for(ll j=0;j<=9;j++)
					f[k][i].ans[z]+=f[k-1][j].ans[z-i];
}

node shu(ll x){
	ll a[20];
	node ans;
	ll p=x,num=0,q=0;
	while(p>0){
		a[++num]=p%10;
		p/=10;
	}
	for(ll i=num;i>=1;i--){
		for(ll j=0;j<a[i];j++)
			for(ll k=max(q,j);k<=162;k++)
				ans.ans[k]+=f[i][j].ans[k-q];
		q+=a[i];
	}
	ans.ans[q]++;
	return ans;
}

int  main(){
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	ll t=read();
	dp();
	while(t--){
		A=read();B=read();X=read();
		node ans;
		if(A==1) ans=shu(B);
		else ans=shu(B)-shu(A-1);
		ll num=0;
		for(ll i=1;i<=162;i++){
			if(!ans.ans[i]) continue;
			// printf("%lld:%lld\n",i,ans.ans[i]);
			if(ans.ans[i]*i<X){
				num+=ans.ans[i];
				X-=ans.ans[i]*i;
			}
			else{
				num+=X/i;
				break;
			}
		}
		cout<<num<<"\n";
	}
	return 0;
}