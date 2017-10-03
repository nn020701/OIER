#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 1005
#define eps 1e-6
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int n;
int y[N];
bool flag[N];
double z,p;

inline double Abs(double a){
	if(a < 0) return -a;
	return a;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		y[i] = read();
	for(int i = 2;i <= n;i++){
		memset(flag,false,sizeof flag);
		z = (double)(y[i]-y[1])/(double)(i-1);
		flag[i] = true;
		for(int j = 2;j <= n;j++){
			p = (double)(y[j]-y[1])/(double)(j-1);
			if(Abs(p-z) < eps){
				flag[j] = true;
			}
		}
		int b = 2;
		bool fp = false;
		while(b <= n && flag[b]) b++;
		if(b == n+1) continue;
		for(int j = b+1;j <= n;j++)
			if(!flag[j]){
				p = (double)(y[j]-y[b])/(double)(j-b);
				if(Abs(p-z) > eps){
					fp = true;
					break;
				}
			}
		if(fp) continue;
		printf("Yes\n");
		return 0;
	}
	int a = y[3]-y[2];
	for(int i = 4;i <= n;i++){
		p = y[i]-y[i-1];
		if(a != p){
			printf("No\n");
			return 0;
		}
	}
	if(y[2]-y[1] == a){
		printf("No\n");
	}
	else printf("Yes\n");
	return 0;
}