#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<memory.h>
#include<bitset>
#include<ctime>
#define ll long long
#define maxn 30005
#define For(i,j,k)	for(ll i=j;i<=k;i++)
#define FOr(i,j,k)	for(ll i=j;i>=k;i--)
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
    printf("\n");
}
ll hash[maxn],a[maxn],n,m;
int main(){
	srand(time(0));
	freopen("phi.in","w",stdout);
	ll n=1e5,t=1e6;
	writeln(n);
	For(i,1,n)	writeln(rand()*rand()%t+1);
}
