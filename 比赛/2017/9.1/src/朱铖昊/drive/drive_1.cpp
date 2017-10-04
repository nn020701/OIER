#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int L=200005,N=500005,mod=1e9+7;
int a[N],b[N],cnt,n,si[4*N],tag[4*N];
ll q[N],h[N],ans,s[4*N];
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
inline void pushup(int x)
{
	si[x]=si[x*2]+si[x*2+1];
	s[x]=s[x*2]+s[x*2+1];
}
inline void pushdown(int x)
{
	tag[x*2]+=tag[x];
	s[x*2]+=(ll)si[x*2]*tag[x];
	tag[x*2+1]+=tag[x];
	s[x*2+1]+=(ll)si[x*2+1]*tag[x];
	tag[x]=0;
}
ll ask(int l,int r,int L,int R,int x)
{
	//cout<<l<<' '<<r<<' '<<L<<' '<<R<<' '<<x<<' '<<endl;
	if (r==0)
		return 0;
	if (l>r)
		swap(l,r);
	if (l==L&&r==R)
		return s[x];
	int mid=(L+R)/2;
	if (r<=mid)
		return ask(l,r,L,mid,x*2);
	if (l>mid)
		return ask(l,r,mid+1,R,x*2+1);
	return ask(l,mid,L,mid,x*2)+ask(mid+1,r,mid+1,R,x*2+1);
}
void add(int l,int r,int L,int R,int x)
{
	if (l>cnt)
		return;
	if (l==L&&r==R)
	{
		++tag[x];
		s[x]+=si[x];
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	if (r<=mid)
		add(l,r,L,mid,x*2);
	else
	{
		if (l>mid)
			add(l,r,mid+1,R,x*2+1);
		else
		{
			add(l,mid,L,mid,x*2);
			add(mid+1,r,mid+1,R,x*2+1);
		}
	}
	pushup(x);
}
void insert(int pos,int l,int r,int x)
{
	if (l==r)
	{
		++si[x];
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if (pos<=mid)
		insert(pos,l,mid,x*2);
	else
		insert(pos,mid+1,r,x*2+1);
	pushup(x);
}
int main()
{
	freopen("drive.in","r",stdin);
	freopen("drive1.out","w",stdout);
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
		q[i]=ask(1,a[i]-1,1,cnt,1)%mod;
		add(a[i]+1,cnt,1,cnt,1);
		insert(a[i],1,cnt,1);
	}
	memset(s,0,sizeof(s));
	memset(si,0,sizeof(si));
	memset(tag,0,sizeof(tag));
	for (int i=n;i>=1;--i)
	{
		h[i]=ask(1,a[i]-1,1,cnt,1)%mod;
		add(a[i]+1,cnt,1,cnt,1);
		insert(a[i],1,cnt,1);
	}
	for (int i=1;i<=n;++i)
		ans=((h[i]*q[i]%mod)+ans)%mod;
	cout<<ans;
}