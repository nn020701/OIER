#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
LL g[110][110];
LL a[10010],b[10010],c[10010],x[10010],y[10010];
LL sum[10010],an[10010];
bool vi[10010];
LL n,d,xx,yy,ans,i,j,ll,l,k,cfb;
bool p;
void Sort(LL l,LL r)
{
	LL i,j,x,y;
	i=l;
	j=r;
	x=a[(l+r)/2];
	do
	{
		while(a[i]<x)
			i++;
		while(x<a[j])
			j--;
		if(!(i>j))
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			swap(c[i],c[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j)
		Sort(l,j);
	if(i<r)
		Sort(i,r);
}
int main()
{
	freopen("soap.in","r",stdin);
	freopen("soap.out","w",stdout);
	cin>>n>>d;
	d=d*d;
	for(i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			ll++;
			b[ll]=i;
			c[ll]=j;
			xx=abs(x[i]-x[j]);
			yy=abs(y[i]-y[j]);
			a[ll]=xx*xx+yy*yy;
			g[i][j]=a[ll];
			g[j][i]=a[ll];
		}
	Sort(1,ll);
	ans=1;
	an[1]=1;
	for(i=1;i<=ll;i++)
		if(a[i]<=d)
		{
			if(cfb>200000)
				break;
			memset(vi,false,sizeof vi);
			l=2;
			sum[1]=b[i];
			sum[2]=c[i];
			if(ans<l)
			{
				ans=l;
				for(j=1;j<=l;j++)
					an[j]=sum[j];
			}
			vi[b[i]]=true;
			vi[c[i]]=true;
			k=i+1;
			while(k<=ll&&a[k]<=d)
			{
				cfb++;
				xx=b[k];
				yy=c[k];
				k++;
				p=false;
				for(j=1;j<=l;j++)
					if(g[xx][sum[j]]>d||g[yy][sum[j]]>d)
						p=true;
				if(p)
					continue;
				if(!vi[xx])
				{
					l++;
					sum[l]=xx;
					vi[xx]=true;
				}
				if(!vi[yy])
				{
					l++;
					sum[l]=yy;
					vi[yy]=true;
				}
				if(ans<l)
				{
					ans=l;
					for(j=1;j<=l;j++)
							an[j]=sum[j];
				}
			}
		}
	for(i=1;i<=ans;i++)
		a[i]=an[i];
	Sort(1,ans);
	cout<<ans<<endl;
	for(i=1;i<=ans;i++)
		cout<<a[i]<<" ";
	return 0;
}