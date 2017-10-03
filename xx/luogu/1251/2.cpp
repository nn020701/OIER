#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 0x7fffffff
#define T 20001
#define ll long long
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll cnt=1,day,p,m,f,n,s,ans;
ll from[20005],q[20005],dis[20005],head[20005];
bool inq[20005];
struct data{ll from,to,next,v,c;}e[2000001];

void ins(ll u,ll v,ll w,ll c){
	cnt++;
	e[cnt].from=u;e[cnt].to=v;
	e[cnt].v=w;e[cnt].c=c;
	e[cnt].next=head[u];head[u]=cnt;
}

void insert(ll u,ll v,ll w,ll c)
{ins(u,v,w,c);ins(v,u,0,-c);}

bool spfa(){
	for(ll i=0;i<=T;i++)dis[i]=inf;
	ll t=0,w=1,i,now;
	dis[0]=q[0]=0;inq[0]=1;
	while(t!=w){
		now=q[t];t++;if(t==20001)t=0;
		for(ll i=head[now];i;i=e[i].next){
			if(e[i].v&&dis[e[i].to]>dis[now]+e[i].c){
				from[e[i].to]=i;
				dis[e[i].to]=dis[now]+e[i].c;
				if(!inq[e[i].to]){
					inq[e[i].to]=1;
					q[w++]=e[i].to;
					if(w==20001)w=0;
				}
			}
		}
		inq[now]=0;
	}
	if(dis[T]==inf)return 0;return 1;
}

void mcf(){
	ll i,x=inf;
	i=from[T];
	while(i){
		x=min(e[i].v,x);
		i=from[e[i].from];
	}
	i=from[T];
	while(i){
		e[i].v-=x;
		e[i^1].v+=x;
		ans+=x*e[i].c;
		i=from[e[i].from];
	}
}

int main(){
	day = read();
	ll x;
	for(ll i=1;i<=day;i++){
		x = read();
		insert(0,i,x,0);
		insert(day+i,T,x,0);
	}
	p = read();
	m = read(); f = read();
	n = read(); s = read();
	for(ll i=1;i<=day;i++){
		if(i+1<=day)insert(i,i+1,inf,0);
		if(i+m<=day)insert(i,day+i+m,inf,f);
		if(i+n<=day)insert(i,day+i+n,inf,s);
		insert(0,day+i,inf,p);
	}
	while(spfa())mcf();
	printf("%lld",ans);
	return 0;
}
