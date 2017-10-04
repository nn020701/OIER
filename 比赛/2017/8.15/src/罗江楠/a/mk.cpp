#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("a.in", "w", stdout); srand(time(0));
	int n = 1000, w = 1000000000;
	printf("%d %d\n", n, w);
	for(int i = 1; i <= n; i++, puts(""))
	for(int j = 1; j <= n; j++) printf("%d ", rand()*rand()%10000000);
}
