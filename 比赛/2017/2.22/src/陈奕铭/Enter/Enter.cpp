#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll n;
ll Max=-99999999999;
ll Map[110][110];
void zuo(ll x,ll y){
	ll j=y;
	ll ans=Map[x][y];
	if(ans>Max) Max=ans;
	j--;
	if(j==0)
		j=n;
	while(j!=y){
		ans+=Map[x][j];
		if(ans>Max) Max=ans;
		j--;
		if(j==0) j=n;
	}
}
void you(ll x,ll y){
	ll j=y;
	ll ans=Map[x][y];
	j++;
	if(j==n+1)j=1;
	while(j!=y){
		ans+=Map[x][j];
		if(ans>Max) Max=ans;
		j++;
		if(j==n+1) j=1;
	}
}
void shang(ll x,ll y){
	ll i=x;
	ll ans=Map[x][y];
	i--;
	if(i==0) i=n;
	while(i!=x){
		ans+=Map[i][y];
		if(ans>Max) Max=ans;
		i--;
		if(i==0) i=n;
	}
}
void xia(ll x,ll y){
	ll i=x;
	ll ans=Map[x][y];
	i++;
	if(i==n+1) i=1;
	while(i!=x){
		ans+=Map[i][y];
		if(ans>Max) Max=ans;
		i++;
		if(i==n+1) i=1;
	}
}
void zuo_shang(ll x,ll y){
	ll i=x,j=y;
	ll ans=Map[x][y];
	i--;j--;
	if(i==0) i=n;
	if(j==0) j=n;
	while(i!=x&&j!=y){
		ans+=Map[i][j];
		if(ans>Max) Max=ans;
		i--;j--;
		if(i==0) i=n;
		if(j==0) j=n;
	}
}
void zuo_xia(ll x,ll y){
	ll i=x,j=y;
	ll ans=Map[x][y];
	i++;j--;
	if(i==n+1) i=1;
	if(j==0) j=n;
	while(i!=x&&j!=y){
		ans+=Map[i][j];
		if(ans>Max) Max=ans;
		i++;j--;
		if(i==n+1) i=1;
		if(j==0) j=n;
	}
}
void you_shang(ll x,ll y){
	ll i=x,j=y;
	ll ans=Map[x][y];
	i--;j++;
	if(i==0) i=n;
	if(j==n+1) j=1;
	while(i!=x&&j!=y){
		ans+=Map[i][j];
		if(ans>Max) Max=ans;
		i--;j++;
		if(i==0) i=n;
		if(j==n+1) j=1;
	}
}
void you_xia(ll x,ll y){
	ll i=x,j=y;
	ll ans=Map[x][y];
	i++;j++;
	if(i==n+1) i=1;
	if(j==n+1) j=1;
	while(i!=x&&j!=y){
		ans+=Map[i][j];
		if(ans>Max) Max=ans;
		i++;j++;
		if(i==n+1) i=1;
		if(j==n+1) j=1;
	}
}
/*void zuo(ll x){
	ll j=1;
	ll q=1;
	int mx=Map[x][j];
	j++;
	int p=-99999999;
	for(int t=1;t<=2*n;t++){
		if(Map[x][j]+mx<0){
			q=1;
			if(p<mx) p=mx;
			mx=Map[x][j];
		}
		else{
			q++;
			if(p<mx) p=mx;
			mx+=Map[x][j];
			if(q==n)
				break;
		}
		j++;
		if(j==n+1) j=1;
	}
	if(p<mx) p=mx;
	if(p>Max) Max=p;
}
void shang(int y){
	int i=1;
	int q=1;
	int mx=Map[i][y];
	i++;
	int p=-99999999;
	for(int t=1;t<=2*n;t++){
		if(Map[i][y]+mx<0){
			q=1;
			if(p<mx) p=mx;
			mx=Map[i][y];
		}
		else{
			q++;
			if(p<mx) p=mx;
			mx+=Map[i][y];
			if(q==n)
				break;
		}
		i++;
		if(i==n+1) i=1;
	}
	if(p<mx) p=mx;
	if(p>Max) Max=p;
}
void zuo_shang(int x,int y){
	int i=x,j=y;
	int q=1;
	int mx=Map[]
}*/
int main(){
	freopen("Enter.in","r",stdin);
	freopen("Enter.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			Map[i][j]=read();
	if(n==1){
		printf("%lld",Map[1][1]);
		return 0;
	}
		
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++){
			zuo(i,j);
			you(i,j);
			shang(i,j);
			xia(i,j);
			zuo_shang(i,j);
			zuo_xia(i,j);
			you_shang(i,j);
			you_xia(i,j);
		}
	printf("%lld",Max);
	return 0;
}
