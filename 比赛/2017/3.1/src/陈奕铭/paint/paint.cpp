#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k;
double ans;
double jisuan(int x,int y){
	double xx=2.0*x*(n-x+1)-1;
	double yy=2.0*y*(m-y+1)-1;
	return pow(1-xx*yy/(1.0*n*m*n*m),k);
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=1-jisuan(i,j);
	printf("%.20lf\n",ans);
	return 0;
}
