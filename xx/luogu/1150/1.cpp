#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,a;
int ans;

int main(){
	n = read(); k = read();
	ans = n;
	while(1){
		a = n/k;
		ans += a;
		if(a == 0) break;
		n = n-a*(k-1);
	}
	printf("%d\n",ans);
	return 0;
}
