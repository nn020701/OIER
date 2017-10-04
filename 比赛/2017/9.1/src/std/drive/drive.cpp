#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int L=200000;
char LZH[L];
char *S,*T;
inline char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++; 
}
inline int read(){
	int x=0;
	char c=gc();
	for (;c<'0'||c>'9';c=gc());
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x;
}
const int N=500005,mo=1000000007;
int n,a[N],b[N];
ll ans,c[N],d[N];
struct data{
	ll t[N];
	void init(){
		memset(t,0,sizeof(t));
	}
	void change(int x,int y){
		for (;x<=n;x+=x&(-x)) t[x]+=y;
	}
	ll ask(int x){
		ll s=0;
		for (;x;x-=x&(-x)) s+=t[x];
		return s;
	}
}t0,t1;
void work(ll *c){
	t0.init(); t1.init();
	for (int i=1;i<=n;i++){
		ll tmp=t0.ask(a[i]);
		t0.change(a[i],1);
		t1.change(a[i],tmp);
		tmp=t0.ask(a[i]-1);
		c[i]=(tmp*(tmp-1)/2-t1.ask(a[i]-1))%mo;
	}
}
int main(){
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout); 
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	work(c);
	reverse(a+1,a+n+1);
	work(d);
	for (int i=1;i<=n;i++)
		ans=(ans+c[i]*d[n-i+1])%mo;
	printf("%lld",ans);
}
