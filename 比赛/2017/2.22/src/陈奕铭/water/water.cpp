#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[305],f[2][305][305],n,m,flag,ans,zero;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==0)
			flag=1;
	}
	if(!flag)
		a[++n]=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]==0){
			zero=i;
			break;
		}
	ans=m;
	for(int t=1;t<=n;t++){
		memset(f,0x3f,sizeof f);
		f[0][zero][zero]=f[1][zero][zero]=0;
		for(int i=2;i<=t;i++)
			for(int j=1,k=i;k<=n;j++,k++){
				f[0][j][k]=min(f[0][j+1][k]+(a[j+1]-a[j])*(t-i+1),f[1][j+1][k]+(a[k]-a[j])*(t-i+1));
				f[1][j][k]=min(f[1][j][k-1]+(a[k]-a[k-1])*(t-i+1),f[0][j][k-1]+(a[k]-a[j])*(t-i+1));
			}
		for(int i=1,j=t;j<=n;i++,j++)
			ans=max(ans,t*m-min(f[0][i][j],f[1][i][j]));
	}
	if(!flag)
		ans-=m;
	printf("%d",ans);
}

