#include<stdio.h>
#include<math.h>
#define M 32768
#define min(a,b) ((a)<(b)?(a):(b))

int n;
double mp[16][16];
double x[16],y[16];
double f[M][16];

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
		for(int j = 1;j < i;j++){
			mp[i][j] = mp[j][i] = sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])));
		}
	}
	// for(int i = 1;i <= n;i++,puts(""))
		// for(int j = 1;j <= n;j++)
			// printf("%.2lf ",mp[i][j]);
	for(int i = 1;i < (1<<n);i++)
		for(int j = 1;j <= n;j++)
			f[i][j]= 99999999.00;
	for(int i = 1;i <= n;i++){
		f[1<<(i-1)][i] = (sqrt((x[i]*x[i])+(y[i]*y[i])));
		// printf("%.2lf\n",f[1<<(i-1)][i]);
	}
	for(int i = 1;i < (1<<n);i++){
		for(int a = 1;a <= n;a++){
			if((1<<(a-1))&i){
				for(int b = 1;b <= n;b++)
					if(!((1<<(b-1))&i)){
						f[i|(1<<(b-1))][b] = min(f[i][a]+mp[a][b],f[i|(1<<(b-1))][b]);
					}
			}
		}
	}
	double ans = 999999999.00;
	for(int i = 1;i <= n;i++){
		ans = min(ans,f[(1<<n)-1][i]);
		// printf("%.2lf\n",f[(1<<n)-1][i]);
	}
	printf("%.2lf\n",ans);
	return 0;
}	