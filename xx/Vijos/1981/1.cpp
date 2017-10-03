#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 50005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int n,m,len,ans;
int x[N];

bool jis(int y){
	int pos = 0,num = 0;
	for(int i = 1;i <= n+1;i++){
		if(x[i]-pos < y)
			num++;
		else pos = x[i];
	}
	return num <= m;
}

int main(){
	len = read(); n = read(); m = read();
	for(int i = 1;i <= n;i++)
		x[i] = read();
	x[n+1] = len;
	int l = 1,r = 1e9;
	int mid;
	while(l <= r){
		mid = (l+r) >> 1;
		if(jis(mid)){
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	printf("%d\n",ans);
	return 0;
}