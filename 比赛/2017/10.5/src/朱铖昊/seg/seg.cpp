#include<bits/stdc++.h>
using namespace std;
#define int unsigned
const unsigned N=5000005;
set<unsigned>s[32];
unsigned a[N],n,m,x,y,z;
inline void read(unsigned &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void write(int x)
{
	int a[20];
	a[0]=0;
	if (x==0)
		putchar('0');
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar(a[a[0]--]+'0');
	putchar('\n');
}
inline int work(int x,int y,int z)
{
	int p;
	if (!(a[z]&(1<<x)))
		return 1;
	if (a[y]&(1<<x))
		p=1;
	else
		p=0;
	set<int>::iterator it=s[x].upper_bound(z);
	if (it==s[x].begin()||*--it<=y)
		return ((z-y)&1)^p;
	else
		return !((z-*it)&1);
}
signed main()
{
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
	{
		read(a[i]);
		for (int j=0;j<32;++j)
			if (!(a[i]&(1<<j)))
				s[j].insert(i);
	}
	for (int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		read(z);
		if (x==1)
		{
			for (int j=0;j<32;++j)
			{
				if ((a[y]&(1<<j))&&(!(z&(1<<j))))
					s[j].insert(y);
				if ((!(a[y]&(1<<j)))&&(z&(1<<j)))
					s[j].erase(y);
			}
			a[y]=z;
		}
		else
		{
			unsigned ans=0;
			for (int j=0;j<32;++j)
			{
				//cout<<work(j,y,z);
				ans+=work(j,y,z)<<j;
			}
			//putchar(' ');
			write(ans);
		}
	}
	return 0;
}