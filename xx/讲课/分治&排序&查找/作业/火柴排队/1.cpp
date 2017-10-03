#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 99999997
struct node{
	int h;
	int n;
}match1[100010],match2[100010];
int p[100010],a[100010];
int q[100010];
int n;
int ans;
bool cmp(const node &a,const node &b)
{
	return a.h>b.h;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>match2[i].h;
		match2[i].n=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>match1[i].h;
		match1[i].n=i;
	}
	sort(match1+1,match1+1+n,cmp);
	sort(match2+1,match2+1+n,cmp);
	for(int i=1;i<=n;i++)
		p[match2[i].n]=i;
	for(int i=1;i<=n;i++)
		a[match1[i].n]=i;
	for(int i=1;i<=n;i++)
		q[i]=a[p[i]];
	return 0;
}
