#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

#define int long long

const int MaxN = 1005;
const long long inf = 1e16;

long long a[MaxN][MaxN], dis1[MaxN][MaxN], dis2[MaxN][MaxN];

long long n, W;

inline long long Calc(int x, int y, int len) {
	if (x + len - 1 > n || y + len - 1 > n) {
		return inf;
	}
	long long res = dis1[x + len - 1][y + len - 1] - dis1[x - 1][y - 1] + dis2[x + len - 1][y] - dis2[x - 1][y + len];
	if (len & 1) {
		res -= a[x + (len >> 1)][y + (len >> 1)];
	}
	return res;
}

inline long long Calc1(int x, int y, int len) {
	if (x + len - 1 > n || y + len - 1 > n || y - len + 1 <= 0 || x - len + 1 <= 0) {
		return inf;
	}
	return dis1[x + len - 1][y + len - 1] - dis1[x - len][y - len] + dis2[x + len - 1][y - len + 1] - dis2[x - len + 1][y - len] - a[x][y];
}

signed main() {
	fin >> n >> W;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			fin >> a[i][j];
			dis1[i][j] = dis1[i - 1][j - 1] + a[i][j];
			dis2[i][j] = dis2[i - 1][j + 1] + a[i][j];
		}
	}
	int ans = 0;
	// Even
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int l = 1, r = n, res = n;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (Calc(i, j, mid) <= W) {
					l = mid + 1;
					res = mid;
				} else {
					r = mid - 1;
				}
			}
			ans = max(ans, res);
		}
	}
	// Odd
	/*
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int l = 1, r = n, res = r;
			while (l <= r) { 
				int mid = (l + r) / 2;
				if (Calc1(i, j, mid) <= W) {
					l = mid + 1;
					res = mid;
				} else {
					r = mid - 1;
				}
			}
			ans = max(ans, res * 2 - 1);
		}
	}
	*/
	fout << ans << endl;
	return 0;
}
