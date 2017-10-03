#include<iostream>
#include<queue>
#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
#define regint register int
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int> > q2;
int root;
int n;
int p[N];

int main(){
	n = read();
	for(regint i = 1;i <= n;i++)
		p[i] = read();
	printf("%d\n",p[1]);
	root = p[1];
	for(regint k = 2;k <= (n+1)>>1;k++){
		if(p[k*2-2] > root)
			q2.push(p[k*2-2]);
		else q1.push(p[k*2-2]);
		if(p[k*2-1] > root)
			q2.push(p[k*2-1]);
		else q1.push(p[k*2-1]);
		if(q2.size() > q1.size()){
			int a = q2.top(); q2.pop();
			q1.push(root);
			root = a; 
		}
		else if(q1.size() > q2.size()){
			int a = q1.top(); q1.pop();
			q2.push(root);
			root = a;
		}
		printf("%d\n",root);
	}
	return 0;
}
