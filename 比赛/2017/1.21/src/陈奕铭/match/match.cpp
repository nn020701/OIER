#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 0x7ffffff
int a[400];
int f[400][400];
bool book[400][400];
int n;
int cost(int x,int y)
{
	if(a[y]-a[x]==1&&a[y]%2==0)
		return 0;
	if((a[x]%2)||!(a[y]%2))
		return 1;
	return 2;
}
int dp(int l,int r)
{
	if(l>=r)
		return INF;
	if(l+1==r)
		return cost(l,r);
	if(book[l][r])
		return f[l][r];
	int &ans=f[l][r];
	book[l][r]=1;
	ans+=cost(l,r)+dp(l+1,r-1);
	for(int i=l;i<=r;i++)
		ans=min(ans,dp(l,i)+dp(i+1,r));
	return ans;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='{')
			a[i]=1;
		else if(s[i-1]=='}')
			a[i]=2;
		else if(s[i-1]=='(')
			a[i]=3;
		else if(s[i-1]==')')
			a[i]=4;
		else if(s[i-1]=='[')
			a[i]=5;
		else if(s[i-1]==']')
			a[i]=6;
	}
	int ans=dp(1,n);
	cout<<ans<<endl;
	return 0;
}