#include<bits/stdc++.h>
using namespace std;
int rnd(){
	int s=0;
	for (int i=1;i<=4;i++)
		s=s*10+rand()%10;
	return s;
}
int main(){
	srand(time(NULL));
	freopen("c1.in","w",stdout);
	printf("5000 5000\n");
	for (int i=1;i<=5000;i++)
		printf("%d %d %d\n",rnd()%5000+1,rnd()%5000+1,int(rnd()*0.2));
}
