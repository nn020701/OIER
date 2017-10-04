#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int fs[20];
int Map[20][20];
int n,Max;
int f[20];
int tot1,tot2;
bool vis[20];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int main(){
	freopen("bro.in","r",stdin);
	freopen("bro.out","w",stdout);
	scanf("%d",&n);
	fs[1]=1;
	char ch[20];
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		for(int j=1;j<=n;j++)
			Map[i][j]=ch[j-1]-'0';
	}
	if(n<=2){
		printf("%d",n);
		return 0;
	}
	for(int i=2;i<=n+1;i++) fs[i]=fs[i-1]<<1;
	for(int i=0;i<fs[n+1];i++){
		for(int j=1;j<=n;j++){
			vis[j]=false;
			f[j]=j;
		}
		tot2=tot1=n;
		for(int j=1;j<=n;j++)
			if(i&fs[j]){
				tot1--;
				int fx=get(j);
				for(int z=1;z<=n;z++)
					if(Map[j][z]&&!vis[z]){
						int fy=get(z);
						if(fx!=fy){
							tot2--;
							f[fy]=fx;
							vis[z]=true;
						}
					}
			}
		if(tot2==1)
			Max=max(Max,tot1);
	}
	printf("%d",Max);
	return 0;
}