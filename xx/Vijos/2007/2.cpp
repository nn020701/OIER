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

int Scarlet[3][N],head[3],tail[3];
int q,n,m,u,v,t;
int add;
double p;

inline bool cmp(int a,int b){
	return a > b;
}

inline int pop(){
	int ans = -1e9,num = 0;
	for(int i = 0;i < 3;i++)
		if(head[i] < tail[i])
			if(Scarlet[i][head[i]] > ans){
				num = i;
				ans = Scarlet[i][head[i]];
			}
	head[num]++;
	return ans;
}

int main(){
	n = read(); m = read(); q = read(); u = read(); v = read(); t = read();
	p = (double)u/v;
	for(int i = 1;i <= n;i++){
		int x = read();
		Scarlet[0][tail[0]++] = x;
	}
	sort(Scarlet[0],Scarlet[0]+tail[0],cmp);
	for(int i = 1;i <= m;i++){
		int x = pop() + add;
		if(i % t == 0) write(x),putchar(' ');
		int a = (int)(x*p);
		int b = x-a;
		add += q;
		Scarlet[1][tail[1]++] = a-add;
		Scarlet[2][tail[2]++] = b-add;
	}
	puts("");
	if(t > m+n){
		puts("");
		return 0;
	}
	for(int i = 1;i <= n + m;i++){
		int x = pop();
		if(i % t == 0) write(x+add),putchar(' ');
	}
	puts("");
	return 0;
}