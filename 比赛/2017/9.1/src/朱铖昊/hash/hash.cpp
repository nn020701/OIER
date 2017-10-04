#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
inline char gc()
{
	if (S==T)
	{
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) 
			return EOF;
	}
	return *S++;
}
inline void read(ll &x)
{
	x=0;
	char c=gc();
	for (;c<'0'||c>'9';c=gc());
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
}
const int N=500005;
int f[N],g[N],a[N],n,k;
ll ans[20000],p,x,v[1005];
ll gcd(ll x,ll y)
{
	return x%y?gcd(y,x%y):y;
}
int main()
{
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	scanf("%d",&n);
	a[1]=1;
	for (int i=2;i<=500000;++i)
	{
		if (!a[i])
			f[++f[0]]=i;
		for (int j=1;j<=f[0]&&i*f[j]<=500000;++j)
		{
			a[i*f[j]]=1;
			if (i%f[j]==0)
				break;
		}
	}
	for (int i=1;i<=n;++i)
	{
		read(x);
		for (int j=1;j<=f[0];++j)
		{
			k=0;
			while (x%f[j]==0)
			{
				x/=f[j];
				++k;
			}
			g[j]=max(g[j],k);
		}
		if (x!=1)
			v[++v[0]]=x;
	}
	for (int i=1;i<=v[0];++i)
		for (int j=i+1;j<=v[0];++j)
		{
			p=gcd(v[i],v[j]);
			if (p==1)
				continue;
			if (v[i]==p*p)
				v[j]/=p;
			else
			{
				if (v[j]==p*p)
					v[i]/=p;
				else
				{
					if (p==v[i])
						v[i]/=p;
					else
						v[j]/=p;
				}
			}
		}
	ans[0]=1;
	ans[1]=1;
	for (int i=1;i<=f[0];++i)
	{
		p=1;
		for (int j=1;j<=g[i];++j)
			p*=f[i];
		if (p==1)
			continue;
		else
			f[i]=p;
		for (int k=1;k<=ans[0];++k)
			ans[k]*=f[i];
		for (int k=1;k<=ans[0];++k)
		{
			ans[k+1]+=ans[k]/26;
			ans[k]%=26;
		}
		while (ans[ans[0]+1])
		{
			++ans[0];
			ans[ans[0]+1]+=ans[ans[0]]/26;
			ans[ans[0]]%=26;
		}
	}
	if (v[0]!=0)
		sort(v+1,v+v[0]);
	for (int i=1;i<=v[0];++i)
	{
		if (v[i]==1)
			continue;
		for (int k=1;k<=ans[0];++k)
			ans[k]*=v[i];
		for (int k=1;k<=ans[0];++k)
		{
			ans[k+1]+=ans[k]/26;
			ans[k]%=26;
		}
		while (ans[ans[0]+1])
		{
			++ans[0];
			ans[ans[0]+1]+=ans[ans[0]]/26;
			ans[ans[0]]%=26;
		}
	}
	for (int i=ans[0];i>=1;--i)
		putchar('a');
	putchar('\n');
	for (int i=ans[0];i>=1;--i)
		putchar('a'+ans[i]);
	return 0;
}