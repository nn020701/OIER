#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100000
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int n,m,Mi,Mx;
int a[N];

bool check(int x){
	int num = 0,sum = 0;
	for(int i = 1;i <= n;i++){
		if(sum + a[i] > x){
			num++;
			sum = 0;
		}
		sum += a[i];
	}
	num++;
	if(num > m) return false;
	return true;
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		Mi = max(a[i],Mi);
		Mx += a[i];
	}
	int l = Mi,r = Mx;
	while(l < r){
		int mid = (l+r)>>1;
		if(check(mid))
			r = mid;
		else l = mid+1;
	}
	printf("%d\n",r);
	return 0;
}