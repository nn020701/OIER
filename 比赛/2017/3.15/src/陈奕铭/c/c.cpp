#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-'); x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){
	write(x);
	puts("");
}

const int N=100100;
const int mod=1000000007;

int ans;
int n,m,q,ch,x,y;
int f[11][N],c[11][N],num[11][N];
int a[N];
char s[10];

void add(int k,int x,int y){
	for( ;x<=n;x+=lowbit(x))
		c[k][x]=(c[k][x]+y)%mod;
}

int query(int k,int x){
	int t=0;
	for( ;x;x-=lowbit(x))
		t=(c[k][x]+t)%mod;
	return t;
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(); m=read(); q=read();
	for(int i=1;i<=n;i++)
		f[1][i]=i;
	for(int i=2;i<=10;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
	for(int i=1;i<=n;i++)
		num[1][i]=1;
	for(int i=2;i<=10;i++)
		for(int j=n;j;j--)
			num[i][j]=(num[i-1][j]+num[i][j+1])%mod;
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=1;j<=10;j++)
			add(j,i,1ll*a[i]*num[j][i]%mod);
	}
	while(q--){
		scanf("%s",s);
		if(s[0]=='Q'){
			y=read(); x=read();
			if(!y) writeln(a[x]);
			else{
				ans=query(y,x);
				for(int j=n-x,k=1;k<y&&j;j--,k++){
					if(k&1)
						ans=(ans+mod-1ll*f[k][j]*query(y-k,x)%mod)%mod;
					else
						ans=(ans+1ll*f[k][j]*query(y-k,x)%mod)%mod;
				}
				writeln(ans);
			}
		}
		else{
			x=read(); y=read();
			a[x]=(a[x]+y)%mod;
			for(int i=1;i<=10;i++)
				add(i,x,1ll*y*num[i][x]%mod);
		}
	}
	return 0;
}
