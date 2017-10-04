#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("b.in", "w", stdout);
	int n = 300, m = 300; srand(time(0));
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; i++, puts(""))for(int j = 1; j <= m; j++){
		printf("%d ", rand()&1);
	}
}