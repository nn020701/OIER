#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define mo 1000000007
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=x*10-48+ch;
	return x;
}
struct data{int a,p;}p[700005];
bool cmp(data a,data b){
	return a.p!=b.p?a.p<b.p:a.a>b.a;
}
int n,tot,x,last;
ll ans=1,sum[35];
void chai(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			p[++tot].p=i;
			while (x%i==0)
				p[tot].a++,x/=i;
		}
	if (x!=1)
		p[++tot].p=x,p[tot].a=1;
}
ll power(ll x,ll y){
	ll s=1;
	for (;y;y/=2,x=x*x%mo)
		if (y&1) s=s*x%mo;
	return s;
}
void calc(int l,int r){
	ll pp=p[l].p,re=1;
	sum[0]=1;
	for (int i=1;i<=p[l].a;i++)
		sum[i]=sum[i-1]*pp%mo;
	for (int i=1;i<=p[l].a;i++)
		sum[i]=(sum[i]+sum[i-1])%mo;
	for (int i=l;i<=r;i++)
		re=re*sum[p[i].a]%mo;
	re=(re-1)*power(pp,mo-2)%mo;
	re=(re*(pp-1)+1)%mo;
	ans=ans*re%mo;
}
int main(){
	freopen("phi.in","r",stdin);
	freopen("phi.out","w",stdout); 
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		chai(x);
	}
	sort(p+1,p+tot+1,cmp);
	for (int i=1;i<=tot;i++)
		if (i==tot||p[i].p!=p[i+1].p)
			calc(last+1,i),last=i;
	printf("%lld",(ans%mo+mo)%mo);
}
