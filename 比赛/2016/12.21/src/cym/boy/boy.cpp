#include<bits/stdc++.h>
using namespace std;
int q[1000010];
int a[1000010];
int n;
int x,y;
bool p=true;
void Init()
{
	cin>>n;
	q[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]%n;
		if(a[i]==0)
		{
			p=false;
			x=i;
			y=i;
		}
		q[i]=(q[i-1]+a[i])%n;
	}
}
void Print()
{
	printf("%d\n",y-x+1);
	for(int i=x;i<=y;i++)
		printf("%d ",i);
}
int main()
{
	freopen("boy.in","r",stdin);
	freopen("boy.out","w",stdout);
	Init();
	bool flag=0;
	if(p)
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(q[j]-q[i]==0)
				{
					flag=1;
					x=i+1;
					y=j;
					break;
				}
			}
			if(flag==1)
				break;
		}
	Print();
	return 0;
}
