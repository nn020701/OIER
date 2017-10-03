#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
priority_queue<int> q;

int main(){
	n = read(); k = read();
	for(int i = 1;i <= n;i++){
		int a = read();
		q.push(a);
	}
	for(int i = 1;i < n;i++){
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		int c = (a+b)/k;
		q.push(c);
	}
	printf("%d\n",q.top());
	return 0;
}
