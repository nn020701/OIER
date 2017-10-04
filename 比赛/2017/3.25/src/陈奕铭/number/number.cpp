#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int N=1000005;
bool pin[N];
ll n,m1,m2,ans,p;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=read();
	m1=(ll)sqrt(n);
	m2=(ll)pow(n+1e-9,1.0/3);
	for(ll i=2;i<=m2;i++)
		if(!pin[i]){
			ans+=(ll)(log((long double)n+1e-9)/log((long double)i)-1);
			for(ll j=i*i;j<=m1;j*=i){
				if(j>m2) ans--;
				else pin[j]=true;
			}
		}
	ans+=1+m1-m2;
	cout<<ans<<endl;
	return 0;
}
