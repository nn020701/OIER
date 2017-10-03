#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 19650827
int n;
int a[1010];
int f[1010][1010][2];
int pd(int x,int y)
{
	if(a[x]>a[y])
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
				f[i][j][0]=f[i+1][j][0]*pd(i+1,i)+f[i+1][j][1]*pd(j,i);
				f[i][j][1]=f[i][j-1][0]*pd(j,i)+f[i][j-1][1]*pd(j,j-1);
				f[i][j][0]%=N;
				f[i][j][1]%=N;
			}
	int ans=f[1][n][0]+f[1][n][1];
	ans%=N;
	cout<<ans<<endl;
	return 0;
}
