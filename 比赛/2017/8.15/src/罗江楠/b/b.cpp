#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int mp[10][350][350], n, m;
int test(int x, int y){
	if(x > n || y > m) return 0;
	int sx = n-x+1, sy = m-y+1;
	for(int i = 1; i <= sx; i++)
	for(int j = 1; j <= sy; j++){
		int zyy = 0;
		for(int k = 0; k < 10; k++)
		if((mp[k][i+x-1][j+y-1]-mp[k][i+x-1][j-1]-mp[k][i-1][j+y-1]+mp[k][i-1][j-1])&1)zyy++;
		if(zyy <= 1 && mp[0][i+x-1][j+y-1]-mp[0][i+x-1][j-1]-mp[0][i-1][j+y-1]+mp[0][i-1][j-1] != x*y) return 1;
	}
	return 0;
}
int check(int x){ int i;
	for(i = 1; i*i < x; i++)
	if(x%i == 0 && (test(i, x/i) || test(x/i, i))) return 1;
	if(i*i == x && test(i, i)) return 1;
	return 0;
}
int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			for(int k = 0; k < 10; k++) mp[k][i][j] = mp[k][i-1][j]+mp[k][i][j-1]-mp[k][i-1][j-1];
			mp[read()][i][j]++;
		}
	for(int i = n*m; i; i--) if(check(i)) return printf("%d\n", i)&0;
	puts("0");
	return 0;
}
/*
烧烧烧烧烧　烧烧烧烧烧　烧烧烧烧烧
烧　　　　　烧　　　　　烧　　　　
烧　　　　　烧　　　　　烧　　　　
烧烧烧烧　　烧烧烧烧　　烧烧烧烧　
烧　　　　　烧　　　　　烧　　　　
烧　　　　　烧　　　　　烧　　　　
烧　　　　　烧　　　　　烧　　　　
*/