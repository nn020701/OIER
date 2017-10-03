#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x7fffff
int map[40][40];
int main()
{
	int n;
	int ans;
	int l;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break; 
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
				map[j][i]=map[i][j];
			}
		ans=map[1][2];
		for(int i=3;i<=n;i++)
		{
			l=INF;
			for(int j=2;j<i;j++)
				l=min(l,(map[1][i]+map[i][j]-map[1][j])>>1);
			ans+=l;
		}
		printf("%d\n",ans);
	}
	return 0;
}
