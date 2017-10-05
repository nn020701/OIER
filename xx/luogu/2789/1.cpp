#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int n,ans,m;
bool dp[30][400];

int main()
{
	freopen("1.out","w",stdout);
	for(n = 1;n <= 25;n++){
		ans = 0;
	    memset(dp,0,sizeof dp);
	    m=(n-1)*n/2;
	    for(int i=1;i<=n;i++)dp[i][0]=true;
	    for(int i=1;i<=n;i++)
	        for(int j=0;j<=m;j++)
	            for(int k=1;k<=n-i;k++)
	                dp[i+k][j+k*i]|=dp[i][j];
	    for(int i=0;i<=m;i++)
	        if(dp[n][i])ans++;
	    printf("%d,",ans);
	}
	return 0;
}