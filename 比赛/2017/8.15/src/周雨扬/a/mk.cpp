#include<bits/stdc++.h>
using namespace std;
int rnd(){
	int s=0;
	for (int i=1;i<=6;i++)
		s=s*10+rand()%10;
	return s;
}
int main(){
	srand(time(NULL));
	freopen("a.in","w",stdout);
	printf("100 40000000\n");
	for (int i=1;i<=100;i++){
		for (int j=1;j<=100;j++) printf("%d ",rnd());
		puts("");
	}
}
