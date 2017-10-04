#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("C.in","w",stdout);
	for (int i=1;i<=100;i++){
		for (int j=1;j<=100;j++)
			printf("%d",rand()%10);
		puts("");
	}
}
