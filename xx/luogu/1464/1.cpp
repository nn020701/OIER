#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
inline LL read(){
	LL x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

LL ans[21][21][21];

LL w(LL a,LL b,LL c){
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(a > 20 || b > 20 || c > 20) return w(20,20,20);
	if(ans[a][b][c] != -1) return ans[a][b][c];
	if(a < b && b < c)
		return ans[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else
		return ans[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main(){
	LL a,b,c;
	memset(ans,-1,sizeof ans);
	while(1){
		a = read(); b = read(); c = read();
		if(a == -1 && b == -1 && c == -1)
			break;
		printf("w(%I64d, %I64d, %I64d) = %I64d\n",a,b,c,w(a,b,c));
	}
	return 0;
}