#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
using namespace std;
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int a[N];
bool v[25];
int n,k;

int main(){
	n = read(); k = read();
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < k;j++){
			int x = read();
			if(x == 1) a[i] |= 1<<j;
		}
		if(a[i] == 0){
			printf("YES\n");
			return 0;
		}
		for(int j = 0;j <= 15;j++)
			if(v[j] && (j&a[i]) == 0){
				printf("YES\n");
				return 0;
			}
		v[a[i]] = true;
	}
	printf("NO\n");
	return 0;
}