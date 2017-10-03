#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int num[100],top;

void jinzhi(int x,int k){
	while(x){
		num[++top] = x%k;
		x /= k;
	}
	return;
}

bool check(){
	for(int l = 1,r = top;l < r;l++,r--){
		if(num[l] != num[r]) return false;
	}
	return true;
}

int main(){
	int k = 0;
	int n = read(),m = read();
	while(k < n){
		m++; int opt = 0;
		for(int i = 2;i <= 10;i++){
			top = 0;
			jinzhi(m,i);
			if(check()) opt++;
		}
		if(opt >= 2) printf("%d\n",m),k++;
	}
	return 0;
}
