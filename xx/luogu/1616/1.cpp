#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 10005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int T,n;
int t[N],w[N];
int f[N*10];

int main(){
	T = read(); n = read();
	for(int i = 1;i <= n;i++)
		t[i] = read(),w[i] = read();
	for(int j = 1;j <= n;j++)
		for(int i = t[j];i <= T;i++)
			f[i] = max(f[i],f[i-t[j]]+w[j]);
	printf("%d\n",f[T]);
	return 0;
}