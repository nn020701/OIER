#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define LL long long
#define inf 100000000
#define N 20010
using namespace std;

inline LL read(){
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void write(LL x){
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}
void writeln(LL x){
    write(x);
    puts("");
}

LL ans[N],a[N],b[N],c[N],d[N];
LL n,Min,m,t=1;
char ch[N];

void print(LL a[]){
	while(!a[a[0]]&&a[0]>1) a[0]--;
	write(a[a[0]]);
	for(int i=a[0]-1;i>=1;i--){
		if (a[i]<10000000)	putchar('0');
		if (a[i]<1000000)	putchar('0');
		if (a[i]<100000)	putchar('0');
		if (a[i]<10000)		putchar('0');
		if (a[i]<1000)		putchar('0');
		if (a[i]<100)		putchar('0');
		if (a[i]<10)		putchar('0');
		write(a[i]); 
	}
	exit(0);
}
void cheng(LL a[],LL b[]){
	ans[0]=a[0]+b[0]-1;
	for(int i=1;i<=a[0];i++)
		for(int j=1;j<=b[0];j++)
			ans[i+j-1]+=a[i]*b[j];
	for(int i=1;i<=a[0]+b[0]-1;i++)
		ans[i+1]+=ans[i]/100000000,ans[i]%=100000000;
	while(ans[ans[0]+1])
		ans[0]++;
	for(int i=0;i<=ans[0];i++)
		a[i]=ans[i];
	for(int i=ans[0];i>=0;i--)
		ans[i]=0;
}
LL bijiao(LL a[],LL b[]){
	if(a[0]<b[0]) return 1;
	if(a[0]>b[0]) return 0;
	for(int i=a[0];i>=1;i--)
		if(a[i]>b[i]) return 0;
	else if(a[i]<b[i])	return 1;
	return 2;
}
bool pd(){
	for(int i=0;i<=b[0];i++)
		c[i]=b[i];
	LL tt=m-1;
	for(int i=1;i<=tt;i++)
		cheng(c,b); 
	LL ans=bijiao(c,a);
	for(int i=c[0];i>=0;i--)
		c[i]=0;
	for(int i=d[0];i>=0;i--)
		d[i]=0;
	if(ans==2)
		print(b);
	else return ans;
}
int main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	m=read();
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;i++)
		a[(n-i+8)/8]=a[(n-i+8)/8]*10+ch[i]-'0';
	n=(n-1)/8+1;
	a[0]=n;
	b[0]=Min=n/m+1;
	for(int i=Min;i>=1;i--){
		LL l=0,r=99999999,ans=0;
		while(l<=r){
			LL mid=(l+r)>>1;
			b[i]=mid;
			if(pd()) ans=mid,l=mid+1;
			else r=mid-1;
		}
		b[i]=ans;
		if(i==Min&&!b[Min])
			b[0]=max(t,b[0]-1);
	}
	print(b);
	return 0;
}
