#include<bits/stdc++.h>
#define N 200005
#define a(x,y) a[(x-1)*(m+10)+(y)]
#define b(x,y) b[(x-1)*(m+10)+(y)]
#define c(x,y) c[(x-1)*(m+10)+(y)]
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=x*10-48+ch;
	return x*f;
}
int a[N],b[N],c[N],d[N];
int bin[1050],vis[1050];
int n,m,ans;
int main(){
	srand(time(NULL));
	freopen("b.in","w",stdout);
	n=rand()%500+10; m=5000/n;
	printf("%d %d\n",n,m);
	for (int i=1;i<=n*m;i++)
		printf("%d ",rand()%10);
}
