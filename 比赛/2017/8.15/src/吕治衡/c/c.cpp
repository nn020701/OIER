#include<bits/stdc++.h>
using namespace std;
struct lsg{int x,l,r,t;}a[1000000],q[10000000];
int lazy[1000000],sum[1000000],n,m,x,y,kk;
bool f[1000000],ff;
void putit(int x,int y,int t,int z,int l,int r,int d){
		f[d*2]&=f[d];f[d*2+1]&=f[d];
		if (x<=l&&y>=r&&!((f[d*2]||f[d*2+1])&&ff)){
			if (t!=0){
					q[++kk].t=t;q[kk].l=l;q[kk].r=r;
					q[kk].x=lazy[d]==z?2:1;
				}
			lazy[d]=z;if (z==1)sum[d]=r-l+1;else sum[d]=0;
			f[d]=true;return;
		}
		int m=(l+r)/2;
		if (lazy[d]){
				putit(l,m,0,lazy[d],l,m,d*2);
				putit(m+1,r,0,lazy[d],m+1,r,d*2+1);
				lazy[d]=0;
			}
		if (x<=m)putit(x,y,t,z,l,m,d*2);
		if (y>m)putit(x,y,t,z,m+1,r,d*2+1);
		sum[d]=sum[d*2]+sum[d*2+1];f[d]=f[d*2]|f[d*2+1];
	}
bool pd(lsg x,lsg y){return x.x<y.x||x.x==y.x&&x.t<y.t;}
bool pd1(lsg x,lsg y){return x.t<y.t;}
void outit(int l,int r,int d,int x){
		if (l==r){
				cout<<(x==0?lazy[d]:x%2)<<' ';
				return;
			}
		if (x==0)outit(l,(l+r)/2,d*2,lazy[d]),outit((l+r)/2+1,r,d*2+1,lazy[d]);
			else outit(l,(l+r)/2,d*2,x),outit((l+r)/2+1,r,d*2+1,x);
	}
int main(){
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;for (int i=1;i<=m;i++){
			cin>>x>>a[i].x>>y;a[i].t=i;
			a[i].l=max(1,x-y);a[i].r=min(n,x+y);
		}
	sort(a+1,a+1+m,pd);ff=true;
	for (int i=1;i<=m;i++){
			if (a[i].x!=a[i-1].x)lazy[1]=2,sum[1]=0,f[1]=0;
			putit(a[i].l,a[i].r,a[i].t,1,1,n,1);
		}ff=false;
	lazy[1]=2;sum[1]=0;f[1]=0;sort(q+1,q+1+kk,pd1);
	for (int i=1;i<=kk;i++)putit(q[i].l,q[i].r,0,q[i].x,1,n,1);
	cout<<n-sum[1]<<endl;
//	outit(1,n,1,0);
}
