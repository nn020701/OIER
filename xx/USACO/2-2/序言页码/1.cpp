#include <cstdio>
#include <cstdlib>
#include <cstring>
#define For(i,x,y) for(int i = x; i < y; i++)
#define Sca(x) scanf("%d", &x)
const int N = 3555;
int ans[N][9];
char roma[8] = {"IVXLCDM"};
int mat[] = {0, 1, 2, 3, 11, 10, 11, 12, 13, 101};
int main()
{
	char n[10];
	For(j, 1, 3500) {
		sprintf(n, "%d", j);
		int len = strlen(n);
		for(int i = len-1, k = 0; i >= 0; i--, k++) {
			int x = n[i] - '0'; x = mat[x];
			int s = k << 1;
			int a = x % 10, b = x / 10 % 10, c = x / 100;
			ans[j][s] += a; ans[j][s+1] += b; ans[j][s+2] += c;
		}
	}
	For(i, 0, 7)
		For(j, 1, 3500)
			ans[j][i] += ans[j-1][i];
	int m;
	Sca(m);
	For(i, 0, 7)
		if(ans[m][i])
			printf("%c %d\n", roma[i], ans[m][i]);
	return 0;
}
