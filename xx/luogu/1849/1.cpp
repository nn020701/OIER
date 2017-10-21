#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 1005
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int step_x[4] = {0,0,1,-1};
const int step_y[4] = {1,-1,0,0};
int mp[N][N];
int dist[N][N];
bool vis[N][N];
int n,stx,sty;
struct node{
    int x,y;
};
queue<node> q;

inline bool pd(int x,int y){
    if(x >= 0 && y >= 0 && x <= 1001 && y <= 1001)
        return true;
    return false;
}

inline void spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[stx][sty] = 0;
    q.push((node){stx,sty});
    while(!q.empty()){
        node u = q.front(); q.pop();
        vis[u.x][u.y] = false;
        for(int k = 0;k < 4;k++){
            int xx = u.x+step_x[k];
            int yy = u.y+step_y[k];
            if(pd(xx,yy) && dist[xx][yy] > dist[u.x][u.y]+mp[xx][yy]){
                dist[xx][yy] = mp[xx][yy]+dist[u.x][u.y];
                if(vis[xx][yy]) continue;
                vis[xx][yy] = true;
                q.push((node){xx,yy});
            }
        }
    }
}

int main(){
    n = read(); stx = read(); sty = read();
    for(int i = 1;i <= n;i++){
        int x = read(),y = read();
        mp[x][y] = 1;
    }
    spfa();
    printf("%d\n", dist[1][1]);
    return 0;
}