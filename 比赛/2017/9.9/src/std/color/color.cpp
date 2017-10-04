#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll h, w;
unordered_map<ll, ll> cnt;

inline void Add(ll x, ll y) {
  int dx[9] = {-2, -2, -2, -1, -1, -1, 0, 0, 0}, dy[9] = {-2, -1, 0, -2, -1, 0, -2, -1, 0};
  ll a, b;
  for (int i = 0; i < 9; ++i) {
    a = x + dx[i], b = y + dy[i];
    if (a <= 0 || b <= 0 || a > h - 2 || b > w - 2) {
      continue;
    }
    ++cnt[(h - 2) * (b - 1) + a];
  }
}

ifstream fin("color.in");
ofstream fout("color.out");

int main() {
  int n;
  fin >> h >> w >> n;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    fin >> x >> y;
    Add(x, y);
  }
  ll ans[10] = {0};
  ans[0] = (h - 2) * (w - 2);
  for (auto it : cnt) {
    ans[it.second]++;
    ans[0]--;
  }
  for (int i = 0; i <= 9; ++i) {
    fout << ans[i] << endl;
  }
  return 0;
}
