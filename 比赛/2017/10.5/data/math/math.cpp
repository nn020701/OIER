#include<cstdio>
#include<cstring>
#define mo 100000007
#define ll long long
using namespace std;
int T,k,r;
ll n;
struct mat{
	ll a[505];
	mat(){
		memset(a,0,sizeof(a));
	}
	ll& operator [](int x){
		return a[x];
	}
	friend mat operator *(mat a,mat b){
		mat c;
		for (int i=0;i<k;i++)
			for (int j=0;j<k;j++){
				int t=(i+j)%k;
				c[t]=(c[t]+a[i]*b[j])%mo; 
			}
		return c;
	}
	friend mat operator ^(mat a,ll b){
		mat c;
		c[0]=1;
		for (;b;b/=2,a=a*a)
			if (b&1) c=c*a;
		return c;
	}
}a;
int main(){
	freopen("math20.in","r",stdin);
	freopen("math20.out","w",stdout); 
	scanf("%d",&T);
	while (T--){
		scanf("%lld%d%d",&n,&k,&r);
		for (int i=0;i<k;i++) a[i]=0;
		a[0]++; a[1%k]++;
		a=a^n;
		printf("%lld\n",a[r]);
	}
}
