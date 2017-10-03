#define Rep(x,a,b) for (int x=a;x<=b;x++)
void Floyd(){
	Rep(i,1,n) Rep(j,1,n) Rep(k,1,n)
		a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
}
