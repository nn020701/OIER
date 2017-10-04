#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	x=0;
	int y=1;
	char c=getchar();
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*y;
}
const int N=100005;
int fa[N],n,k,sum,cnt;
struct point
{
	int x,id;
	bool operator<(const point &a)const
	{
		return x<a.x;
	}
}a[N],b[N],c[N];
struct edge
{
	int x,y,z;
	bool operator<(const edge &a)const
	{
		return z<a.z;
	}
}e[N*3];
inline void add(int x,int y,int z)
{
	++cnt;
	e[cnt].x=x;
	e[cnt].y=y;
	e[cnt].z=z;
}
int gf(int x)
{
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
inline void merge(int x,int y)
{
	x=gf(x);
	y=gf(y);
	fa[x]=y;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n);
	for (int i=1;i<=n;++i)
	{
		read(a[i].x);
		read(b[i].x);
		read(c[i].x);
		a[i].id=b[i].id=c[i].id=i;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	for (int i=1;i<n;++i)
	{
		add(a[i].id,a[i+1].id,a[i+1].x-a[i].x);
		add(b[i].id,b[i+1].id,b[i+1].x-b[i].x);
		add(c[i].id,c[i+1].id,c[i+1].x-c[i].x);
	}
	sort(e+1,e+1+cnt);
	for (int i=1;i<=n;++i)
		fa[i]=i;
	k=n-1;
	for (int i=1;i<=cnt&&k;++i)
		if (gf(e[i].x)!=gf(e[i].y))
		{
			sum+=e[i].z;
			merge(e[i].x,e[i].y);
			--k;
		}
	printf("%d",sum);
}