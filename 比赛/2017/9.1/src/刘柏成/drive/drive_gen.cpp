#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	int n=3000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%100+1);
}