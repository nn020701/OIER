#include <fstream>
#include <iostream>
#include <set>
using namespace std;

ifstream fin("c.in");
ofstream fout("c.out");

int n, m;

const int MaxN = 1e5;

set<int> S[MaxN];
bool vis[MaxN];

int main() {
	fin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int x, l, k;
		fin >> x >> l >> k;
		for (int j = max(x - k, 1); j <= min(x + k, n); ++j) {
			int p = S[j].count(l);
			if (p == 0) {
				S[j].insert(l);
				vis[j] = true;
			} else if (p == 1) {
				vis[j] = false;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += (!vis[i]);
	}
	fout << res << endl;
	return 0;
}
