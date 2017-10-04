/*
 * Problem: 
 * Author: Leo Yu
 * Time: 2012-06-29 
 * State: Solved
 * Memo: ’“πÊ¬…
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;


inline int read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')	positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

int	log(int A)
{	
	if (A == 1)	return 0;
	return log((A + 1)/ 2) + 1;
}

int main()
{
	freopen("kniforbare.in", "r", stdin);
	freopen("kniforbare.out", "w", stdout);
	
	int T = read();
	for (int t = 1; t <= T; ++ t)
	{
		//printf("Case #%d: ", t);
		int	A = read(), B = read(), C = read();
		printf("%I64d ", (LL)A * B * C - 1);
		printf("%d\n", log(A) + log(B) + log(C));
	}
	
	return 0;
}

