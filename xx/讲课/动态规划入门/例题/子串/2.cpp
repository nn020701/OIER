#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 1000000007
int f[220][220];
int sum[220][220];
int n,m,k;
string s1;
string s2;
int main()
{
	cin>>n>>m>>k;
	cin>>s1>>s2;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			for(int z=k;z>=1;z--)
			{
				sum[j][z]=0;
				if(s1[i-1]==s2[j-1])
					sum[j][z]=(sum[j-1][z]+f[j-1][z-1])%N;
				f[j][z]=(f[j][z]+sum[j][z])%N;
			}
	cout<<f[m][k]<<endl;
	return 0;
}
