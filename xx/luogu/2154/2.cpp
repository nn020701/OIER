#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define P 2147483648LL
using namespace std;

int n,m,w,K,H[200001];
ll c[100001][11],tr[200001],ans;
struct data{int x,y;}a[100005];
int h[200001],l[200001];
int now[200001];

int find(int x){
	int l=1,r=2*w,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(H[mid]<x)l=mid+1;
		else if(H[mid]>x)r=mid-1;
		else return mid;
	}
}

void getc(){
	c[0][0]=1;
	for(int i=1;i<=w;i++){
		c[i][0]=1;
		for(int j=1;j<=min(K,i);j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
	}
}

int lowbit(int x){return x&(-x);}

void update(int x,int y){
	while(x<=2*w){
		tr[x]+=y;tr[x]%=P;
		x+=lowbit(x);
	}
}

ll ask(int x){
	ll s=0;
	while(x){
		s+=tr[x];s%=P;
		x-=lowbit(x);
	}
	return s;
}

inline bool cmp(data a,data b){
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}

int main(){
	scanf("%d%d%d",&m,&n,&w);
	for(int i=1;i<=w;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		H[2*i-1]=a[i].x;
		H[2*i]=a[i].y;
	}
	scanf("%d",&K);getc();
	sort(H+1,H+2*w+1);
	for(int i=1;i<=w;i++){
		h[find(a[i].y)]++;
		l[find(a[i].x)]++;
	}
	sort(a+1,a+w+1,cmp);
	int lf;
	for(int i=1;i<=w;i++){
		if(i>1&&a[i].y==a[i-1].y){
			lf++;
			ll t1=ask(find(a[i].x)-1)-ask(find(a[i-1].x));
			ll t2=c[lf][K]*c[h[find(a[i].y)]-lf][K];
			ans+=t1*t2;
			ans%=P;
		}
		else lf=0;
		int d=find(a[i].x);now[d]++;
		int change=(c[now[d]][K]*c[l[d]-now[d]][K]-c[now[d]-1][K]*c[l[d]-now[d]+1][K])%P;
		update(d,change);
	}
	if(ans<0)ans+=P;
	printf("%d",ans);
	return 0;
}