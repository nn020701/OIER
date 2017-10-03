#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define LL long long
LL f[4][4][4][4];
LL ans;
int n;
LL food(int i,int j,int k)
{
	int s[4]={0};
	s[i]=1;
	s[j]=1;
	s[k]=1;
	int p=s[1]+s[2]+s[3];
	return p;
}
int main()
{
	string s;
	cin>>n>>s;
	int u;
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++)
			for(int l=0;l<=3;l++)
				for(int k=0;k<=3;k++)
					f[i][j][l][k]=-1;
	f[0][0][0][0]=0;
	for(int t=0;t<n;t++)
	{
		if(s[t]=='M') u=1;
		else if(s[t]=='F') u=2;
		else if(s[t]=='B') u=3;
		LL a[4][4][4][4];
		for(int i=0;i<=3;i++)
			for(int j=0;j<=3;j++)
				for(int l=0;l<=3;l++)
					for(int k=0;k<=3;k++)
						a[i][j][l][k]=-1;
		for(int i=0;i<=3;i++)
			for(int j=0;j<=3;j++)
				for(int l=0;l<=3;l++)
					for(int k=0;k<=3;k++)
						if(f[i][j][l][k]!=-1)
						{
							a[j][u][l][k]=max(a[j][u][l][k],f[i][j][l][k]+food(i,j,u));
							a[i][j][k][u]=max(a[i][j][k][u],f[i][j][l][k]+food(l,k,u));
						}
		for(int i=0;i<=3;i++)
			for(int j=0;j<=3;j++)
				for(int l=0;l<=3;l++)
					for(int k=0;k<=3;k++)
						f[i][j][l][k]=a[i][j][l][k];
	}
	for(int i=0;i<=3;i++)
		for(int j=0;j<=3;j++)
			for(int l=0;l<=3;l++)
				for(int k=0;k<=3;k++)
					ans=max(ans,f[i][j][l][k]);
	cout<<ans<<"\n";
	return 0;
}
