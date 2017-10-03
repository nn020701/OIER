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

int a,b,x,y,gcd;

int exgcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1; y = 0;
		return a;
	}
	int gcd = exgcd(b,a%b,x,y);
	x = x-a/b*y;
	swap(x,y);
	return gcd;
}

int main(){
	a = read(); b = read();
	gcd = exgcd(a,b,x,y);
	x = -x; a = -a;
	while(x < 0 || y < 0){
		if(x < 0) x += 	b/gcd;
		else y -= a/gcd;
	}
	printf("%d\n",gcd);
	printf("%d %d\n",x,y);
	return 0;
}
