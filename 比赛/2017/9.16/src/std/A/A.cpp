#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int n,tot,ans,fa[maxn];
struct pp{
	int x,y,z,id;
}a[maxn];
struct edge{
	int u,v,w;
}e[maxn*3];
inline bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
inline bool cmp1(pp a,pp b){return a.x<b.x;}
inline bool cmp2(pp a,pp b){return a.y<b.y;}
inline bool cmp3(pp a,pp b){return a.z<b.z;}
inline int read(){int x=0,f=1; char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();} while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} return x*f;}
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=(pp){read(),read(),read(),i};
	}
	sort(a+1,a+1+n,cmp1);
	for (int i=1;i<n;i++) {
		e[++tot]=(edge){a[i].id,a[i+1].id,abs(a[i].x-a[i+1].x)};
	}
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<n;i++) {
		e[++tot]=(edge){a[i].id,a[i+1].id,abs(a[i].y-a[i+1].y)};
	}
	sort(a+1,a+1+n,cmp3);
	for (int i=1;i<n;i++) {
		e[++tot]=(edge){a[i].id,a[i+1].id,abs(a[i].z-a[i+1].z)};
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+tot,cmp);
	for (int i=1;i<=tot;i++){
		int p=find(e[i].u),q=find(e[i].v);
		if (p!=q){
			fa[p]=q;
			ans+=e[i].w;
			cnt++;
		}
		if (cnt==n-1) break;
	}
	printf("%d\n",ans);
	return 0;
}
