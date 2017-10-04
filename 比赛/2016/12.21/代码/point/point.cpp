#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int x[100010];
int y[100010];
int book[200010];
void Init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
}
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int t;
	bool flag;
	int a;
	cin>>t;
	while(t--)
	{
		Init();
		if(n*(n-1)/2>2*m+2)
		{
			cout<<"YES"<<endl;
			continue;
		}
		flag=false;
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				a=abs(x[i]-x[j])+abs(y[i]-y[j]);
				if(book[a]==1)
				{
					flag=true;
					break;
				}
				book[a]=1;
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
