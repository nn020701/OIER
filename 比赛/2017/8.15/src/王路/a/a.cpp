#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

const int MaxN = 1005;
const long long inf = 1e16;

#define int long long

long long a[MaxN][MaxN], dis1[MaxN][MaxN], dis2[MaxN][MaxN];

long long n, W;

#define Calc(x, y, len) (x + len - 1 > n || y + len - 1 > n) ? (inf) : (dis1[x + len - 1][y + len - 1] - dis1[x - 1][y - 1] + dis2[x + len - 1][y] - dis2[x - 1][y + len] - ((len & 1) ? a[x + (len >> 1)][y + (len >> 1)] : 0))

signed main() {
	fin >> n >> W;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			fin >> a[i][j];
			dis1[i][j] = dis1[i - 1][j - 1] + a[i][j];
			dis2[i][j] = dis2[i - 1][j + 1] + a[i][j];
		}
	}
	//
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = ans + 1; l <= n; ++l) {
				long long temp = Calc(i, j, l);
				if (temp <= W) {
					ans = l;
			 	} else if (temp >= inf) {
					break;
				}
			}
		}
	}
	// cout << clock() << endl;
	// cout << cnt << endl;
	// cout << ans << endl;
	// cout << a << ' ' << b << ' ' << c << endl;
	// cout << Calc(a, b, c) << endl;
	fout << ans << endl;
	return 0;
}
