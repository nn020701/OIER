#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20010];
int b[20010];
int c[20010];
int n;
int ans;
void Swap(int x,int y)
{
	int num1=0,num2=0;
	for(int i=x+1;i<=y-1;i++)
		if(a[x]<a[i])
			num1++;
		else if(a[x]>a[i])
			num2++;
	ans+=num1-num2;
	num1=0;
	num2=0;
	for(int i=x+1;i<=y-1;i++)
		if(a[y]>a[i])
			num1++;
		else if(a[y]<a[i])
			num2++;
	ans+=num1-num2;
	if(a[y]>a[x])
		ans++;
	else if(a[y]<a[x])
		ans--;
	swap(a[x],a[y]);
	cout<<ans<<endl;
}
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
		cin>>x>>y;
		if(x>y)
			swap(x,y);
		Swap(x,y);
	}
	return 0;
}
