#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 5005
#define M 1000005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[N];
bool f[M];

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			f[abs(a[i]-a[j])] = true;
	for(int i = n;;i++)
		if(!f[i]){
			printf("%d\n",i);
			break;
		}
	return 0;
}
