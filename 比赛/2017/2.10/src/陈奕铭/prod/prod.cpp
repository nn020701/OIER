#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
inline LL read(){
	LL x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
LL f_2[1010][1010],f_5[1010][1010];
LL Map[1010][1010];
LL Map_2[1010][1010],Map_5[1010][1010];
LL ans=0x7fffffffffffffff;
LL n;
LL pd_5(LL num){
	LL ans=0;
	while(num%5==0){
		ans++;
		num/=5;
	}
	return ans;
}
LL pd_2(LL num){
	LL ans=0;
	while(num%2==0){
		ans++;
		num/=2;
	}
	return ans;
}
int main(){
	freopen("prod.in","r",stdin);
	freopen("prod.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			Map[i][j]=read();
			if(Map[i][j]==0){
				Map_2[i][j]=0;
				Map_5[i][j]=0;
			}
			else{
				Map_2[i][j]=pd_2(Map[i][j]);
				Map_5[i][j]=pd_5(Map[i][j]);
			}
		}
	memset(f_2,0x3f,sizeof f_2);
	memset(f_5,0x3f,sizeof f_5);
	f_2[1][1]=Map_2[1][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(Map[i][j]==0)
				continue;
			if(i-1>=1&&Map[i-1][j]!=0){
				f_2[i][j]=f_2[i-1][j]+Map_2[i][j];
				if(j-1>=1&&Map[i][j-1]!=0)
					f_2[i][j]=min(f_2[i][j],f_2[i][j-1]+Map_2[i][j]);
			}
			else if(j-1>=1&&Map[i][j-1]!=0){
				f_2[i][j]=f_2[i][j-1]+Map_2[i][j];
				if(i-1>=1&&Map[i-1][j]!=0)
					f_2[i][j]=min(f_2[i][j],f_2[i-1][j]+Map_2[i][j]);
			}
		}
	f_5[1][1]=Map_5[1][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(Map[i][j]==0)
				continue;
			if(i-1>=1&&Map[i-1][j]!=0){
				f_5[i][j]=f_5[i-1][j]+Map_5[i][j];
				if(j-1>=1&&Map[i][j-1]!=0)
					f_5[i][j]=min(f_5[i][j],f_5[i][j-1]+Map_5[i][j]);
			}
			else if(j-1>=1&&Map[i][j-1]!=0){
				f_5[i][j]=f_5[i][j-1]+Map_5[i][j];
				if(i-1>=1&&Map[i-1][j]!=0)
					f_5[i][j]=min(f_5[i][j],f_5[i-1][j]+Map_5[i][j]);
			}
		}
	cout<<min(f_2[n][n],f_5[n][n]);
	return 0;
}
