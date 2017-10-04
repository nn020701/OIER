#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=500+19;
struct Edge {int y,nxt;} E[N*N];
int SPY[N],Q[N],Last[N],is_C[N],vis[N],f,w,Time,cnt,n,b;

void Add(int x,int y) {E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;}
void BFS(int S)
{
	f=w=0;Time++;
	For(i,1,n+1) if (is_C[i]&&i!=S) Q[++f]=i;
	while (f>w)
	{
		int x=Q[++w];
		for (int i=Last[x];~i;i=E[i].nxt)
			if (vis[E[i].y]!=Time) vis[E[i].y]=Time,Q[++f]=E[i].y;
	}
	For(i,1,n+1) if (!is_C[i]&&vis[i]!=Time) SPY[i]=1;
}

int main()
{
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	memset(Last,-1,sizeof(Last));
	n=IN();
	For(i,1,n+1)
	{
		int k=IN();is_C[i]=!k;
		while (k--) Add(IN(),i);
	}
	For(i,1,n+1) if (is_C[i]) BFS(i);
	For(i,1,n+1) if (SPY[i]) printf("%d\n",i),b=1;
	if (!b) puts("BRAK");
}
