#include<cstdio>
using namespace std;
const int N=100100,M=10001000;
int i,j,k,n,m,E_sz,x,y,v;
int head[N],A[N];
struct edge {int next,to,val;} E[M];
void E_add(int x,int y,int v)
{
	E[++E_sz].to=y;
	E[E_sz].val=v;
	E[E_sz].next=head[x];
	head[x]=E_sz;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		E_add(x,y,v);
		E_add(y,x,v);
	}
	for (i=1;i<=n;i++)
	{
		int num=0;
		for (k=head[i];k;k=E[k].next) A[++num]=E[k].to;
		printf("%d %d\n",i,num);
		for (j=1;j<=num;j++) printf("%d ",A[j]);
		puts("");
	}
}
