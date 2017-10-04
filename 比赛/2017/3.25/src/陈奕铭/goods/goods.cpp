#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

const int N=50;
int n,m;
int bin[6],st[6],step[6],num_p[6];
int num_h[N];
double w[N],ans;

struct data{
	double w;
	int num;
}q[N];

void add(int j,int num_p){
	for(int i=1;i<bin[m];i++)
		if(i&bin[j-1]){
			if(num_p!=1)
				w[i]-=(double)1/(num_p-1);
			w[i]+=(double)1/num_p;
		}
}

bool cmp(data a,data b){
	return a.w>b.w;
}

int main(){
	freopen("goods.in","r",stdin);
	freopen("goods.out","w",stdout);
	scanf("%d%d",&n,&m);
	bin[0]=1;
	for(int i=1;i<=m;++i)
		bin[i]=bin[i-1]<<1;
	for(int i=1;i<=m;++i){
		scanf("%d",&st[i]); ++st[i];
	}
	for(int i=1;i<=m;++i)
		scanf("%d",&step[i]);
	for(int i=1;i<=n;++i){
		int sum=0;
		for(int j=1;j<=m;++j)
			if(i>=st[j]&&(i-st[j])%step[j]==0){
				++num_p[j];
				add(j,num_p[j]);
				sum+=bin[j-1];
			}
		num_h[sum]++;
		if(i*9>=n){
			sum=n-i;
			double k=0;
			for(int j=1;j<bin[m];++j){
				q[j].w=w[j]; q[j].num=num_h[j];
			}
			sort(q+1,q+bin[m],cmp);
			for(int j=1;j<bin[m];++j){
				if(8*q[j].num<=sum){
					sum-=8*q[j].num;
					k+=8*q[j].num*q[j].w;
				}
				else{
					k+=sum*q[j].w;
					sum=0;
				}
				k+=q[j].num*q[j].w;
			}
			ans=max(ans,k*i);
		}
	}
	printf("%.5lf",ans/m);
	return 0;
}
