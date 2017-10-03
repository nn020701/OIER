#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int f[7][9][13][24];
int p[16],king;
int h[5];
int biao[4] = {0,5,3,2};
int t,n;
int ans = 1000000;

void dp(){
	for(int a4 = 0;a4 <= n;a4++)
		for(int a3 = 0;a3 <= n;a3++)
			for(int a2 = 0;a2 <= n;a2++)
				for(int a1 = 0;a1 <= n;a1++)
					if(a4*4 + a3*3 + a2*2 + a1 <= n){
						int& a = f[a4][a3][a2][a1];
						a = a4 + a3 + a2 + a1;
						//将所有牌单张打显然是最大可能性
						if(a4 > 0){		//有四张牌存在
							//4
							a = min(f[a4-1][a3][a2][a1]+1,a);
							// = 1 + 3
							a = min(f[a4-1][a3+1][a2][a1+1],a);
							// = 2 + 2
							a = min(f[a4-1][a3][a2+2][a1],a);
							// = 1 + 1 + 2
							a = min(f[a4-1][a3][a2+1][a1+2],a);
							// = 1 + 1 + 1 + 1
							a = min(f[a4-1][a3][a2][a1+4],a);
							if(a1 > 1)	//4 + 1 + 1
								a = min(f[a4-1][a3][a2][a1-2]+1,a);
							if(a2 > 1)  //4 + 2 + 2
								a = min(f[a4-1][a3][a2-2][a1]+1,a);
						}
						if(a3 > 0){		//有三张牌存在
							//3
							a = min(f[a4][a3-1][a2][a1]+1,a);
							// = 1 + 2
							a = min(f[a4][a3-1][a2+1][a1+1],a);
							// = 1 + 1 + 1
							a = min(f[a4][a3-1][a2][a1+3],a);
							if(a1 > 0)//3 + 1
								a = min(f[a4][a3-1][a2][a1-1]+1,a);
							if(a2 > 0)//3 + 2
								a = min(f[a4][a3-1][a2-1][a1]+1,a);
						}
						if(a2 > 0){		//有两张牌存在
							//2
							a = min(f[a4][a3][a2-1][a1]+1,a);
							// = 1 + 1
							a = min(f[a4][a3][a2-1][a1+2],a);
						}
						if(a1 > 0)		//有一张牌存在
							//1
							a = min(f[a4][a3][a2][a1-1]+1,a);
					}
}

int jis(int a1,int a2,int a3,int a4){
	if(king == 0) return f[a4][a3][a2][a1];
	if(king == 1) return f[a4][a3][a2][a1+1];
	else
		return min(f[a4][a3][a2][a1+2],f[a4][a3][a2][a1]+1);
}

void dfs(int step){
	if(step > ans) return;
	memset(h,0,sizeof h);
	for(int i = 3;i <= 15;i++)
		h[p[i]]++;
	ans = min(ans,step+jis(h[1],h[2],h[3],h[4]));
	for(int k = 1;k <= 3;k++){
		for(int i = 3;i <= 14;i++){
			int j;
			for(j = i;j <= 14;j++){
				if(p[j] < k) break;
				p[j] -= k;
				if(j-i+1 >= biao[k])
					dfs(step+1);
			}
			for(j--;j >= i;j--)
				p[j] += k;
		}
	}
}

int main(){
	t = read(); n = read();
	dp();
	while(t--){
		memset(p,0,sizeof p);
		king = 0;
		ans = n;
		for(int i = 1;i <= n;i++){
			int x = read();
			int y = read();
			if(x == 1) p[14]++;
			else if(x == 0) king++;
			else if(x == 2) p[15]++;
			else p[x]++;
		}
		memset(h,0,sizeof h);
		// for(int i = 3;i <= 15;i++)
			// h[p[i]]++;
		// printf("%d\n",f[h[4]][h[3]][h[2]][h[1]]);
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}