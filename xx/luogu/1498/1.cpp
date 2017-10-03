#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define N 20005
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int n;
int h;
string a[3000];

int main(){
	h = 2; n = read();
	a[1] = " /\\ ";
	a[2] = "/__\\";
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= h;j++)
			a[j+h] = a[j]+a[j];
		for(int j = 1;j <= h;j++)
			for(int k = 1;k <= h;k++)
				a[j] = ' ' + a[j] + ' ';
		h <<= 1;
	}
	for(int i = 1;i <= h;i++)
		cout<<a[i]<<endl;
	return 0;
}