#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 105
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
bool a[N];

int main(){
	n = read(); printf("%d\n",n);
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= n;j++){
			if(i != j) a[j] ^= 1;
			printf("%d",a[j]);
		}
	return 0;
}
