#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=30000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
	freopen("truancy.in","r",stdin);
	freopen("truancy.out","w",stdout);
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
ll f[1000002],g[1000002],sum[1000002];
int q[1000002];
int main(){
	init();
	int n=readint(),k=readint();
	for(int i=1;i<=n;i++)
		sum[i]=readint()+sum[i-1];
	//g[i]=max(g[i-1],f[i-1]),f[i]=max(g[j]+sum[i]-sum[j])(j in [i-k,i])
	int l=1,r=1;
	for(int i=1;i<=n;i++){
		g[i]=max(g[i-1],f[i-1]);
		while(l<=r && g[q[r]]-sum[q[r]]<g[i]-sum[i])
			r--;
		q[++r]=i;
		if (q[l]==i-k-1)
			l++;
		f[i]=g[q[l]]+sum[i]-sum[q[l]];
		//printf("%lld %lld\n",f[i],g[i]);
	}
	printf("%lld",f[n]);
}