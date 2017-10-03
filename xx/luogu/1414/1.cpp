#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 10005
#define M 1000005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int a[N];
int num[M];
int n,MX;
int ans[N];

int main(){
	n = read();
	for(int i = 1;i <= n;++i){
		a[i] = read();
		MX = max(MX,a[i]);
		int len = sqrt(a[i]);
		for(int j = 1;j <= len;++j){
			if(a[i] % j == 0){
				num[j]++;
				num[a[i]/j]++;
			}
		}
		if(len*len == a[i]) num[len]--;
	}
	for(int i = MX;i >= 1;i--){
		if(ans[num[i]] == 0)
			ans[num[i]] = i;
	}
	for(int i = n;i >= 1;i--)
		if(ans[i] < ans[i+1])
			ans[i] = ans[i+1];
	for(int i = 1;i <= n;++i)
		printf("%d\n", ans[i]);
	return 0;
}