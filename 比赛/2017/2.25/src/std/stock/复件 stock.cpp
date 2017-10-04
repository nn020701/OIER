#include <iostream>
#include <cstdio>
#include <cstring>
#define N 256
using namespace std;
bool mat[N][N];
int a[N*N], b[N*N], la, lb, n, m;
int main()
{
    freopen("stock.in", "r", stdin);
    freopen("stock.out", "w", stdout);
    int ca = 0, x, y;
    scanf("%d%d", &n, &m);
    memset(mat, 0, sizeof(mat));
    int res = 0;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        if ((x == y) || mat[y][x]) ++res;
        else
        {
            la = lb = 1; a[1] = x; b[1] = y;
            for (int l = 1; l <= n; ++l)
                if (mat[l][x] && !mat[l][y]) a[++la] = l;
            for (int l = 1; l <= n; ++l)
                if (!mat[x][l] && mat[y][l]) b[++lb] = l;
            for (int l = 1; l <= la; ++l)
                for (int r = 1; r <= lb; ++r)
                    mat[a[l]][b[r]] = 1;
        }
    }
    printf("%d\n", res);
    return 0;
}


