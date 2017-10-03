#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 2010
inline int read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f = -1;ch = getchar();}
    while(ch>='0' && ch<='9'){x = x*10+ch-'0';ch = getchar();}
    return x*f;
}

int f[N][N];
int ans[N][N];
int num[N];
int k;

inline void init(){
	for(int i = 0;i < N;i++)
		f[i][0] = 1;
	for(int i = 1;i < N;i++)
		for(int j = 1;j < N;j++){
			f[i][j] = (f[i-1][j-1]+f[i-1][j])%k;
			if(f[i][j] == 0)
				num[i]++;
			ans[i][j] = ans[i-1][j]+num[i];
			if(i == j)
				ans[i][j] = num[i]+ans[i-1][j-1];
		}
}

int main(){
	int t = read(); k = read();
	init();
	for(int i = 1;i <= t;i++){
		int n = read(),m = read();
		if(m > n) m = n;
		printf("%d\n",ans[n][m]);
	}
	return 0;
}