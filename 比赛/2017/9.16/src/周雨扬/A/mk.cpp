#include<bits/stdc++.h>
using namespace std;
int rnd(){
	int s=0;
	for (int i=1;i<=9;i++)
		s=s*10+rand()%10;
	return s;
}
int main(){
	freopen("A.in","w",stdout);
	printf("100000\n");
	for (int i=1;i<=100000;i++)
		printf("%d %d %d\n",rnd(),rnd(),rnd());
}
