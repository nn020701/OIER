//85分
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 7100005
inline int read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f = -1;ch = getchar();}
    while(ch>='0' && ch<='9'){x = x*10+ch-'0';ch = getchar();}
    return x*f;
}
inline void write(int x){
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int q,n,m,u,v,t;
int add;
double p;
struct heap{
	int num[N],len;
	heap(){
		len = 0;
	}

	void push(int x){
		num[++len] = x;
		int a = len;
		while(a > 1 && num[a] > num[a >> 1]){
			swap(num[a],num[a >> 1]);
			a >>= 1;
		}
	}

	void pop(){
		num[1] = num[len--];
		int a = 1,b = 2,c = 3;
		while(b <= len){
			if(c <= len)
				if(num[c] > num[b])
					b = c;
			if(num[b] > num[a]){
				swap(num[b],num[a]);
				a = b;
			}
			else break;
			b = a << 1; c = a << 1|1;
		}
	}

}que;


int main(){
	n = read(); m = read(); q = read(); u = read(); v = read(); t = read();
	p = (double)u/v;
	for(int i = 1;i <= n;i++){
		int x = read();
		que.push(x);
	}
	for(int i = 1;i <= m;i++){
		int x = que.num[1] + add; que.pop();
		if(i % t == 0) write(x),putchar(' ');
		int a = (int)(x*p);
		int b = x-a;
		add += q;
		a -= add; b -= add;
		que.push(a); que.push(b);
	}
	puts("");
	for(int i = 1;i <= n+m;i++){
		int y = que.num[1] + add;
		que.pop();
		if(i % t == 0) write(y),putchar(' ');
	}
	puts("");
	return 0;
}