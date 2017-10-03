#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 2002    
#define N 1002    
#define INF 999999
int n,m,s;
int map[M][M];   
int dis[N];        
int visit[N];      
void dijkstra(int s)
{
    int i,j,k = 0;
    int min;
    memset(visit,0,sizeof(visit)); 
    for(i = 1; i <=n; i++)
    {
        dis[i] = map[s][i];
    }
    visit[s] = 1; 
    dis[s] = 0;
    for(i = 1; i < n; i++)
    {
        min = INF;
        for (j = 1; j <= n; j++)
        {
            if ( !visit[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if (min == INF)
        {
            break;
        }
        visit[k] = 1; 
        for(j = 1; j <= n; j++)   
        {
            if ( !visit[j] && dis[j] > dis[k] + map[k][j])
            {
                dis[j] = dis[k] + map[k][j];
            }
        }
    }
    return ;
}
int main()
{
    int i,j;
    int p,q,t,w;
    int  minx ,ww;
    while ( scanf("%d %d %d",&n,&m,&s) != EOF)
    {
        memset(dis,0,sizeof(dis));
        for (i = 1; i<= n; i++)
            for(j = 1; j <= n; j ++)
            {
                map[i][j] = INF;
            }
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&p,&q,&t);
            if(t < map[q][p])    
                map[q][p] = t;  
        }
        dijkstra(s);
        scanf("%d",&w);
        minx = INF;

        for (i = 1; i <=w; i++ ) 
        {
            scanf("%d",&ww);
            if (minx > dis[ww])
            {
                minx = dis[ww];
            }
        }
        if ( minx != INF)
        {
            printf("%d\n",minx);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}

