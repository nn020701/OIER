#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 505
inline int read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
    return x*f;
}

const int step_x[4] = {-1,0,1,0};
const int step_y[4] = {0,-1,0,1};
int n,m;
int high[N][N];
bool flag[N][N];
bool pd[N];
bool vis[N][N];
struct node{
    int l,r;
    friend bool operator <(node a,node b){
        return a.l < b.l || (a.l == b.l && a.r < b.r);
    }
}xian[N];
int f[N];
int qux[N*N],quy[N*N],head,tail;

void Bfs(){
    head = 0; tail = 0;
    for(int i = 1;i <= m;i++){
        qux[++tail] = 1;
        quy[tail] = i;
        vis[1][i] = true;
    }
    while(head < tail){
        int ux = qux[++head];
        int uy = quy[head];
        for(int i = 0;i < 4;i++){
            int x = ux+step_x[i];
            int y = uy+step_y[i];
            if(x > 0 && x <= n && y > 0 && y <= m && !vis[x][y] && high[ux][uy] > high[x][y]){
                qux[++tail] = x;
                quy[tail] = y;
                vis[x][y] = true;
            }
        }
    }
}

void bfs(int xx){
    memset(vis,0,sizeof vis);
    vis[1][xx] = true;
    head = 0; tail = 0;
    qux[++tail] = 1;
    quy[tail] = xx;
    while(head < tail){
        int ux = qux[++head];
        int uy = quy[head];
        if(ux == n)
            flag[xx][uy] = true;
        for(int i = 0;i < 4;i++){
            int x = ux+step_x[i];
            int y = uy+step_y[i];
            if(x > 0 && x <= n && y > 0 && y <= m && !vis[x][y] && high[ux][uy] > high[x][y]){
                qux[++tail] = x;
                quy[tail] = y;
                vis[x][y] = true;
            }
        }
    }
}

int main(){
    n = read(); m = read();
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            high[i][j] = read();
    Bfs();
    int ans = 0;
    for(int i = 1;i <= m;i++)
        if(vis[n][i])
            ans++;
    if(ans < m){
        printf("0\n%d\n",m-ans);
        return 0;
    }
    for(int i = 1;i <= m;i++)
        bfs(i);
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++)
            if(flag[i][j]){
                xian[i].l = j;
                break;
            }
        if(xian[i].l == 0){
            xian[i].l = m+1;
            xian[i].r = m+1;
            continue;
        }
        for(int j = xian[i].l+1;j <= m;j++)
            if(!flag[i][j]){
                xian[i].r = j-1;
                break;
            }
        if(xian[i].r == 0)
            xian[i].r = m;
    }
    // for(int i = 1;i <= m;i++)
        // printf("%d %d\n",xian[i].l,xian[i].r);
    sort(xian+1,xian+m+1);

    memset(f,0x3f,sizeof f);
    f[0] = 0;
    for(int i = 1;i <= m;i++)
        for(int j = xian[i].l;j <= xian[i].r;j++)
            f[j] = min(f[j],f[xian[i].l-1]+1);
    printf("1\n%d\n",f[m]);
    return 0;
}