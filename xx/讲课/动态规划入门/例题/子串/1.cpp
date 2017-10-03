#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000000007
int n,m,k;
int f[1010][220];
int sum[1010][220];
string s1;
string s2;
int main()
{
	f[0][0]=1;
	cin>>n>>m>>k;
	cin>>s1>>s2;
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
