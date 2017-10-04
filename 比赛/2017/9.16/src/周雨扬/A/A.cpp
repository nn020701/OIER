#include<bits/stdc++.h>
#define N 100005
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
	int x=0,f=1;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x*f;
}
struct P{int x,y,z,id;}p[N];
struct E{int x,y,z;}e[N*3];
int n,tot,f[N];
long long ans;
inline bool cmpx(const P& a,const P& b){
	return a.x<b.x;
}
inline bool cmpy(const P& a,const P& b){
	return a.y<b.y;
}
inline bool cmpz(const P& a,const P& b){
	return a.z<b.z;
}
inline bool cmp(const E& a,const E& b){
	return a.z<b.z;
}
inline int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)
		p[i].x=read(),p[i].y=read(),p[i].z=read(),p[i].id=i;
	sort(p+1,p+n+1,cmpx);
	for (int i=1;i<n;i++)
		e[++tot]=(E){p[i].id,p[i+1].id,p[i+1].x-p[i].x};
	sort(p+1,p+n+1,cmpy);
	for (int i=1;i<n;i++)
		e[++tot]=(E){p[i].id,p[i+1].id,p[i+1].y-p[i].y};
	sort(p+1,p+n+1,cmpz);
	for (int i=1;i<n;i++)
		e[++tot]=(E){p[i].id,p[i+1].id,p[i+1].z-p[i].z};
	for (int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+tot+1,cmp);
	for (int i=1;i<=tot;i++){
		int x=get(e[i].x),y=get(e[i].y);
		if (x!=y) ans+=e[i].z,f[x]=y;
	}
	printf("%lld",ans);
}
