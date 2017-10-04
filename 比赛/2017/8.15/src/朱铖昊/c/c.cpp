#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int a[N],f[N],n,m,x,y,z,ans;
set<int>s[N];
inline void read(int &x)
{
	x=0;
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void pushdown(int k)
{
	if (a[k*2]!=0)
		s[k*2].insert(a[k*2]);
	a[k*2]=a[k];
	if (a[k*2+1]!=0)
		s[k*2+1].insert(a[k*2+1]);
	a[k*2+1]=a[k];
	a[k]=0;
}
inline void add(int L,int R,int l,int r,int k,int x)
{
	if (L==l&&R==r)
	{
		if (a[k]!=0)
			s[k].insert(a[k]);
		a[k]=x;
		return;
	}
	if (a[k]!=0)
		pushdown(k);
	int mid=(l+r)/2;
	if (R<=mid)
		add(L,R,l,mid,k*2,x);
	else
	{
		if (L>mid)
			add(L,R,mid+1,r,k*2+1,x);
		else
		{
			add(L,mid,l,mid,k*2,x);
			add(mid+1,R,mid+1,r,k*2+1,x);
		}
	}
}
inline void xc(int l,int r,int k)
{
	if (l==r)
	{
		f[l]=a[k];
		return;
	}
	if (a[k]!=0)
		pushdown(k);
	int mid=(l+r)/2;
	xc(l,mid,k*2);
	xc(mid+1,r,k*2+1);
}
inline bool ask(int x,int l,int r,int k,int y)
{
	if (s[k].count(y))
		return true;
	else
	{
		if (l==r)
			return false;
		else
		{
			int mid=(l+r)/2;
			if (x<=mid)
				return ask(x,l,mid,k*2,y);
			else
				return ask(x,mid+1,r,k*2+1,y);
		}
	}
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		read(z);
		add(max(1,x-z),min(n,x+z),1,n,1,y);
	}
	xc(1,n,1);
	for (int i=1;i<=n;++i)
		if (f[i]==0||ask(i,1,n,1,f[i]))
			++ans;
	printf("%d",ans);
	return 0;
}

	