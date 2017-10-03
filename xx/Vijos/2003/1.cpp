#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

string name[N];
int Scarlet[N];
int n,m;
int ans = 0;

int main(){
	n = read(); m = read();
	for(int i = 0;i < n;i++){
		Scarlet[i] = read();
		cin >> name[i]; 
	}
	for(int i = 1;i <= m;i++){
		int scarlet = read();
		int Remililia = read();
		if(scarlet ^ Scarlet[ans]){
			ans = (ans + Remililia) % n;
		}
		else{
			ans = (ans - Remililia + n) % n;
		}
	}
	cout << name[ans] << endl;
	return 0;
}