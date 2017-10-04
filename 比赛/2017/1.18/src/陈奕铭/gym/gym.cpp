#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL unsigned long long
LL n,m,l;
LL Gcd(LL m,LL n)
{
	if(m%n==0)
		return n;
	return Gcd(n,m%n);
}
int main()
{
	freopen("gym.in","r",stdin);
	freopen("gym.out","w",stdout);
	cin>>l>>n>>m;
	LL t;
	if(n>m)
	{
		t=n;
		n=m;
		m=t;
	}
	LL g=Gcd(m,n);
	LL gongb=n/g;
	LL ans=l/gongb/m;
	ans*=n;
	ans+=min(l-l/gongb/m*gongb*m+1,n)-1;
	LL p=Gcd(l,ans);
	ans=ans/p;
	l=l/p;
	cout<<ans<<"/"<<l<<endl;
	return 0;
}
