#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[40010];
int b[40010];
int c[40010];
int n;
int ans;
void Mearge(int l,int mid,int r)
{
	int i=l,j=mid+1;
	int k=0;
	while(i<=mid&&j<=r) 
        if(b[i]<=b[j]) 
            c[k++]=b[i++];
		else
		{
			ans+=mid-i+1;
            c[k++]=b[j++];
        }
    while(i<=mid)
    	c[k++]=b[i++];
    while(j<=r)
        c[k++]=b[j++];
    for(k=0,i=l;i<=r;i++,k++) 
		b[i]=c[k];
}
void Sort(int l,int r)
{
	int mid=(l+r)/2;
	if(l<r)
	{
		Sort(l,mid);
		Sort(mid+1,r);
		Mearge(l,mid,r);
	}
}
int main()
{
	cin>>n;
	int m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	Sort(1,n);
	cin>>m;
	int x,y;
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)
	{
		ans=0;
		cin>>x>>y;
		swap(a[x],a[y]);
		for(int j=1;j<=n;j++)
			b[j]=a[j];
		Sort(1,n);
		cout<<ans<<endl;
	}
	return 0;
}
