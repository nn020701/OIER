#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1000005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int ans;
struct node{
	int l,r;
	friend bool operator <(node a,node b){
		return a.r < b.r || (a.r == b.r && a.l < b.l);
	}
}a[N];
int front;

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a[i].l = read(); a[i].r = read();
	}
	sort(a+1,a+n+1);
	front = 0;
	for(int i = 1;i <= n;i++)
		if(a[i].l >= front){
			front = a[i].r;
			ans++;
		}
	printf("%d\n",ans);
	return 0;
}