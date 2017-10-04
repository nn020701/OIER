#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void wri(ll x){
	if(x>=10) wri(x/10);
	putchar(x%10+'0');
}
void write(ll x){
	if(x<0){putchar('-'); x=-x;}
	wri(x);
}
void writeln(ll x){
	write(x);
	puts("");
}

const int N=4010;
const ll mod=1000000007;
int n,m,q;
ll a[N],p[N][N];

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=0;i<n;++i)
		p[1][i]=1;
	for(int i=2;i<=m;++i)
		for(int j=0;j<n;++j)
			if(j!=0)
				 p[i][j]=(p[i-1][j]+p[i][j-1])%mod;
			else p[i][j]=p[i-1][j];
	char ch[10];
	ll x,y,ans;
	while(q--){
		scanf("%s",ch);
		x=read(); y=read();
		if(ch[0]=='Q'){
			if(x==0) writeln(a[y]);
			else{
				ans=0;
				for(int i=1;i<=y;i++)
					ans=(ans+p[x][y-i]*a[i])%mod;
				writeln(ans);
			}
		}
		else a[x]=(a[x]+y)%mod;
	}
	return 0;
}
