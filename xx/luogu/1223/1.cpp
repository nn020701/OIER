#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
struct node{
	int w,num;
	friend bool operator <(node a,node b){
		return a.w < b.w || (a.w == b.w && a.num < b.num);
	}
}a[N];
ll ans;

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		a[i].w = read(),a[i].num = i;
	sort(a+1,a+n+1);
	for(int i = 1;i < n;i++)
		ans += a[i].w*(n-i);
	for(int i = 1; i < n;i++)
		printf("%d ",a[i].num);
	printf("%d\n",a[n].num);
	printf("%.2lf\n",(double)(1.0*ans/n));
	return 0;
}