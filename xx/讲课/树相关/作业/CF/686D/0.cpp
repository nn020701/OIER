#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int maxn = 100000 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;

int n, q, x;
int fa[3*maxn];
int sz[3*maxn];
int ans[3*maxn];
vector<int> G[3*maxn];

void dfs(int u)
{
    sz[u] = 1;
    ans[u] = u;
    int mmax = 0;    //ÖØ¶ù×Ó
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] > sz[mmax])
            mmax = v;
    }
    if (sz[mmax] * 2 > sz[u])
    {
        //printf("2333 %d\n", u);
        int now = ans[mmax];
        while ((sz[u] - sz[now]) * 2 > sz[u])
            now = fa[now];
        ans[u] = now;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        G[fa[i]].push_back(i);
    }
    dfs(1);
    while (q--)
    {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}
