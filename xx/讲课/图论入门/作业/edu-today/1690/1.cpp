#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const LL INF=1e18;
const int VN=105;
int n;
int m;
LL d[VN][VN];
LL X[VN];
LL L1,L2,L3,L4;
LL C1,C2,C3,C4;
LL Abs(LL x)
{
	if(x>0)
		return x;
	return -x;
}
void init()
{
    for(int i=1;i<=n;i++)
	{
        d[i][i]=0;
        for(int j=i+1;j<=n;j++)
            d[i][j]=d[j][i]=INF;
    }
}

LL getCost(LL dist)
{
    if(0<dist && dist<=L1) 
		return C1;
    if(L1<dist && dist<=L2) 
		return C2;
    if(L2<dist && dist<=L3) 
		return C3;
    if(L3<dist && dist<=L4) 
		return C4;
    return INF;
}

void Floyd()
{
    for(int k=1;k<=n;k++)
    	for(int i=1;i<=n;i++)
			if(d[i][k]!=INF)
    			for(int j=1;j<=n;j++)
					if(d[k][j]!=INF)
        				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
	{
        cin>>L1>>L2>>L3>>L4;
        cin>>C1>>C2>>C3>>C4;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            cin>>X[i];
        init();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                d[i][j]=d[j][i]=getCost(Abs(X[i]-X[j]));
        Floyd();
        int u,v;
        printf("Case %d:\n",cas++);
        for(int i=0;i<m;i++)
		{
            scanf("%d%d",&u,&v);
            if(d[u][v]!=INF)
			{
                printf("The minimum cost between station %d and station %d is ",u,v);
                cout<<d[u][v]<<".\n";
            }
            else 
                printf("Station %d and station %d are not attainable.\n",u,v);
        }
    }
    return 0;
}
