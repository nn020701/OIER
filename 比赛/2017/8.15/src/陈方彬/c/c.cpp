#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const Ll N=1e5+5;
struct tree{int l,r,v,lazy;}T[N*8];
struct cs{int to,nxt,v;}a[N*2];
struct in{int x,y,z;}c[N];
int q[N],top,p[N];
int head[N],ll;
int n,m,x,y,z,ans;
void make(int id,int l,int r){
	T[id].l=l;T[id].r=r;
	if(l==r)return;
	int mid=l+r>>1;
	make(id*2  ,l,mid  );
	make(id*2+1,mid+1,r);
} 
void down(int id){
	if(T[id].lazy==0)return ;
	int x=id+id,y=x+1;
	T[x].v=T[x].lazy=T[id].lazy;
	T[y].v=T[y].lazy=T[id].lazy;
	T[id].lazy=0;
}
void change(int id,int l,int r,int v){
	down(id);
	if(l<=T[id].l&&T[id].r<=r){T[id].v=v;T[id].lazy=v;return;}
	if(T[id*2  ].r>=l)change(id*2  ,l,r,v);
	if(T[id*2+1].l<=r)change(id*2+1,l,r,v);
}
int out(int id,int k){
	down(id);
	if(T[id].l==T[id].r)return T[id].v;
	if(T[id*2  ].r>=k)return out(id*2,k);return out(id*2+1,k);
}
void init(int x,int y){
	a[++ll].to=y;
	a[ll].nxt=head[x];
	head[x]=ll;
}
bool cmp1(in x,in y){return x.z<y.z;}
int er(int r,int k){
	int l=1,mid,ans=-1;
	while(r>=l){
		mid=l+r>>1;
		if(q[mid]>=k)ans=mid,r=mid-1;else l=mid+1;
	}return ans;
}
void find(int l,int r){
	top=0;
	for(int k=head[c[l].z];k;k=a[k].nxt)q[++top]=a[k].to,p[top]=0;
	sort(q+1,q+top+1);
	for(int i=l;i<=r;i++){
		int k=er(top,c[i].x),kk=k-1;
		if(k==-1)continue;
		for(int j=k;j<=top;j++)
			if(q[j]<=c[i].y)kk=j,p[j]++;else break;
		if(kk==k-1)continue;
		kk=k-1;
		for(int j=k;j<=top;j++)
			if(p[j]<2)p[++kk]=p[j],q[kk]=q[j];else ans++;
		top=kk;
	}
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&m);
	make(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		int l=max(1,x-z);
		int r=min(n,x+z);
		change(1,l,r,y);
		c[i].x=l;c[i].y=r;c[i].z=y;
	}
	for(int i=1;i<=n;i++)init(out(1,i),i);
	sort(c+1,c+m+1,cmp1);
	int last=1;
	for(int i=2;i<=m+1;i++)
		if(c[i].z!=c[i-1].z)find(last,i-1),last=i;
	printf("%d",ans);
}
