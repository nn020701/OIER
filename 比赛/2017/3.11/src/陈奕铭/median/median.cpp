#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-'); x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){
	write(x);
	puts("");
}

const int N=100010;
int a[N],b[N],c[N];
int f[N*2][2];
int n,k,cnt,l=0,ans;

int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	n=read(); k=read();
	f[n][0]=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>k)
			cnt+=1;
		else if(a[i]<k)
			cnt-=1;
		ans+=f[cnt+n][(i+1)%2];
		f[cnt+n][i%2]++;
	}
	write(ans);
	return 0;
}