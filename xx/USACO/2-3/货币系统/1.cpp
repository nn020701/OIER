#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int v,n,p;
    long long dp[10001];
    cin>>v>>n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=v;i++)
    {
        cin>>p;
        for(int j=p;j<=n;j++)
            dp[j]+=dp[j-p];
    }
    cout<<dp[n]<<endl;
    return 0;
}
