#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int f[110][110][11];
int n,m,k;
int dp[110][11];
int sum[101];
int s1[101],s2[101];
int main()
{
	cin>>n>>m>>k;
	int a;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			sum[i]=sum[i-1]+a;
		}
		for(int i=1;i<=n;i++)
			for(int z=1;z<=k;z++)
			{
				dp[i][z]=dp[i-1][z];
				for(int j=0;j<i;j++)
					dp[i][z]=max(dp[i][z],dp[j][z-1]+sum[i]-sum[j]);
			}
		cout<<dp[n][k]<<endl;
		return 0;
	}
	int s,ss;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>ss;
		s1[i]=s1[i-1]+s;
		s2[i]=s2[i-1]+ss;
		for(int z=1;z<=k;z++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					f[i][j][z]=max(f[i-1][j][z],f[i][j-1][z]);
					for(int l=0;l<i;l++)
						f[i][j][z]=max(f[i][j][z],f[l][j][z-1]+s1[i]-s1[l]);
					for(int l=0;l<j;l++)
						f[i][j][z]=max(f[i][j][z],f[i][l][z-1]+s2[j]-s2[l]);
					if(i==j)
						for(int l=0;l<i;l++)
							f[i][j][z]=max(f[i][j][z],f[l][l][z-1]+s1[i]+s2[j]-s1[l]-s2[l]);
				}
	}
	cout<<f[n][n][k]<<endl;
	return 0;
}
