#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int n, m;

const int MaxN = 305;

int a[MaxN][MaxN], c[MaxN][MaxN][10];

int main() {
	fin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			fin >> a[i][j];
			for (int k = 0; k < 10; ++k) {
				c[i][j][k] = c[i - 1][j][k] + c[i][j - 1][k] - c[i - 1][j - 1][k] + (a[i][j] == k);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int i1 = i; i1 <= n; ++i1) {
				for (int j1 = j; j1 <= m; ++j1) {
					int sum = 0;
					for (int ii = 0; ii < 10; ++ii) {
						if ((c[i1][j1][ii] - c[i1][j - 1][ii] - c[i - 1][j1][ii] + c[i - 1][j - 1][ii]) & 1) { 
							sum++;
						}
					}
					if (sum <= 1) {
						ans = max(ans, (i1 - i + 1) * (j1 - j + 1));
					}
				}
			}
		}
	}
	fout << ans << endl;
	return 0;
}
