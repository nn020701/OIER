#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
#define INF 1e9
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int nxt[100005][35], mn[100005][35];
LL sum[100005][35];
int main()
{
	int n;
	LL k;
	cin>>n>>k;
	for(int i=0;i<n;i++) 
		scanf("%d",&nxt[i][0]);
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&mn[i][0]);
		sum[i][0]=mn[i][0];
	}
	for(int i=1;i<35;i++)
		for(int j=0;j<n;j++)
		{
			nxt[j][i]=nxt[nxt[j][i-1]][i-1];
			mn[j][i]=min(mn[j][i-1],mn[nxt[j][i-1]][i-1]);
			sum[j][i]=sum[j][i-1]+sum[nxt[j][i-1]][i-1];
		}
	for(int j=0;j<n;j++)
	{
		LL ansSum=0,tmpk=k;
		int ansMin=INF,pos=j;
		for(int i=34;i>=0;i--)
		{
			LL tmp=1LL<<i;
			if(tmpk>=tmp)
			{
				tmpk-=tmp;
				ansSum+=sum[pos][i];
				ansMin=min(ansMin, mn[pos][i]);
				pos=nxt[pos][i];
			}
		}
		printf("%I64d %d\n",ansSum,ansMin);
	}
	return 0;
}
