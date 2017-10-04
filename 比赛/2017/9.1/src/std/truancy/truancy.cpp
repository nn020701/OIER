#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
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
int n,k,h,t,a[1000005],q[1000005];
ll ans,f[1000005];
int main(){
	freopen("truancy.in","r",stdin);
	freopen("truancy.out","w",stdout); 
	n=read()+1; k=read()+1; 
	for (int i=1;i<n;i++)
		a[i]=read(),ans+=a[i];
	memset(f,0x3f,sizeof(f));
	f[0]=0; t=1; q[1]=0;
	for (int i=1;i<=n+1;i++){
		if (q[h+1]<i-k) h++;
		f[i]=f[q[h+1]]+a[i];
		while (h!=t&&f[q[t]]>f[i]) t--;
		q[++t]=i;
	}
	printf("%lld\n",ans-f[n+1]);
}
