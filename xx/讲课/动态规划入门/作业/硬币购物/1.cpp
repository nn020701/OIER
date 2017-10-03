#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long										
LL c[5];
LL d[5];
LL x;
LL f[100010];
LL ans;
void dfs(LL x,LL k,LL sum)
{
	if(sum<0)
		return;
	if(x==5)
	{
		if(k&1)
			ans-=f[sum];
		else 
			ans+=f[sum];
		return;
	}
    dfs(x+1,k+1,sum-(d[x]+1)*c[x]);
	dfs(x+1,k,sum);
}
int main()
{
	int tot;
	for(int i=1;i<=4;i++)
		cin>>c[i];
	cin>>tot;
	f[0]=1;
	for(int i=1;i<=4;i++)
		for(int j=c[i];j<=100000;j++)
			f[j]+=f[j-c[i]];
	while(tot--)
	{
		for(int i=1;i<=4;i++)
			cin>>d[i];
		cin>>x;
		ans=0;
		dfs(1,0,x);
		cout<<ans<<endl;
	}
	return 0;
}
