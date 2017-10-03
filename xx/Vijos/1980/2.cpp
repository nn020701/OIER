#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int T,n,ans,king;
int p[15],dp[24][24][24][24],ha[5];//i个4，j个3，k个2，l个1 
int shun[5]={0,5,3,2};
int calc(int one,int two,int three,int four,int king)
{
    if(king==1)
    {
        king--;
        one++;
    }
    if(king==0)return dp[four][three][two][one];
    else return min(dp[four][three][two][one]+1,dp[four][three][two][one+2]);
}
void dfs(int now)//打了now次 
{
    //直觉告诉我这局春天了
    if(now>ans)return;
    memset(ha,0,sizeof(ha));
    for(int i=2;i<=14;i++)
    ha[p[i]]++;
    ans=min(ans,now+calc(ha[1],ha[2],ha[3],ha[4],king));
   for(int k=1;k<=3;k++)//顺子 
    {
        for(int i=3;i<=14;i++)
        {
            int j;
            for(j=i;j<=14&&p[j]>=k;j++)
            {
                p[j]-=k;
                if(j-i+1>=shun[k])dfs(now+1);
            }
            for(j--;j>=i;j--)
            p[j]+=k;
        }
    }
}
int main()
{
    scanf("%d%d",&T,&n);
    memset(dp,1,sizeof(dp));
    dp[0][0][0][0]=0;
    for(int i=0;i<=n;i++)//四 
    for(int j=0;j<=n;j++)//三 
    for(int k=0;k<=n;k++)//二 
    for(int l=0;l<=n;l++)//一 
    if(i*4+j*3+k*2+l<=n)
    {
        dp[i][j][k][l]=i+k+j+l;//手牌最炸
        if(i)
        {
            if(i>=1)//四拆成三和一个单 
            dp[i][j][k][l]=min(dp[i-1][j+1][k][l+1],dp[i][j][k][l]);
            if(k>=2)//四带两对 
            dp[i][j][k][l]=min(dp[i-1][j][k-2][l]+1,dp[i][j][k][l]);
            if(i>=2)//两炸拆成四带两对 
            dp[i][j][k][l]=min(dp[i-2][j][k][l]+1,dp[i][j][k][l]);
            if(k>=1)//四带两张成对的单 
               dp[i][j][k][l]=min(dp[i-1][j][k-1][l]+1,dp[i][j][k][l]);
            if(l>=2)//四带二
            dp[i][j][k][l]=min(dp[i-1][j][k][l-2]+1,dp[i][j][k][l]);
/*直接炸*/ dp[i][j][k][l]=min(dp[i-1][j][k][l]+1,dp[i][j][k][l]);

        }
        if(j)
        {
            if(j>=1)//三拆成一对一单 
            dp[i][j][k][l]=min(dp[i][j-1][k+1][l+1],dp[i][j][k][l]); 
            if(k>=1)//三带一对
            dp[i][j][k][l]=min(dp[i][j-1][k-1][l]+1,dp[i][j][k][l]); 
            if(l>=1)//三带一 
            dp[i][j][k][l]=min(dp[i][j-1][k][l-1]+1,dp[i][j][k][l]);
/*蜜汁三个*/ dp[i][j][k][l]=min(dp[i][j-1][k][l]+1,dp[i][j][k][l]);

        }
        if(k)//对
        dp[i][j][k][l]=min(dp[i][j][k-1][l]+1,dp[i][j][k][l]);
        if(l)//单
        dp[i][j][k][l]=min(dp[i][j][k][l-1]+1,dp[i][j][k][l]); 
    }
    for(int tt=1;tt<=T;tt++)
    {
        memset(p,0,sizeof(p));
        king=0;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==0)king++;
            else if(x==1)p[14]++;
            else p[x]++;
        }
        memset(ha,0,sizeof ha);    
        for(int i = 2;i <= 14;i++)
            ha[p[i]]++;
        printf("%d\n",dp[ha[4]][ha[3]][ha[2]][ha[1]]);
    ans=n;
    dfs(0);
    printf("%d\n",ans);
    }
     return 0;
}