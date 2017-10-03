#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

bool zhishu[20005];
int n;

int main(){
	n = read();
	for(int i = 2;i <= sqrt(n);i++)
		for(int j = 2;j <= n/i;j++)
			zhishu[i*j] = true;
	for(int a = 2;a <= n/3;a++)
		if(!zhishu[a])
			for(int b = a;b <= (n-a)/2;b++)
				if(!zhishu[b] && !zhishu[n-a-b]){
					printf("%d %d %d\n",a,b,n-a-b);
					return 0;
				}
	return 0;
}