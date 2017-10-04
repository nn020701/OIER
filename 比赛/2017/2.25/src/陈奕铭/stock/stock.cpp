#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[300];
int n,t,ans;
int Max_num,num,a_num;
bool Map[300][300];
bool vis[300][300];
int x[100010],y[100010];
int main(){
	freopen("stock.in","r",stdin);
	freopen("stock.out","w",stdout);
	n=read();t=read();
	Max_num=n*(n-1)/2;
	int a[310],b[310];
	int top_a,top_b;
	for(int i=1;i<=t;i++){
		x[i]=read();y[i]=read();
	}
	for(int i=1;i<=t;i++){

		if(Map[y[i]][x[i]]||y[i]==x[i])
			ans++;
		else{
			/*a_num++;
			if(!vis[x[i]][y[i]]){
				num++;
				vis[x[i]][y[i]]=true;
				if(num>=Max_num){
					ans=t-a_num;
					break;
				}
			}*/
			top_a=1;top_b=1;
			a[1]=x[i];b[1]=y[i];
			for(int j=1;j<=n;j++)
				if(Map[j][x[i]]&&!Map[j][y[i]])
					a[++top_a]=j;
			for(int j=1;j<=n;j++)
				if(Map[y[i]][j]&&!Map[x[i]][j])
					b[++top_b]=j;
			for(int j=1;j<=top_a;j++)
				for(int z=1;z<=top_b;z++)
					Map[a[j]][b[z]]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
