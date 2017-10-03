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

int n;
int l,r;
int a[51];
int x,y,sum;

int main(){
	n = read();
	for(int i = 1;i <= n;i++) a[i] = read(),sum += a[i];
	l = read(); r = read();
	if(sum/n < l){
		printf("-1");
		return 0;
	}
	if(sum/n > r || (sum%n != 0 && sum/n == r)){
		printf("-1");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		if(a[i] > r) y += a[i]-r;
		if(a[i] < l) x += l-a[i];
	}
	printf("%d\n",max(x,y));
	return 0;
}
