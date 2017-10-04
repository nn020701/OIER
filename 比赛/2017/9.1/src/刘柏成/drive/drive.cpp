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
	freopen("drive.out","w",stdout);
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
int a[500002],b[500002];
ll pre[500002],suf[500002],pre2[500002],suf2[500002];
ll ls[500002],rs[050002];
struct bit{
	int n;
	ll a[500002];
	void add(int p,ll v){
		for(;p<=n;p+=p&-p)
			a[p]+=v;
	}
	ll query(int p){
		ll ans=0;
		for(;p;p-=p&-p)
			ans+=a[p];
		return ans;
	}
}t;
struct bint{
	int n;
	int a[500002];
	int w[500002];
	void add(int p,int v){
		w[p]+=v;
		for(;p<=n;p+=p&-p)
			a[p]+=v;
	}
	int query(int p){
		ll ans=0;
		for(;p;p-=p&-p)
			ans+=a[p];
		return ans;
	}
}t2;
int main(){
	init();
	int n=readint();
	for(int i=1;i<=n;i++)
		a[i]=b[i]=readint();
	sort(b+1,b+n+1);
	int cur=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+cur+1,a[i])-b;
	
	t.n=t2.n=cur;
	for(int i=1;i<=n;i++){
		pre[i]=t2.query(a[i]-1);
		pre2[i]=pre[i]+t2.w[a[i]];
		t2.add(a[i],1);
	}
	//memset(t.a,0,sizeof(t.a));
	for(int i=n;i;i--){
		int qwq=t2.query(a[i]-1);
		suf[i]=qwq-pre[i];
		suf2[i]=qwq+t2.w[a[i]]-1-pre2[i];
	}
	memset(t.a,0,sizeof(t.a));
	for(int i=1;i<=n;i++){
		ls[i]=pre[i]*(pre[i]-1)/2-t.query(a[i]-1);
		t.add(a[i],pre2[i]);
	}
	memset(t.a,0,sizeof(t.a));
	for(int i=n;i;i--){
		rs[i]=suf[i]*(suf[i]-1)/2-t.query(a[i]-1);
		t.add(a[i],suf2[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ls[i]%=mod;
		rs[i]%=mod;
		(ans+=ls[i]*rs[i])%=mod;
	}
	printf("%lld",ans);
}