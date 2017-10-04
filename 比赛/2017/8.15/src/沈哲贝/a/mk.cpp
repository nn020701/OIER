#include<cstdio>
#include<memory.h>
#include<ctime>
#include<algorithm>
#define ll long long
#define maxn 1010
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
int main(){
	freopen("a.in","w",stdout);
	srand(time(0));
	ll n=100;
	printf("%lld %lld\n",n,1LL*rand()*rand()%((ll)1e9));
	For(i,1,n){
		For(j,1,n)	printf("%lld ",1LL*rand()*rand()%((ll)1e7));
		puts("");
	}
}
