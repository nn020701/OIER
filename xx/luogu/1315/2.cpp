#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
int t[N],s[N],ed[N],tou[N];
int f[N];
ll ans;

int main(){
	n = read(); m = read(); k = read();
	for(int i = 1;i < n;i++) s[i] = read();
	for(int i = 1;i <= m;i++){
		int a = read(),x = read(),y = read();
		t[x] = max(t[x],a);
		ed[y]++; ans -= a;
	}
	for(int i = 1;i <= n;i++)
		tou[i] = max(tou[i-1],t[i-1])+s[i-1];
	while(k--){
		for(int i = n;i > 1;i--){
			if(s[i-1] == 0) f[i-1] = 0;
			else{
				f[i-1] = ed[i];
				if(tou[i] > t[i]) f[i-1] += f[i];
			}
		}
		int Max = 0,p;
		for(int i = 1;i < n;i++)
			if(f[i] > Max){
				Max = f[i];
				p = i;
			}
		if(Max == 0) break;
		s[p]--;
		for(int i = 1;i <= n;i++)
			tou[i] = max(tou[i-1],t[i-1])+s[i-1];
	}
	for(int i = 1;i <= n;i++)
		ans += 1LL*ed[i]*tou[i];
	printf("%lld\n",ans);
	return 0;
}
