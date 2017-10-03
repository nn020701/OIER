#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 1000000000
int n,m,cnt;
int a[100005],f[100005],best[100005];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void solve(int x)
{
	int last=0;
	for(int i=1;i<=n;i++)
		if(f[i]>=x&&a[i]>last)
		{
			cout<<a[i];
			if(x!=1)
				cout<<" ";
			last=a[i];
			x--;
			if(!x)
				break;
		}
		cout<<endl; 
}
int find(int x)
{
	int l=1,r=cnt,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(best[mid]>x)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return ans;
}
void pre()
{
	for(int i=n;i;i--)
	{
		int t=find(a[i]);
		f[i]=t+1;
		cnt=max(cnt,t+1);
		if(best[t+1]<a[i])
			best[t+1]=a[i];
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	pre();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read();
		if(x<=cnt)
			solve(x);
		else
			cout<<"Impossible\n";
	}
	return 0;
}
