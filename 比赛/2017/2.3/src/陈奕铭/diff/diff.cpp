#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[100010];

bool cmp(const int &a,const int &b){
	return a<b;
}

int main(){
	freopen("diff.in","r",stdin);
	freopen("diff.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1,cmp);
	swap(a[1],a[n]);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
