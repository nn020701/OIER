#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int L=200005,N=500005,mod=1e9+7;
int a[N],b[N],cnt,n;
ll g[N],q[N],h[N],ans;
char LZH[L],*S=LZH,*T=LZH;
inline char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++;
}
inline int read(){
	int x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
inline int lb(int x)
{
	return x&(-x);
}
inline ll ask(int x)
{
	/*ll y=0;
	for (int i=x;i;i-=lb(i))
		y+=g[i];
	return y;*/
	ll y=0;
	for (int i=1;i<=x;++i)
		y+=g[i];
	return y%mod;
}
inline void add(int x)
{
	/*for (int i=x;i<=cnt;i+=lb(i))
		++g[i];*/
	++g[x];
}
int main()
{
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i)
		a[i]=read();
	for (int i=1;i<=n;++i)
		b[i]=i;
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;++i)
		if (a[b[i]]!=a[b[i+1]])
			a[b[i]]=++cnt;
		else
			a[b[i]]=cnt+1;
	for (int i=1;i<=n;++i)
	{
		q[i]=ask(a[i]-1);
		for (int j=1;j<i;++j)
			if (a[j]>a[i])
				add(a[j]);
	}
	memset(g,0,sizeof(g));
	for (int i=n;i>=1;--i)
	{
		h[i]=ask(a[i]-1);
		for (int j=i+1;j<=n;++j)
			if (a[j]>a[i])
				add(a[j]);
	}
	for (int i=1;i<=n;++i)
		ans=((h[i]*q[i]%mod)+ans)%mod;
	cout<<ans;
}