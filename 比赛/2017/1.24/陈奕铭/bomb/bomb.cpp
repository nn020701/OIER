#include<iostream>
#include<cstdio>
#include<cstring>
int max(int a,int b)
{
	return a>b?a:b;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[5005][5005],ans,n,m,t,r,x,y,w;
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout); 
	t=read();
	r=read();
	while(t--)
	{
		x=read();
		y=read();
		w=read();
		x++;
		y++;
		a[x][y]+=w;
		n=max(n,x);
		m=max(m,y);
	}
	t=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			ans=max(ans,a[i][j]+a[max(t,i-r)][max(t,j-r)]-a[max(t,i-r)][j]-a[i][max(t,j-r)]);
		}
	printf("%d\n",ans);
	return 0;
}
