#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
#define LL long long 
LL p,a,b,x,y,s1,s2,s3;
struct data{
	LL d[2][2];
}f,g,ans,q;
LL mi(LL x,LL n)
{
	if(n==1)
		return x%p;
	LL o=mi(x,n/2)%p;
	o=o*o%p;
	if(n%2!=0)
		o=o*x%p;
	return o;
}
LL gcd(LL a,LL b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
void cheng(data &a,data b)
{
	ans.d[0][0]=0;
	ans.d[1][0]=0;
	ans.d[0][1]=0;
	ans.d[1][1]=0;	
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				ans.d[i][j]=(ans.d[i][j]+a.d[i][k]*b.d[k][j])%p;
	a.d[0][0]=ans.d[0][0];
	a.d[1][0]=ans.d[1][0];
	a.d[0][1]=ans.d[0][1];
	a.d[1][1]=ans.d[1][1];
}
void juzhengmi()
{
	f.d[0][0]=y;	
	f.d[0][1]=1;
	g.d[0][0]=a;
	g.d[1][0]=b;
	g.d[1][1]=1;
	x--;
	for(LL k=0;k<=40;k++)
	{
		if (x&(1LL<<k))	
			cheng(f,g);
		q.d[0][0]=g.d[0][0];
		q.d[1][0]=g.d[1][0];
		q.d[0][1]=g.d[0][1];
		q.d[1][1]=g.d[1][1];	
		cheng(g,q);
	}
	s3=f.d[0][0];
}
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	cin>>x>>y>>a>>b>>p;
	
	LL q=x,l=y;
	if(q<l)
		swap(q,l);
	LL o=gcd(q,l);
	s1=(o%p)+(x*y/o)%p;
	s2=mi(x,y);
	juzhengmi();
	LL ans=((s1*s2)%p*s3)%p;
	cout<<ans<<endl;
	return 0;
}
