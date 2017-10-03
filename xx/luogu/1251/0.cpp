#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

const int N=2005,M=1e6+5,INF=1e9;
	
int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}

int n,p,fn,fp,sn,sp,r[N],s,t;
struct edge{
    int v,ne,c,f,w;
}e[M<<1];
int cnt,h[N];

inline void ins(int u,int v,int c,int w){
    cnt++;
    e[cnt].v=v;e[cnt].c=c;e[cnt].f=0;e[cnt].w=w;
    e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].c=0;e[cnt].f=0;e[cnt].w=-w;
    e[cnt].ne=h[v];h[v]=cnt;
}

void build(){
    s=0;t=n+n+1;
    for(int i=1;i<=n;i++){
        ins(s,i,r[i],0);
        ins(i+n,t,r[i],0);
        ins(s,i+n,INF,p);
        if(i+1<=n) ins(i,i+1,INF,0);
        if(i+fn<=n) ins(i,i+n+fn,INF,fp);
        if(i+sn<=n) ins(i,i+n+sn,INF,sp);
    }
}

int d[N],q[N],head,tail,inq[N],pre[N],pos[N];

inline void lop(int &x){if(x==N)x=1;else if(x==0) x==N-1;}

bool spfa(){
    memset(d,127,sizeof(d));
    memset(inq,0,sizeof(inq));
    head=tail=1;
    d[s]=0;inq[s]=1;q[tail++]=s;
    pre[t]=-1;
    while(head!=tail){
        int u=q[head++];inq[u]=0;lop(head);
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v,w=e[i].w;
            if(d[v]>d[u]+w&&e[i].c>e[i].f){
                d[v]=d[u]+w;
                pre[v]=u;pos[v]=i;
                if(!inq[v]){
                    inq[v]=1;
                    if(d[v]<d[q[head]]) head--,lop(head),q[head]=v;
                    else q[tail++]=v,lop(tail);
                }
            }
        }
    }
    return pre[t]!=-1;
}

int mcmf(){
    int flow=0,cost=0;
    while(spfa()){
        int f=INF;
        for(int i=t;i!=s;i=pre[i]) f=min(f,e[pos[i]].c-e[pos[i]].f);
        flow+=f;cost+=d[t]*f;
        for(int i=t;i!=s;i=pre[i]){
            e[pos[i]].f+=f;
            e[((pos[i]-1)^1)+1].f-=f;
        }
    }
    return cost;
}

int main(int argc, const char * argv[]){
    n=read();
    for(int i=1;i<=n;i++) r[i]=read();
	p=read();fn=read();fp=read();sn=read();sp=read();
    build();
    printf("%d",mcmf());
}
