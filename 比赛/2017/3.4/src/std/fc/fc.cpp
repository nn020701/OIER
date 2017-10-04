/*
 * Problem: 
 * Author: Leo Yu
 * Time: 19/04/12 eve
 * State: Coding
 * Memo: ÊýÎ»DP 
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;


inline LL	read()
{
	LL x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')	positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

int	T;
LL	f[20][200], A[200], B[200];
LL	a[20];

inline void	work(LL X, LL ans[])
{
	for (int i = 0; i <= 18 * 9; ++ i)	ans[i] = 0;
	int N;
	for (N = 1; X; ++ N, X /= 10)	a[N] = X % 10;
	N --;
	int last = 0;
	for (int i = N; i; -- i)
	{
		for (int j = 0; j < a[i]; ++ j)
		{
			for (int k = 0; k <= i * 9; ++ k)	if (f[i - 1][k])
				ans[last + j + k] += f[i - 1][k];
		}
		last += a[i];
	}
}

int main()
{
	freopen("fc.in", "r", stdin);
	freopen("fc.out", "w", stdout);

	f[0][0] = 1;
	for (int i = 1; i <= 18; ++ i)
		for (int j = 0; j <= i * 9; ++ j)	if (f[i - 1][j])
			for (int k = 0; k <= 9; ++ k)
				f[i][j + k] += f[i - 1][j];
	
	int T = read();
	while (T --)
	{
		work(read(), A);
		work(read() + 1, B);
		LL	X = read(), ans = 0;
		for (int i = 1; i <= 18 * 9; ++ i)
		{
			LL Y = min(X / i, B[i] - A[i]);
			X -= Y * i;
			ans += Y;
		}
		printf("%I64d\n", ans);
	}

	return 0;
}

