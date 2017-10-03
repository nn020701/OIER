#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

double s,x;
double speed = 7.0;
double len;

int main(){
	scanf("%lf %lf",&s,&x);
	while(1){
		if(len >= s-x){
			if(len+speed > s+x){
				printf("n\n");
				break;
			}
			else{
				printf("y\n");
				break;
			}
		}
		len += speed;
		speed *= 0.98;
	}
	return 0;
}