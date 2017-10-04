#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

#define EMIT_INLINE __attribute__((__always_inline__))

const int N = 100005, M = 105, Mod = 1000000007;
int n, m;
char ch;

template<class _Tp, size_t n>
class Matrix {
    typedef _Tp        value_type;
public:
  inline EMIT_INLINE Matrix(bool flag = false) {
      memset(a, 0, sizeof a);
      for (int i = 0; i <= m; i++)
          a[i][i] = flag;
  }

  inline friend Matrix operator * (const Matrix &a, const Matrix &b) {
      Matrix res;
      for (int i = 0; i <= m; i++)
          for (int j = 0; j <= m; j++)
              for (int k = 0; k <= m; k++)
                  res.a[i][j] = (res.a[i][j] + (long long)a.a[i][k] * b.a[k][j] % Mod) % Mod;
      return res;
  }

  inline EMIT_INLINE friend void operator *= (Matrix &a, const Matrix &b) {
      a = a * b;
  }

  inline friend Matrix quickpow(Matrix a, value_type k) {
      Matrix res(true);
      for (; k; k >>= 1, a *= a)
          if (k & 1) res *= a;
      return res;
  }

  inline EMIT_INLINE value_type& operator()(int i, int j) {
    return a[i][j];
  }
  
  value_type a[n][n];
};

typedef Matrix<int, M> matrix_type;

ifstream fin("flower.in");
ofstream fout("flower.out");

matrix_type mat, res;

int main() {
  fin >> n >> m;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      fin >> ch;
      mat(i, j) = (ch == '0');
    }
  for (int i = 0; i <= m; i++)
    mat(i, 0) = mat(0, i) = 1;
  mat = quickpow(mat, n);
  res = mat;
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans = (ans + res(0, i)) % Mod;
  }
  fout << ans << endl;
  return 0;
}
