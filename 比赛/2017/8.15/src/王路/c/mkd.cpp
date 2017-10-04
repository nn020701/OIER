#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("c.in", "w", stdout);
	srand(time(0));
	int n = 1e3, m = 1e3;
	ios_base::sync_with_stdio(false);
	cout << n << ' ' << m << endl;
	for (int i = 1; i <= m; ++i) {
		cout << rand() % n + 1 << ' ' << rand() % n + 1 << ' ' << rand() % n + 1 << endl;
	}
	return 0;
}
