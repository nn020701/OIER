/*
	1、f[i]记录从左至右到i前最大子段和；
	2、g[i]记录从右至左到i后最大子段和；
	3、枚举i求max(f[i]+g[i+1])，记录为maxans；
	4、f[i]记录从左至右到i前最小子段和；
	5、g[i]记录从右至左到i后最小子段和；
	6、枚举i求min(f[i],g[i+1])，记录为minans；
	7、枚举i记录a[i]之和为sum；
	8、答案ans为max(max,sum-minans)。
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
#define inf 0x3f3f3f3f
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,sum;
int Max,Min;
int a[N];
int f[N];
int g[N];

int work(){
	int ans = -inf;
	for(int i = 1;i <= n;i++) f[i] = max(f[i-1],0)+a[i];
	for(int i = n;i >= 1;i--) g[i] = max(g[i+1],0)+a[i];
	for(int i = 1;i <= n;i++) f[i] = max(f[i-1],f[i]);
	for(int i = n;i >= 1;i--) g[i] = max(g[i],g[i+1]);
	for(int i = 2;i <= n;i++) ans = max(ans,f[i-1]+g[i]);
	return ans;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	for(int i = 1;i <= n;i++)
		sum += a[i];
	f[0] = g[n+1] = -inf;
	Max = work();
	for(int i = 1;i <= n;i++) a[i] = -a[i];
	Min = work();
	int ans = Max;
	if(sum+Min > 0) ans = max(Max,sum+Min);
	printf("%d\n",ans);
	return 0;
}
