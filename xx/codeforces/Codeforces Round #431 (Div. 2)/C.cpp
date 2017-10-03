#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int k;
int f[449];
int num[27];

void Print(int cnt){
	for(int i = 1;i <= cnt;i++){
		for(int j = 1;j <= num[i];j++)
			putchar('a'+i-1);
	}
	exit(0);
}

void dfs(int p,int cnt,int k){
	if(k == 0) Print(cnt);
	if(cnt == 27) return;
	for(int i = p;i >= 1;i--)
		if(k >= f[i]){
			num[cnt] = i;
			dfs(i,cnt+1,k-f[i]);
		}
}

int main(){
	int k = read();
	if(k == 0){
		printf("a");
		return 0;
	}
	for(int i = 1;i <= 447;i++)
		f[i] = (i*(i-1))/2;
	// for(int i = 1;i <= 10;i++)
		// printf("%d\n",f[i]);
	// printf("%d\n",f[448]);
	int a;
	for(int i = 447;i >= 1;i--)
		if(k > f[i]){
			a = i;
			break;
		}
	// printf("%d\n",a);12
	dfs(a,1,k);
	return 0;
}