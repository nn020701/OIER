#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
ifstream fin("tree.in");
ofstream fout("tree.out");
long long to[1000003],val[1000003],next[1000003],head[1000003],tot;
inline void add(int a,int b,int c){
	to[++tot]=b;  val[tot]=c;  next[tot]=head[a];  head[a]=tot;
}
int f[600003][23],dis[600003][23],d[600003];
void dfs(int now,int fa){
	f[now][0]=fa;
	for(int i=head[now];i;i=next[i]){
		int x=to[i];
		if(x!=fa){
			d[x]=d[now]+1;
        	f[x][0]=now;
        	dis[x][0]=val[i];
			dfs(x,now);
		}
	}
}
inline int lca(int a,int b){
    if(d[a]>d[b]){
    	swap(a,b);
	}
    int x=d[b]-d[a];
    for(int i=0;(1<<i)<=x;i++){
        if((1<<i)&x){
			b=f[b][i];
    	}
	}
    if(a!=b){
        for(int i=20;i>=0;i--){
            if(f[a][i]!=f[b][i]){
                a=f[a][i]; b=f[b][i];
            }
        }
        a=f[a][0];
    }
    return a;
}
inline int ju(int a,int ca){
	int ret=0;
	for(int i=20;i>=0;i--){
		if(d[ca]<=d[f[a][i]]){
			ret=max(ret,dis[a][i]);
			a=f[a][i];
		}
    }
    return ret;
}
int main(){
	int n,q;
	fin>>n>>q;
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		fin>>u>>v>>w;
		add(u,v,w),add(v,u,w);
	}
	dfs(1,0);
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
			dis[i][j]=max(dis[i][j-1],dis[f[i][j-1]][j-1]);
		}
	}
	long long ans=0;
	while(q--){
		long long op,a,b,u,v;
		fin>>op;
		if(op==1){
			fin>>a>>u>>v;
			a^=ans,u^=ans,v^=ans;
			int ca=lca(u,v);
			int caa=lca(ca,a);
			if(lca(ca,a)==a){
				ans=ju(ca,a);
			}else{
				if(caa!=ca){
					ans=max(ju(ca,caa),ju(a,caa));
				}else{
					ans=min(min(ju(a,lca(a,ca)),ju(a,lca(a,u))),ju(a,lca(a,v)));
				}
			}
			fout<<ans<<endl;
		}else{
			fin>>a>>b;
			a^=ans,b^=ans;
			f[++n][0]=a;
			dis[n][0]=b;
			d[n]=d[a]+1;
			for(int i=1;i<=20;i++){
				f[n][i]=f[f[n][i-1]][i-1];
				dis[n][i]=max(dis[n][i-1],dis[f[n][i-1]][i-1]);
			}
		}
	}
	return 0;
}
/*

in:
10 10
10 1 237837066
7 4 333101381
5 6 764410644
2 9 800406055
2 3 977449294
10 9 85077389
6 8 883423879
7 5 483282546
3 4 109819496
2 2 237524075
1 7 3 2
2 333101376 243353439
2 333101391 970164111
2 333101389 489066126
1 333101377 333101376 333101383
2 5 947013122
2 15 885096691
1 7 9 10
1 977449284 977449286 977449291

out:
333101381
0
977449294
977449294

*/
