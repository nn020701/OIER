#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
ifstream fin("c.in");
ofstream fout("c.out");
int n,m;
struct person{
	int x,l,k,pos;
}num[100003];
struct xx{
	int pos,val;
}num2[100003];
inline bool cmp(const person a,const person b){
	if(a.l==b.l){
		return a.pos<b.pos; 
	}
	return a.l<b.l;
}
inline bool cmp2(const xx a,const xx b){
	if(a.val==b.val){
		return a.pos<b.pos;
	}
	return a.val<b.val;
}
struct seg{
	int val;
}t[400003];
inline void pushdown(int rt){
	if(t[rt].val!=-1){
		t[rt*2].val=t[rt].val;
		t[rt*2+1].val=t[rt].val;
	}
}
void build(int rt,int l,int r){
	t[rt].val=0;
	if(l==r){
		return;
	}
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
}
void rev(int rt,int l,int r,int x,int y,int val){
	if(l==x&&r==y){
		t[rt].val=val;
		return;
	}
	pushdown(rt);
	t[rt].val=-1;
	int mid=(l+r)/2;
	if(y<=mid){
		rev(rt*2,l,mid,x,y,val);
	}else if(x>mid){
		rev(rt*2+1,mid+1,r,mid+1,y,val);
	}else{
		rev(rt*2,l,mid,x,mid,val);
		rev(rt*2+1,mid+1,r,mid+1,y,val);
	}
}
int query(int rt,int l,int r,int pos){
	if(l==r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(l+r)/2;
	if(pos>mid){
		return query(rt*2+1,mid+1,r,pos);
	}else{
		return query(rt*2,l,mid,pos);
	}
}
struct segment{
	int sum;
}tt[400003];
inline void pushdown2(int rt){
	tt[rt*2].sum+=tt[rt].sum;
	tt[rt*2+1].sum+=tt[rt].sum;
}
void build2(int rt,int l,int r){
	tt[rt].sum=0;
	if(l==r){
		return;
	}
	int mid=(l+r)/2;
	build2(rt*2,l,mid);
	build2(rt*2+1,mid+1,r);
}
void rev2(int rt,int l,int r,int x,int y,int val){
	if(l==x&&r==y){
		tt[rt].sum+=val;
		return;
	}
	int mid=(l+r)/2;
	if(y<=mid){
		rev2(rt*2,l,mid,x,y,val);
	}else if(x>mid){
		rev2(rt*2+1,mid+1,r,x,y,val);
	}else{
		rev2(rt*2,l,mid,x,mid,val);
		rev2(rt*2+1,mid+1,r,mid+1,y,val);
	}
}
int query2(int rt,int l,int r,int pos){
	if(l==r){
		return tt[rt].sum;
	}
	pushdown2(rt);
	int mid=(l+r)/2;
	if(pos>mid){
		return query2(rt*2+1,mid+1,r,pos);
	}else{
		return query2(rt*2,l,mid,pos);
	}
}
int xx[100003],tong[100003];
bool yes[10003][10003];
int sta[100003],end[100003];
int main(){
	fin>>n>>m;
	for(int i=1;i<=m;i++){
		fin>>num[i].x>>num[i].l>>num[i].k;
		num[i].pos=i;
	}
	if(n<=10000&&m<=10000){
		for(int i=1;i<=n;i++){
			xx[i]=1;
		}
		for(int i=1;i<=m;i++){
			for(int k=max(1,num[i].x-num[i].k);k<=min(n,num[i].x+num[i].k);k++){
				if(yes[k][num[i].l]==true){
					xx[k]=1;
				}else{
					yes[k][num[i].l]=true;
					xx[k]=0;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=xx[i];
		}
		fout<<ans<<endl;
		return 0;
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		rev(1,1,n,max(1,num[i].x-num[i].k),min(n,num[i].x+num[i].k),num[i].l);
	}
	for(int i=1;i<=n;i++){
		num2[i].pos=i;
		num2[i].val=query(1,1,n,i);
	}
	sort(num+1,num+m+1,cmp);
	sort(num2+1,num2+n+1,cmp2);
	build2(1,1,n);
	int ans=0;
	int sta[100003],end[100003];
	for(int i=1;i<=n;i++){
		int l=i;
		while(num2[i].val==num2[l].val){
			l++;
		}
		sta[num2[i].val]=i;
		end[num2[i].val]=l-1;
		i=l-1;
	}
	for(int i=1;i<=m;i++){
		int l=sta[num[i].l],r=end[num[i].l];
		int xx=max(1,num[i].x-num[i].k);
		while(l<r){
			int mid=(l+r)/2;
			if(num2[mid].pos>xx){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		int ll=l;
		l=sta[num[i].l],r=end[num[i].l];
		xx=min(n,num[i].x+num[i].k);
		while(l<r){
			int mid=(l+r)/2;
			if(num2[mid].pos<xx){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		int rr=l;
		if(ll<=rr){
			rev2(1,1,n,ll,rr,1);
		}
	}
	for(int i=1;i<=n;i++){
		if(query2(1,1,n,i)>=2){
			ans++;
		}
	}
	fout<<ans<<endl;
	return 0;
}
/*

in:
10 7
3 11 0
3 11 2
5 12 1
8 13 2
7 11 2
10 12 1
9 12 0

out:
3

*/
