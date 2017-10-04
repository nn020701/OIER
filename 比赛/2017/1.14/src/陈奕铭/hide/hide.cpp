#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010];
int n,k,p;
bool cmp(const int &a,const int &b)
{
	return a<b;
}
void Init()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
}
int main()
{
	freopen("hide.in","r",stdin);
	freopen("hide.out","w",stdout);
	Init();
	int q=a[1];
	int l=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-q>p)
		{
			l++;
			q=a[i];
		}
	}
	if(l>k)
		cout<<"No\n";
	else
		cout<<"Yes\n";
	return 0;
}
