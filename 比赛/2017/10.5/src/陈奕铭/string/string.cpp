#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define gc getchar
#define N 3005
#define mod 1000000007
using namespace std;
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
// inline char gc(){
// 	if (S==T){
// 		T=(S=LZH)+fread(LZH,1,L,stdin);
// 		if (S==T) return EOF;
// 	}
// 	return *S++;
// }
inline int read(){
	int x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}

int n,q,k;
string s[N];
int len[N];
int w[N][N];
ll a[N],b[N];
ll ans;

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll num = exgcd(b,a%b,x,y);
	ll tmp = x;
	x = y;
	y = tmp-a/b*y;
	return num;
}

inline ll C(ll n,ll m){
	return (a[n]*b[n-m]%mod)*b[m]%mod;
}

inline int Min(int a,int b){
	if(a < b) return a;
	return b;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n = read(); q = read();
	for(int i = 1;i <= n;i++)
		cin >> s[i];
	sort(s+1,s+n+1);
	for(int i = 1;i <= n;i++)
		len[i] = s[i].length();
	for(int i = 0;i < Min(len[1],len[2]);i++)
		if(s[1][i] == s[2][i])
			w[2][1]++;
		else break;
	for(int i = 3;i <= n;i++){
		for(int j = i-1;j >= 0;j--){
			w[i][j] = Min(w[i][j+1],w[j+1][j]);
			for(int k = w[i][j];k < Min(len[i],len[j]);k++)
				if(s[i][k] == s[j][k])
					w[i][j]++;
				else break;
		}
	}

	for(int i = 1;i <= n;i++)
		for(int j = 1;j < i;j++)
			ans = (ans+w[i][j])%mod;

	a[0] = 1;
	for(ll i = 1;i <= n;i++)
		a[i] = a[i-1]*i%mod;
	ll y;
	exgcd(a[n],mod,b[n],y);
	b[n] = (b[n]+mod)%mod;
	for(ll i = n-1;i >= 0;i--)
		b[i] = (b[i+1]*(i+1))%mod;
	/*for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j < i;j++)
			printf("%d ",w[i][j]);*/
	while(q--){
		k = read();
		ll p = (C(n,k)-(C(n-1,k-1)*2%mod-C(n-2,k-2)+mod)%mod+mod)%mod;
		printf("%lld\n",(p*ans)%mod);
	}
	return 0;
}