#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int p[1010];
int Max;
int f[1010];
bool func(int x)
{
	int ans=0;
	for(int i=1;i<=m;i++)
		ans+=p[i]/x;
	return ans>=n;
}
int main()
{
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i];
		Max+=p[i];
	}
	int l=1,r=Max/n;
	int mid;
	int ans1=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(func(mid))
		{
			ans1=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	if(ans1==0)
	{
		cout<<"0 0\n";
		return 0;
	}
	memset(f,127,sizeof f);
	f[0]=0;
	for(int i=1;i<=m;i++)
		for(int j=n;j>0;j--)
			f[j]=min(f[j],f[max(0,j-p[i]/ans1)]+p[i]);
	cout<<ans1<<" "<<f[n]<<endl;
	return 0;
}
