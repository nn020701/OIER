#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 100005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int n,m;
int a[N];

bool check(int x){
	int l = 1;
	int num = 0;
	for(int i = 2;i <= n;i++){
		if(a[i]-a[l] < x){
			num++;
		}
		else l = i;
	}
	if(num > m) return false;
	return true;
}

int main(){
	n = read(); m = read();
	m = n-m;
	for(int i = 1;i <= n;i++)
		a[i] = read();
	sort(a+1,a+n+1);
	int l = 1e9,r = a[n]-a[1];
	for(int i = 2;i <= n;i++)
		l = min(l,a[i]-a[i-1]);
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}
	printf("%d\n",r);
	return 0;
}