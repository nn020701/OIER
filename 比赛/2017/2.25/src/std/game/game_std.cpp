#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 1000005
#define INF 1000000000
using namespace std;
int n, num[N], a[N], b[N], ffmin[N][20], ffmax[N][20];
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
void format()
{
    for (int i = 1; i <= n; ++i) ffmin[i][0] = ffmax[i][0] = num[i];
    for (int j = 1, p = 1; j < 20; ++j, p <<= 1)
        for (int i = 1; i + p * 2 - 1 <= n; ++i)
        {
            ffmin[i][j] = min(ffmin[i][j - 1], ffmin[i + p][j - 1]);
            ffmax[i][j] = max(ffmax[i][j - 1], ffmax[i + p][j - 1]);
        }
}
int getmin(int left, int right)
{
    int len = (int)(log(right - left + 1) / log(2) + 1e-6);
    return min(ffmin[left][len], ffmin[right - (1 << len) + 1][len]);
}
int getmax(int left, int right)
{
    int len = (int)(log(right - left + 1) / log(2) + 1e-6);
    return max(ffmax[left][len], ffmax[right - (1 << len) + 1][len]);
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
    for (int i = 1; i <= n; ++i) a[i] = b[i] = i;
    num[0] = num[n + 1] = INF;
    format();
    for (int i = 1; i <= n; ++i)
        while (num[a[i] - 1] <= num[i]) a[i] = a[a[i] - 1];
    for (int i = n; i >= 1; --i)
        while (num[b[i] + 1] <= num[i]) b[i] = b[b[i] + 1];
    for (int i = 1; i <= n; ++i)
        if ((a[i] == i) || (b[i] == i)) puts("-1");
        else printf("%d\n", max(iabs(getmax(a[i], i - 1) - getmin(i + 1, b[i])), iabs(getmax(i + 1, b[i]) - getmin(a[i], i - 1))));
    return 0;
}


