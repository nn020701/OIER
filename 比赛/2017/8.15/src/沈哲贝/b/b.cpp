#include<cstdio>
#include<memory.h>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define g(i,j)	a[(i-1)*m+j]
#define maxn 100010
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
ll map[maxn],bin[100],hash[maxn],sum[maxn],a[maxn],cur_sum,cur_hash,n,m,answ,now_sum,now_hash;
bool mark[3010];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	bin[0]=1;	For(i,1,10)	bin[i]=bin[i-1]<<1;	bin[10]=0;
	For(i,0,9)	mark[bin[i]]=1;	mark[0]=1;
	n=read();	m=read();	answ=1;
	ll x,y;
	if (n<=m)	For(i,1,n)	For(j,1,m)	a[(i-1)*m+j]=read();
	else{
		For(i,1,n)	For(j,1,m)	a[(j-1)*n+i]=read();
		swap(n,m);
	}
	For(i,1,n){
		For(j,1,m)	sum[j]=hash[j]=0;	ll x;
		For(j,i,n){
			map[0]=1;	cur_sum=cur_hash=0;
			For(k,1,m){
				now_sum=sum[k];	now_hash=hash[k];
				sum[k]=sum[k-1]+sum[k]-cur_sum+g(j,k);
				hash[k]=hash[k-1]^hash[k]^cur_hash^bin[g(j,k)];
				cur_sum=now_sum;cur_hash=now_hash;
			}
			For(k,1,m){
				x=hash[k];
					For(yy,0,10)
					if (map[x^bin[yy]]&&(sum[k]-sum[map[x^bin[yy]]-1]>yy%10))	answ=max(answ,(j-i+1)*(k-map[x^bin[yy]]+1));
				if (!map[x])	map[x]=k+1;
			}
			For(k,1,m)	map[hash[k]]=0;
		}
	}writeln(answ);
}
/*
3 3
1 1 1
1 0 1
1 1 1
*/
