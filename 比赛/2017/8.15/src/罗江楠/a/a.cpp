#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
long long mp[1020][1020], orz[1020][1020], zyy[1020][1020], n, w;
bool check(int x){
//	printf("Checked:%d\n", x);
	int sz = n-x+1;
	memset(orz, 0, sizeof(int)*1020*1020);
	memset(zyy, 0, sizeof(int)*1020*1020);
	for(int i = 1; i <= sz; i++) for(int j = 1; j <= sz; j++){
		if(orz[i-1][j-1]) orz[i][j] = orz[i-1][j-1]-mp[i-1][j-1]+mp[i+x-1][j+x-1];
		else for(int k = 0; k < x; k++) orz[i][j] += mp[i+k][j+k];
		if(zyy[i-1][j+1]) zyy[i][j] = zyy[i-1][j+1]-mp[i-1][j+x]+mp[i+x-1][j];
		else for(int k = 0; k < x; k++) zyy[i][j] += mp[i+k][j+x-k-1];
	}
	if(x&1){
		int szb = x>>1;
		for(int i = 1; i <= sz; i++)
		for(int j = 1; j <= sz; j++)
		if(orz[i][j]+zyy[i][j]-mp[i+szb][j+szb] > w) return false;
	}
	else
	for(int i = 1; i <= sz; i++)
	for(int j = 1; j <= sz; j++) if(orz[i][j]+zyy[i][j] > w) return false;
//	puts("It is ok!");
	return true;
}
int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	n = read(); w = read();
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) mp[i][j] = read();
	int l = 0, r = n, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, l = mid+1;
		else r = mid-1;
	}
	printf("%d\n", ans);
	return 0;
}
