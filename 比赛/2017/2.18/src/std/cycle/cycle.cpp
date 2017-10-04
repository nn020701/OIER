#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 5005
using namespace std;

const int BSZ=63;

int n;
char a[oo][oo];
long long in[oo][oo/BSZ+5],ou[oo][oo/BSZ+5];

int main()
{
	freopen("cycle.in","r",stdin);
	freopen("cycle.out","w",stdout);
	
	scanf("%d",&n);
	gets(a[0]);
	for (int i=0;i<n;++i) gets(a[i]);
	
	for (int i=0;i<n;++i) a[i][i]='0';
	
	for (int i=0;i<n;++i)
	for (int j=0;j<n;++j)
	if (a[i][j]=='1'){
		in[j][i/BSZ]+=1LL<<(i%BSZ);
		ou[i][j/BSZ]+=1LL<<(j%BSZ);
	}
	
	bool flag=0;
	for (int i=0;i<n-1;++i)
	for (int j=i+1;j<n;++j)
	if (a[i][j]=='1'){
		for (int k=(n-1)/BSZ;k>=0 && !flag;--k)
		if (in[i][k]&ou[j][k]) flag=1;
		
		if (flag){
			for (int k=0;k<n;++k)
			if (a[k][i]=='1' && a[j][k]=='1'){
				printf("%d %d %d\n",i+1,j+1,k+1);
				exit(0);
			}
		}
	}
	
	printf("-1\n");
	return 0;
}
