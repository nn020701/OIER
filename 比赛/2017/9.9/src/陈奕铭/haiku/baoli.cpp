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

int num[10];
int N1,X1,Y1,Z1;
int N,X,Y,Z;
int ans;

void pand(int p){
	if(p == N+1){
		for(int n = 1;n <= N-2;n++){
			int o = 0,i;
			for(i = n;i <= N;i++){
				if(o >= X) break;
				o += num[i];
			}
			if(o != X) continue;
			o = 0;
			for(;i <= N;i++){
				if(o >= Y) break;
				o += num[i];
			}
			if(o != Y) continue;
			o = 0;
			for(;i <= N;i++){
				if(o >= Z) break;
				o += num[i];
			}
			if(o != Z) continue;
			ans++;
			return;
		}
		return;
	}
	for(int i = 1;i <= 10;i++){
		num[p] = i;
		pand(p+1);
	}
}

int main(){
	freopen("baoli.out","w",stdout);
	N1 = 8; X1 = 5; Y1 = 7; Z1 = 5;
	putchar('{');
	for(int n = 3;n <= N1;n++){
		putchar('{');
		for(int x = 1;x <= X1;x++){
			putchar('{');
			for(int y = 1;y <= Y1;y++){
				putchar('{');
				for(int z = 1;z <= Z1;z++){
					ans = 0;
					N = n; X = x; Y = y; Z = z;
					pand(1);
					printf("%d",ans);
					if(z != Z1)putchar(',');
				}
				putchar('}');
				if(y != Y1) putchar(',');
			}
			putchar('}');
			if(x != X1) putchar(',');
		}
		putchar('}');
		if(n != N1) putchar(',');
	}
	putchar('}');
	return 0;
}