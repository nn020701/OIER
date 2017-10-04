#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<ctime>
#include<vector>
#define maxn 400050
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
inline ll get(){	return 1LL*rand()*rand();}
int main(){
	freopen("c.in","w",stdout);
	srand(time(0));
	ll n=1000,Q=1000;
	printf("%lld %lld\n",n,Q);
	while(Q--)	printf("%lld %lld %lld\n",rand()%n+1,rand()%((ll)1e3)+1,rand()%(n+1));
}
