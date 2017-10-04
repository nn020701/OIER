#include		<iostream>
#include		<cstdio>
#include        <cstdlib>
#include		<cstring>
#include		<cmath>
#define 	MD 100000000
using namespace std;
int f[101][101][11][11];
int i,j,n1,n2,l1,l2,k1,k2,ans;
void		add(int &a,int &b){
	a=(a+b)%MD;
}
int main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
    //cout<<n1<<" "<<n2<<" "<<k1<<" "<<k2<<endl;
	f[0][0][0][0]=1;
	for (i=0;i<=n1;i++)
	for (j=0;j<=n2;j++)
	for (l1=0;l1<=k1;l1++)
	for (l2=0;l2<=k2;l2++)
	if (f[i][j][l1][l2])
	{
		if (i+1<=n1 && l1+1<=k1)
		add(f[i+1][j][l1+1][0],f[i][j][l1][l2]);
		if (j+1<=n2 && l2+1<=k2)
		add(f[i][j+1][0][l2+1],f[i][j][l1][l2]);
	}
	ans=0;
	for (l1=1;l1<=k1;l1++)
	add(ans,f[n1][n2][l1][0]);
	for (l2=1;l2<=k2;l2++)
	add(ans,f[n1][n2][0][l2]);
	printf("%d\n",ans);
	fclose(stdout);
	return 0;
}
