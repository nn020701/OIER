#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int ans[30] = {0,1,2,3,5,7,9,13,18,21,27,34,39,46,54,61,72,83,92,106,118,130,145,162,176,193};
int n;

int main(){
	n = read();
	printf("%d\n",ans[n]);
	return 0;
}