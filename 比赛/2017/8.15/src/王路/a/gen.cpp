#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define Rand() ((rand() << 15) + rand())

int main() {
	freopen("a.in", "w", stdout);
	ios_base::sync_with_stdio(false);
	srand(time(0));
	int n = 1000, W = 1e6;
	cout << n << ' ' << W << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << rand() << ' ';
		}
		cout << endl;
	}
	return 0;
}
