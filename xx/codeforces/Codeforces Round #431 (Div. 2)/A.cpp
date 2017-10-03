#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 105
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int n;
int a[N];

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	if(n % 2 == 0){
		printf("No\n");
		return 0;
	}
	if(a[1] % 2 == 0 || a[n] % 2 == 0){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}