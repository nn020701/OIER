#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,l;
int a[N],u[N];
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int> > q2;

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;++i)
		a[i] = read();
	l = 1;
	for(int i = 1;i <= m;++i){
		int r = read();
		for(;l <= r;++l){
			q1.push(a[l]);
			if(q1.size() == i+1){
				q2.push(q1.top());
				// puts("11");
				q1.pop();
				// puts("12");
			}
		}
		printf("%d\n",q1.top());
		// puts("11");
		if(q2.empty()) continue;
		q1.push(q2.top());
		// puts("13");
		q2.pop();
		// puts("14");
	}
	return 0;
}