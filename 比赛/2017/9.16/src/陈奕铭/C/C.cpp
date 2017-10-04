#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n;
int s[105];
int f[105][11],ans;

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	char c = getchar();
	while(c != EOF){
		n = 0;
		while(c != '\n' && c != EOF){
			s[++n] = c - '0';
			if(s[n] == 0) s[n] = 10;
			c = getchar();
		}
		s[0] = 5;
		if(n == 0){
			printf("0\n");
			c = getchar();
			continue;
		}
		memset(f,0x3f,sizeof f);
		f[0][6] = 0;
		for(int i = 1;i <= n;i++){
			int p = s[i];
			int k = s[i-1];
			for(int j = 1;j < k;j++){		//left?
				for(int l = 1;l < p;l++)
					f[i][l] = min(f[i][l],f[i-1][j]+1+max(abs(j-l)-1,abs(p-k)));
				for(int l = p+1;l <= 10;l++)
					f[i][l] = min(f[i][l],f[i-1][j]+1+max(abs(p-j),abs(k-l)-1));
			}
			for(int j = k+1;j <= 10;j++){
				for(int l = 1;l < p;l++)
					f[i][l] = min(f[i][l],f[i-1][j]+1+max(abs(p-j),abs(k-l)-1));
				for(int l = p+1;l <= 10;l++)
					f[i][l] = min(f[i][l],f[i-1][j]+1+max(abs(j-l)-1,abs(p-k)));
			}
		}
		ans = 1e9;
		for(int i = 1;i <= 10;i++)
			ans = min(ans,f[n][i]);
		printf("%d\n",ans);
		c = getchar();
	}
	return 0;
}