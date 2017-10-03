#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1010][1010][2];
int n;
int a[1010];
int pd(int a,int b)
{
	if(a>b)
		return 1;
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f[i][i][0]=1;
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=0;k<=1;k++)
			{
				f[i][j][0]=f[i+1][j][0]*pd(a[i+1],a[i])+f[i+1][j][1]*pd(a[j],a[i]);
				f[i][j][1]=f[i][j-1][0]*pd(a[j],a[i])+f[i][j-1][1]*pd(a[j],a[j-1]);
				f[i][j][0]%=19650827;
				f[i][j][1]%=19650827;
			}
	int ans=(f[1][n][0]+f[1][n][1])%19650827;
	cout<<ans<<endl;
	return 0;
}
