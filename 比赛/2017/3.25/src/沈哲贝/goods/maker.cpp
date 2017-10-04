#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<queue>
#include<memory.h>
#include<ctime> 
#define ll long long
#define inf 2100000000
#define For(i,j,k)    for (ll i=j;i<=k;i++)
#define FOr(i,j,k)	  for (ll i=j;i>=k;i--)
#define pa pair<ll,ll>
#define maxn 800010
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(ll x){
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}
void writeln(ll x){
    write(x);
    puts("");
}
struct data{
	ll rnd,v;
}a[maxn];
bool cmp(data x,data y){
	return x.rnd<y.rnd;
}
int main(){
	freopen("median.in","w",stdout);
	srand(time(0));
	ll n=rand()%100+1,k=rand()%n+1;
	printf("%I64d %I64d\n",n,k);
	For(i,1,n)	a[i].rnd=rand()*rand()%inf*rand()%inf,a[i].v=i;
	sort(a+1,a+n+1,cmp);
	For(i,1,n)	printf("%I64d ",a[i].v);
}
