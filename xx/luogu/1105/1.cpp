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

struct node{
	int l,r,h;
	int num;
}a[N];
int n;
int l[N],r[N];

bool cmp(node a,node b){
	return a.h > b.h || ( a.h == b.h && a.l < b.l);
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a[i].h = read();
		a[i].l = read(); 
		a[i].r = read();
		a[i].num = i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++)
			if(a[i].h > a[j].h && a[i].l > a[j].l && a[i].l < a[j].r){
				l[a[i].num] = a[j].num;
				break;
			}
		for(int j = i+1;j <= n;j++)
			if(a[i].h > a[j].h && a[i].r > a[j].l && a[i].r < a[j].r){
				r[a[i].num] = a[j].num;
				break;
			}
	}
	for(int i = 1;i <= n;i++)
		printf("%d %d\n",l[i],r[i]);
	return 0;
}
