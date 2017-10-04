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


// const int N = ;
ll n;
ll l,w,h;
ll ans;
int main(){
	freopen("kniforbare.in","r",stdin);
	freopen("kniforbare.out","w",stdout);
	n=read();
	bool flag;
	while(n--){
		l=read(); w=read(); h=read();
		flag=false; ans=0;
		cout<<l*w*h-1<<" ";
		while(l>1){
			if(l%2!=0) flag=true;
			l/=2; ans++;
		}
		if(flag) ans++;
		flag=false;
		while(w>1){
			if(w%2!=0) flag=true;
			w/=2; ans++;
		}
		if(flag) ans++;
		flag=false;
		while(h>1){
			if(h%2!=0) flag=true;
			h/=2; ans++;
		}
		if(flag) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}