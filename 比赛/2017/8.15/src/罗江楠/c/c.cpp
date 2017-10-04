// 暴力出奇迹
#include <bits/stdc++.h>
#define ll long long
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int x[N], k[N], l[N], n, m;
int check(int j){
	int zyy = -1;
	for(int i = m; i; i--)if(j <= x[i]+k[i] && j >= x[i]-k[i]){
		if(zyy == -1) zyy = l[i];
		else if(zyy == l[i]) return 1;
	}
//	printf("%d wa, ok desu. zyy = %d\n", j, zyy);
	return 0;
}
int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= m; i++)
	x[i] = read(), l[i] = read(), k[i] = read();
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += check(i);
	printf("%d\n", ans);
	return 0;
}
