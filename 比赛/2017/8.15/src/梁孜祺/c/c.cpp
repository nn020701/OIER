#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define N 100005
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
int n,m,f[N<<1],a[N],p[N],sum;
inline int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
struct data{int l,r;};
vector <data> gg[N];
struct dddd{
	int l,r,x;
	bool operator <(const dddd& a)const{
		return (l==a.l)?r<a.r:l<a.l;
	}
}b[N];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();m=read();
	For(i,1,m){
		int x=read(),l=read(),k=read();
		b[i]=(dddd){max(x-k,1),min(x+k,n),l};
	}
	For(i,1,n<<1) f[i]=i;
	Rep(i,m,1){
		int l=b[i].l,r=b[i].r;
		for(int j=find(l);j<=r;j=find(j)){
			a[j]=b[i].x;f[j]=f[j]+1;
		}
	}
	For(i,1,n) if(!a[i]) sum++;
	sort(b+1,b+1+m);
	For(i,1,m){
		int l=b[i].l,r=b[i].r,x=b[i].x;
		gg[x].push_back((data){l,r});
	}
	For(i,1,n) if(a[i]){
		int l=0,r=gg[a[i]].size()-1,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(gg[a[i]][mid].l<=i) ans=mid,l=mid+1;
			else r=mid-1;
		}
		l=0;r=gg[a[i]].size()-1;
		if((ans+1<=r&&gg[a[i]][ans+1].l<=i&&gg[a[i]][ans+1].r>=i)||(ans-1>=0&&gg[a[i]][ans-1].l<=i&&gg[a[i]][ans-1].r>=i)) sum++;
	}
	printf("%d",sum);
	return 0;
}
