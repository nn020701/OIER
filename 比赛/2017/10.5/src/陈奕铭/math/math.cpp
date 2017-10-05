
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1000005
#define mod 100000007
#define gc getchar
using namespace std;
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
//inline char gc(){
//	if (S==T){
//		T=(S=LZH)+fread(LZH,1,L,stdin);
//		if (S==T) return EOF;
//	}
//	return *S++;
//}
inline ll read(){
	ll x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}

ll n,k,r;
struct Matrix{
	ll a[505];
	Matrix(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		for(int i = 0;i < k;i++){
			int t = i;
			for(int j = 0;j < k;j++){
				ans.a[t] = (ans.a[t]+a.a[i]*b.a[j])%mod;
				t = t == k-1?0:t+1;
			}
		}
		return ans;
	}
	friend Matrix operator ^(Matrix a,ll b){
		Matrix ans;
		ans.a[0] = 1;
		while(b){
			if(b&1) ans = ans*a;
			a = a*a;
			b >>= 1;
		}
		return ans;
	}
}a;

int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	int T = read();
	while(T--){
		n = read(); k = read(); r = read();
		for(int i = 0;i < k;i++)
			a.a[i] = 0;
		a.a[0]++; a.a[1%k]++;
		a = a ^ n;
		printf("%lld\n", a.a[r]);
	}
	return 0;
}