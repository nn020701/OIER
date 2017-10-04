#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node{
	int x,y;
};
const int N=310;
const int INF=99999999;
int Stepx[4]={0,1,0,-1};
int Stepy[4]={1,0,-1,0};
int dist[N][N],a[N],b[N],Map[N][N],x[N],y[N];
int len1,len2;
int n,ans,num1,num2;
bool vis[N][N];

int erfen(int x,int l1,int r1,int a[]){
	int l=l1,r=r1;
	int mid;
	while(r>=l){
		mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		if(a[mid]>x) r=mid-1;
		else l=mid+1;
	}
}

int main(){
	freopen("delite.in","r",stdin);
	freopen("delite.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		a[++num1]=x[i]-1; b[++num2]=y[i]-1;
		a[++num1]=x[i];	  b[++num2]=y[i];
		a[++num1]=x[i]+1; b[++num2]=y[i]+1;
	}
	sort(a+1,a+num1+1); sort(b+1,b+num2+1);
	len1=1; len2=1;
	for(int i=2;i<=num1;i++)
		if(a[i]!=a[i-1]) a[++len1]=a[i];
	// printf("%d\n",len1);
	// for(int i=1;i<=len1;i++)
		// printf("%d ",a[i]);
	// puts("");
	for(int i=2;i<=num2;i++)
		if(b[i]!=b[i-1]) b[++len2]=b[i];
	// printf("%d\n",len2);
	// for(int i=1;i<=len2;i++)
		// printf("%d ",b[i]);
	// puts("");
	for(int i=1;i<=n;i++){
		x[i]=erfen(x[i],1,len1,a);
		y[i]=erfen(y[i],1,len2,b);
		 // printf("%d %d\n",x[i],y[i]);
	}
	for(int i=1;i<=n;i++) Map[x[i]][y[i]]=1;
	queue<node> Q;
	node e,v;
	for(int i=1;i<=n;i++){
		while(!Q.empty()) Q.pop();
		int x1=x[i], y1=y[i], x2=x[i%n+1], y2=y[i%n+1];
		memset(dist,0x3f,sizeof dist);
		Map[x1][y1]=0; Map[x2][y2]=0;
		dist[x1][y1]=0;
		e.x=x1; e.y=y1;
		Q.push(e);
		while(!Q.empty()){
			v=Q.front(); Q.pop();
			vis[v.x][v.y]=0;
			for(int k=0;k<=3;k++){
				int tx=v.x+Stepx[k], ty=v.y+Stepy[k];
				if(tx>0&&ty>0&&tx<=len1&&ty<=len2&&!Map[tx][ty]){
					int dis=abs(a[v.x]-a[tx])+abs(b[v.y]-b[ty]);
					if(dist[tx][ty]>dist[v.x][v.y]+dis){
						dist[tx][ty]=dist[v.x][v.y]+dis;
						if(!vis[tx][ty]){
							e.x=tx; e.y=ty;
							Q.push(e);
							vis[tx][ty]=true;
						}
					}
				}
					
			}
		}
		Map[x1][y1]=1; Map[x2][y2]=1;
		if(dist[x2][y2]>INF){
			printf("-1\n");
			return 0;
		}
		ans+=dist[x2][y2];
	}
	printf("%d\n",ans);
	return 0;
}