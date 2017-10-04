#include <cstdio>
#include <cmath>
#include <algorithm> 
#define For(i,j,k) for(int i=j;i<=k;i++) 
using namespace std ; 

const int N = 1011 ; 
int n,W,ans ; 
int a[N][N] ; 

inline int read() 
{
	int x = 0 , f = 1 ; 
	char ch = getchar() ; 
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; } 
	while(ch>='0'&&ch<='9') { x= x * 10 +ch-48 ; ch = getchar() ; } 
	return x * f ; 
}

inline void work()
{
	int l,sum,x,y,xx,yy,ty ;  
	For(i,1,n) 
		For(j,1,n) {
			for(l=min(n-i+1,n-j+1);l>=1;l--) {
				x = i+l-1 ; 
				y = j+l-1 ; 
				if(x>n||y>n) continue ; 
				sum = 0 ; 
				For(k,1,l) {
					xx = i+k-1 ; 
					yy = j+k-1 ; 
					sum+=a[xx][yy] ; 
					ty = y-(yy-j) ;  
					if(yy!=ty) sum+=a[xx][ty] ; 
				}
				if( sum <= W ) break ; 
				
			}
			if( l > ans ) ans = l ; 
		}
	printf("%d",ans) ; 
	
}

int main() 
{
	freopen("a.in","r",stdin) ; 
	freopen("a.out","w",stdout) ; 
	n = read() ; W = read() ; 
	For(i,1,n) 
		For(j,1,n) a[ i ][ j ] = read() ; 
	work() ; 
	return 0 ; 
}
