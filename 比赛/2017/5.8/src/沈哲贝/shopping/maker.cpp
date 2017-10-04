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
#define ll int
#define inf 2100000000
#define For(i,j,k)    for (ll i=j;i<=k;i++)
#define FOr(i,j,k)	  for (ll i=j;i>=k;i--)
#define pa pair<ll,ll>
#define maxn 8000100
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
int main(){
	freopen("queen.in","w",stdout);
	ll T=10000*(10000+1)/2;
	writeln(T);
	For(i,1,10000)	For(j,i,10000)	printf("%d %d\n",i,j);
}
