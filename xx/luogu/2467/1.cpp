#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define N 4205
inline int read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
    return x*f;
}

struct node{
	int f[N];
}dp[2];//i表示前i个数中有i个不符的，j表示有j个数
int n,p;

int main(){
	n = read(); p = read();
	dp[0].f[0] = 1;
	int down = 0;
	for(int j = 1;j < n;j++,down ^= 1){
		memset(dp[down^1].f,0,sizeof(dp[down^1].f));
		for(int i = 0;i <= j;i++){
			(dp[down^1].f[i] += dp[down].f[i]) %= p;
			(dp[down^1].f[i+1] += (1LL*dp[down].f[i]*(j-i))%p) %= p;
			if(i > 0)
				(dp[down^1].f[i-1] += (1LL*dp[down].f[i]*i)%p) %= p;
		}
	}
	printf("%d\n",(1LL*dp[down].f[0]*2)%p);
	return 0;
}