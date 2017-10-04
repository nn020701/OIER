#include <iostream> 	  			   	 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 41
#define mod 1000000007
#define M 17
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,x,y,z;
int p[N],f[N][1 << M];
int End;

int dp(int i,int j){
	if(i == n) return 0;
	if(f[i][j] < f[0][0]) return f[i][j];
	ll res = 0;
	for(int k = 1;k <= 10;k++){
		int nxt = (j << k)|1;
		if((nxt & End) == End)
			res += p[n-1-i];
		else
			res += dp(i+1,nxt & ((1 << 17)-1));
	}
	return f[i][j] = res % mod;
}

int main(){
	freopen("haiku.in","r",stdin);
	freopen("haiku.out","w",stdout);
	memset(f,0x3f,sizeof f);
	n = read(); x = read(); y = read(); z = read();
	p[0] = 1;
	for(int i = 1;i < N;i++)
		p[i] = p[i-1]*10LL%mod;
	End = (1<<x)|(1<<(x+y))|(1<<(x+y+z));
	printf("%d\n",dp(0,1));
	return 0;
}