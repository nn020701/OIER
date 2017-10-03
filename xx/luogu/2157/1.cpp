#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 1005
#define INF 0x3f3f3f3f
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int n;
int f[N][20][256];
int w[N],b[N];

int main(int argc, char const *argv[]){
	int T = read();
	while(T--){
		memset(f,0x3f,sizeof f);
		n = read();
		for(int i = 1;i <= n;++i){
			w[i] = read(); b[i] = read();
		}
		f[1][7][0] = 0;
		for(int i = 1;i <= n;++i)
			for(int j = 0;j <= (1<<8)-1;++j)
				for(int k = -8;k <= 7;++k)
					if(f[i][k+8][j] < INF){
						if(j & 1)
							f[i+1][k+7][j>>1] = min(f[i+1][k+7][j>>1],f[i][k+8][j]);
						else{
							int p = INF;
							for(int z = 0;z <= 7;++z){
								if(!((j>>z) & 1)){
									if(i+z > p) break;
									p = min(p,i+z+b[i+z]);
									f[i][z+8][j | (1<<z)] = min(f[i][z+8][j | (1<<z)],f[i][k+8][j]+(i+k?(w[i+k]^w[i+z]):0));
								}
							}
						}
					}
		int ans = INF;
		for(int i = 0;i <= 8;++i)
			ans = min(ans,f[n+1][i][0]);
		printf("%d\n", ans);
	}
	return 0;
}