#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXN 1002 
double path[102][102];
int flag[102];
double closedge[102];
double cnt;
typedef struct{
    int x,y;
}input;
input temp[102];
double calculate(int x1, int y1, int x2, int y2)
{
    double t=(double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return sqrt(t);
}
double CreatMST(int n)
{
    int i,j,x;
    double k;
    flag[0]=1;
    for(i=1;i<n;++i)
    closedge[i]=path[0][i];
    for(i=1;i<n;++i)
    {
        k=MAXN-2,x=0;
        for(j=0;j<n;j++)
        if(!flag[j]&&closedge[j]<=k)
            x=j,k=closedge[j];
        flag[x]=1;
        cnt+=k;
        for(j=0;j<n;j++)
        	if(!flag[j]&&closedge[j]>path[x][j])
        		closedge[j]=path[x][j];
    }
    return cnt;
}
int main()
{
    int i,j,k,t,x,y,n,m,T,fflag;
    double h;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        cnt=0;
        memset(temp,0,sizeof(temp));
        memset(flag,0,sizeof(flag));
        memset(closedge,0,sizeof(closedge));
        memset(path,0,sizeof(path));
        for(i=0;i<n;i++)
        scanf("%d%d",&temp[i].x,&temp[i].y);
    
        for(i=0;i<n;i++)
        	for(j=0;j<n;j++)
	        {
	            h=calculate(temp[i].x,temp[i].y,temp[j].x,temp[j].y);
	            if(h<10||h>1000) 
					path[i][j]=MAXN; 
	            else 
					path[i][j]=h;
	        }
        if(n==1||n==0)
		{
			printf("oh!\n");
			continue;
		} 
        h=CreatMST(n)*100;
        fflag=0;
        for(i=0;i<n;i++) 
			if(flag[i] == 0)
			{
				fflag=1;
				break;
			}
        if(fflag)
			printf("oh!\n");
        else
			printf("%.1lf\n", h);
    }
    return 0;
}
