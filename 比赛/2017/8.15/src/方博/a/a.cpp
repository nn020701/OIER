#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int z[1005][1005];
int f[1005][1005];
int n,w;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();
//	n=1000;
	w=read();
//	srand(20);
	bool flag=false;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			a[i][j]=read();
//			a[i][j]=rand()%4+1;
			if(a[i][j]<w)flag=true;
		}
	if(!flag){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			z[i][j]=z[i-1][j-1]+a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=n;j>=1;j--)
			f[i][j]=f[i-1][j+1]+a[i][j];
	int l=1,r=n;
	for(;l<r;){
		int k=(l+r+1)/2;
		bool flag=false;
		for(int i=1;i<=n-k+1;i++)
			for(int j=1;j<=n-k+1;j++){
//			for(int k=ans+1;k+i<=n&&k+j<=n;k++){
				int ww=0;
				ww=z[i+k-1][j+k-1]-z[i-1][j-1]+f[i+k-1][j]-f[i-1][j+k];
				if(k%2==1)ww-=a[i+k/2][j+k/2];
				if(ww<=w)flag=true;
//				else k=n;
//				cout<<i<<' '<<j<<' '<<k<<' '<<ww<<endl;
			}
		k++;
		for(int i=1;i<=n-k+1;i++)
			for(int j=1;j<=n-k+1;j++){
//			for(int k=ans+1;k+i<=n&&k+j<=n;k++){
				int ww=0;
				ww=z[i+k-1][j+k-1]-z[i-1][j-1]+f[i+k-1][j]-f[i-1][j+k];
				if(k%2==1)ww-=a[i+k/2][j+k/2];
				if(ww<=w)flag=true;
//				else k=n;
//				cout<<i<<' '<<j<<' '<<k<<' '<<ww<<endl;
			}
		k--;
		if(flag)l=k;
		else r=k-1;
	}
	printf("%d",l);
	return 0;
}
