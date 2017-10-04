#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int L=200005,N=1000005;
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
int pos[N],n,m,l;
ll a[N],f[N];
struct data
{
	int id;
	bool operator >(const data &k)
	{
		return f[id]-a[id+1]>f[k.id]-a[k.id+1];
	}
}h[N];
inline void up(int x)
{
	if (h[x]>h[x/2])
	{
		pos[h[x].id]=x/2;
		pos[h[x/2].id]=x;
		swap(h[x],h[x/2]);
		if (x/2!=1)
			up(x/2);
	}
}
inline void down(int x)
{
	int j=x*2;
	if (x*2>l)
		return;
	if (j+1<=l&&h[j+1]>h[j])
		j=j+1;
	if (h[j]>h[x])
	{
		pos[h[x].id]=j;
		pos[h[j].id]=x;
		swap(h[j],h[x]);
		down(j);
	}
}
inline void del(int x)
{
	int p=pos[x];
	pos[x]=0;
	h[p]=h[l];
	pos[h[p].id]=p;
	--l;
	down(p);
}
inline void xj(int x)
{
	h[++l].id=x;
	pos[x]=l;
	up(l);
}
int main()
{
	freopen("truancy.in","r",stdin);
	freopen("truancy.out","w",stdout);
	n=read();
	m=read();
	for (int i=1;i<=n;++i)
		a[i]=a[i-1]+read();
	for (int i=1;i<=m;++i)
	{
		f[i]=a[i];
		xj(i);
	}
	for (int i=m+1;i<=n;++i)
	{
		if (i-m-2>=1)
			del(i-m-2);
		f[i]=max(f[h[1].id]+a[i]-a[h[1].id+1],f[i-1]);
		xj(i);
	}
	printf("%lld",f[n]);
	return 0;
}
