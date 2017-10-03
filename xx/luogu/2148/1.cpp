#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int n,sg;
bool vis[55];
int sgg[55][55];
/*
void getsg(){
	sgg[1][1] = 0;
	for(int a = 2;a <= 50;a++)
		for(int b = 1;b <= a;b++){
			memset(vis,0,sizeof vis);
			for(int c = 1;c < a;c++)
				vis[sgg[max(a-c,c)][min(a-c,c)]] = true;
			for(int c = 1;c < b;c++)
				vis[sgg[max(b-c,c)][min(b-c,c)]] = true;
			int p = 0;
			while(vis[p]) p++;
			sgg[a][b] = p;
		}
	for(int a = 1;a <= 50;a++,puts(""))
		for(int b = 1;b <= a;b++)
			printf("%d ", sgg[a][b]);
}*/

int getsg(int a,int b){
	int Sg = 0 ;
	while(1){
		if(a%2 == 1 && b%2 == 1)
			return Sg;
		if(a%2 == 1)
			a++;
		else if(b%2 == 1)
			b++;
		else{
			a >>= 1;
			b >>= 1;
			Sg++;
		}
	}
}

int main(){
	// freopen("1.out","w",stdout);
	// getsg();
	int T = read();
	// int T = 0;
	while(T--){
		n = read()/2;
		sg = 0;
		for(int i = 1;i <= n;i++){
			int a = read(),b = read();
			sg ^= getsg(a,b);
		}
		if(sg != 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}