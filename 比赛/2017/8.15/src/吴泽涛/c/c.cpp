#include <cstdio> 
#include <cmath> 
#include <algorithm>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std ; 

const int N = 10011 ; 
int x,l,type,n,m,s,t,sum ; 
struct node{
	bool all ; 
	int f[4011] ; 
}w[N];

inline int read() 
{
	int x = 0 , f = 1 ; 
	char ch = getchar() ; 
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; } 
	while(ch>='0'&&ch<='9') { x = x * 10+ch-48 ; ch = getchar() ; } 
	return x * f ; 	
}

int main() 
{
	freopen("c.in","r",stdin) ; 
	freopen("c.out","w",stdout) ; 
	n = read() ; m = read() ; 
	while(m--) {
		x = read() ; type = read() ; l = read() ; 
		s = max(1,x - l) ;  t = min(x + l,n) ; 
		For(i,s,t) {
			if( !w[ i ].f[type] ) w[ i ].all = 1 , w[ i ].f[type] = 1 ; 
				else w[ i ].all = 0 ; 
		}
	}
	For(i,1,n) sum+=(w[ i ].all==0) ; 
	printf("%d\n",sum) ; 
	return 0 ; 
}
 
