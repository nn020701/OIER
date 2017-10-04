#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
const int mod=1000000007;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	freopen("drive.in","r",stdin);
	freopen("bf.out","w",stdout);
	buf[fread(buf,1,MAXSIZE,stdin)]='\0';
	bufpos=0;
}
#if NEG
int readint(){
	bool isneg;
	int val=0;
	for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
	bufpos+=(isneg=buf[bufpos]=='-');
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return isneg?-val:val;
}
#else
int readint(){
	int val=0;
	for(;!isdigit(buf[bufpos]);bufpos++);
	for(;isdigit(buf[bufpos]);bufpos++)
		val=val*10+buf[bufpos]-'0';
	return val;
}
#endif
char readchar(){
	for(;isspace(buf[bufpos]);bufpos++);
	return buf[bufpos++];
}
int readstr(char* s){
	int cur=0;
	for(;isspace(buf[bufpos]);bufpos++);
	for(;!isspace(buf[bufpos]);bufpos++)
		s[cur++]=buf[bufpos];
	s[cur]='\0';
	return cur;
}
int a[500002],b[500002],ls[500002],rs[500002];
int pre[3002][3002],suf[3002][3002];
int main(){
	init();
	int n=readint();
	for(int i=1;i<=n;i++)
		a[i]=b[i]=readint();
	sort(b+1,b+n+1);
	int cur=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+cur+1,a[i])-b;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cur;j++)
			pre[i][j]=pre[i-1][j];
		for(int j=a[i];j<=cur;j++)
			pre[i][j]++;
	}
	for(int i=n;i;i--){
		for(int j=1;j<=cur;j++)
			suf[i][j]=suf[i+1][j];
		for(int j=a[i];j<=cur;j++)
			suf[i][j]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)
			if (a[j]<a[i]){
				//printf("ls[%d]=%d %d %d\n",i,ls[i],a[i],a[j]);
				ls[i]+=pre[j-1][a[i]-1]-pre[j-1][a[j]];
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if (a[j]<a[i])
				rs[i]+=suf[j+1][a[i]-1]-suf[j+1][a[j]];
		}
	ll ans=0;
	for(int i=1;i<=n;i++)
		(ans+=(ll)ls[i]*rs[i])%=mod;
	printf("%lld",ans);
}