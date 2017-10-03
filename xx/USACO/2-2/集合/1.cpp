#include<cstring>
#include <iostream>
using namespace std;
 
int main()
{
    int n,max;
    unsigned long dp[10000];
    cin>>n;
    max=(n*(n+1))/2;
    if (max&1==1) {
        cout<<0<<endl;
        return 0;
    }
    max/=2;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=max;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];
    cout<<dp[max]/2<<endl;
    return 0;
}
