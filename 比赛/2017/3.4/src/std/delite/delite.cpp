#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


struct Point
{	
	int x,y;
}	A[505];
int	tmp[505];
int N,M,Nx,Ny,num[305][305],Q[1000005][2],inQ[305][305],X[1000005],Y[1000005];
long long ans=0,d[305][305],dist_x[505],dist_y[505];

inline int read()
{
	char ch=getchar();int x=0;bool flag=0;
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')
	{
		flag=1;
		ch=getchar();
	}
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	if(flag)return-x;return x;
}

long long spfa(int S,int T)
{
	memset(d,0x1f,sizeof(d));
	memset(inQ,0,sizeof(inQ));
	d[A[S].x][A[S].y]=0;inQ[A[S].x][A[S].y]=1;Q[1][0]=A[S].x;Q[1][1]=A[S].y;
	for(int l=1,r=1;l<=r;++l)
	{
		int x=Q[l][0],y=Q[l][1];inQ[x][y]=0;
		if((x-1)&&(num[x-1][y]==T||!num[x-1][y]))
		{
			if(d[x][y]+dist_x[x]<d[x-1][y])
			{
				d[x-1][y]=d[x][y]+dist_x[x];
				if(!inQ[x-1][y])
				{
					inQ[x-1][y]=1;
					Q[++r][0]=x-1;
					Q[r][1]=y;
				}
			}
		}
		if((x<Nx)&&(num[x+1][y]==T||!num[x+1][y]))
		{
			if(d[x][y]+dist_x[x+1]<d[x+1][y])
			{
				d[x+1][y]=d[x][y]+dist_x[x+1];
				if(!inQ[x+1][y])
				{
					inQ[x+1][y]=1;
					Q[++r][0]=x+1;
					Q[r][1]=y;
				}
			}
		}
		if((y-1)&&(num[x][y-1]==T||!num[x][y-1]))
		{
			if(d[x][y]+dist_y[y]<d[x][y-1])
			{
				d[x][y-1]=d[x][y]+dist_y[y];
				if(!inQ[x][y-1])
				{
					inQ[x][y-1]=1;
					Q[++r][0]=x;
					Q[r][1]=y-1;
				}
			}
		}
		if((y<Ny)&&(num[x][y+1]==T||!num[x][y+1]))
		{
			if(d[x][y]+dist_y[y+1]<d[x][y+1])
			{
				d[x][y+1]=d[x][y]+dist_y[y+1];
				if(!inQ[x][y+1])
				{
					inQ[x][y+1]=1;
					Q[++r][0]=x;
					Q[r][1]=y+1;
				}
			}
		}
	}
	if(d[A[T].x][A[T].y]>100000000000ll)
	{
		printf("-1\n");
		exit(0);
	}
	return d[A[T].x][A[T].y];
}

int main()
{
	freopen("delite.in","r",stdin);
	freopen("delite.out","w",stdout);
	
	N=read();
	for(int i=1;i<=N;++i)
	{
		A[i].x=read();
		A[i].y=read();
	}
	
	M=0;
	for(int i=1;i<=N;++i)
	{
		tmp[++M]=A[i].x;
		tmp[++M]=A[i].x-1;
		tmp[++M]=A[i].x+1;
	}
	sort(tmp+1,tmp+M+1);
	X[tmp[1]]=1;Nx=1;
	for(int i=1;i<=M;++i)
		if(tmp[i]!=tmp[i-1])
		{
			X[tmp[i]]=++Nx;
			dist_x[Nx]=tmp[i]-tmp[i-1];
		}
		
	M=0;
	for(int i=1;i<=N;++i)
	{
		tmp[++M]=A[i].y;
		tmp[++M]=A[i].y-1;
		tmp[++M]=A[i].y+1;
	}
	sort(tmp+1,tmp+M+1);
	Y[tmp[1]]=1;Ny=1;
	for(int i=1;i<=M;++i)
		if(tmp[i]!=tmp[i-1])
		{
			Y[tmp[i]]=++Ny;
			dist_y[Ny]=tmp[i]-tmp[i-1];
		}
	
	for(int i=1;i<=N;++i)
	{
		A[i].x=X[A[i].x];
		A[i].y=Y[A[i].y];
		num[A[i].x][A[i].y]=i;
	}
	
	ans=0;
	for(int i=1;i<N;++i)ans+=spfa(i,i+1);
	ans+=spfa(N,1);
	
	cout<<ans<<endl;
	
	//for(;;);
	return 0;
}
