#include<cstdio>
#include<cstring>
#define mo 100000007
#define ll long long
using namespace std;
int T,k,r;
ll n;
struct mat{
	int a[505];
	mat(){
		memset(a,0,sizeof(a));
	}
	friend mat operator *(const mat &a,const mat &b){
		mat c;
		for (int i=0,t;i<k;i++){
			t=i;
			for (int j=0;j<k;j++){
				c.a[t]=(c.a[t]+1ll*a.a[i]*b.a[j])%mo;
				t=t==k-1?0:t+1; 
			}
		}
		return c;
	}
	friend mat operator ^(mat a,ll b){
		mat c;
		c.a[0]=1;
		for (;b;b/=2,a=a*a)
			if (b&1) c=c*a;
		return c;
	}
}a;
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout); 
	scanf("%d",&T);
	while (T--){
		scanf("%lld%d%d",&n,&k,&r);
		for (int i=0;i<k;i++) a.a[i]=0;
		a.a[0]++; a.a[1%k]++;
		a=a^n;
		printf("%d\n",a.a[r]);
	}
}
