#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=x*10-48+ch;
	return x;
}
ll ans;
int n,mn=0x3f3f3f3f,x;
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout); 
	n=read();
	for (int i=1;i<=n;i++){
		x=read();
		ans+=x;
		if (x&1) mn=min(mn,x);
	}
	if (~ans&1) ans-=mn;
	printf("%I64d",ans);
}

