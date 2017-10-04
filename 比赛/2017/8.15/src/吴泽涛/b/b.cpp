#include <cstdio> 
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std ; 

const int N = 1011 ; 
int n,m,mx,x,ans ; 
int sum[10][N][N],a[N][N] ; 

inline int read() 
{
	int x = 0 , f = 1 ; 
	char ch = getchar() ; 
	while(ch<'0'||ch>'9') { if(ch=='-') f = -1 ; ch = getchar() ; } 
	while(ch>='0'&&ch<='9') { x = x * 10+ch-48 ; ch = getchar() ; } 
	return x * f ; 	
} 

inline int max(int x,int y) { return x>y?x:y ; } 
 
inline void work() 
{
	mx = 0 ; 
	bool flag ; 
	For(sx,1,n) 
	  For(sy,1,m) 
		for(int tx=n;tx>=sx;tx--) 
		  for(int ty=m;ty>=sy;ty--) {
		  	x = sum[0][tx][ty] - sum[0][sx-1][ty] - sum[0][tx][sy-1] + sum[0][sx-1][sy-1] ; 
		  	if( x>=(tx-sx+1) * (ty-sy+1)-1 ) continue ; 
		  	flag = 0 ; 
		  	int tot = 0 ;  
		  	For(k,0,9) {
		  		x = sum[k][tx][ty] - sum[k][sx-1][ty] - sum[k][tx][sy-1] + sum[k][sx-1][sy-1] ;
		  		if(x&1) {
		  			tot++ ; 
					if(tot==2) {
						flag = 1 ; 
		  				break ; 
		  			}
				  }
			  }
		  	if(!flag) {
		  		ans = max(ans,(tx-sx+1)*(ty-sy+1)) ;  
		  		break ; 
		  	}
		  }
	printf("%d\n",ans) ; 
}

int main() 
{
	freopen("b.in","r",stdin) ; 
	freopen("b.out","w",stdout) ; 
	n = read() ; m = read() ; 
	For(i,1,n) 
		For(j,1,m) a[ i ][ j ] = read() ;  
	For(k,0,9) {
		For(i,1,n) 
			For(j,1,m) 
			  sum[k][i][j] = sum[k][i-1][j] + sum[k][i][j-1] - sum[k][i-1][j-1] + (a[i][j]==k) ; 
	}
	if( sum[ 0 ][ n ][ m ]>=n*m-1 ) {
		printf("0\n") ; 
		return 0 ; 	
	}
	work() ; 
	return 0 ; 
}
