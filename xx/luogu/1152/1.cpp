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

int n,a,b;
bool vis[1005];

int main(){
	n = read(); a = read();
	for(int i = 1;i < n;i++){
		b = read();
		if(vis[abs(a-b)] || abs(a-b) < 1 || abs(a-b) > n-1){
			printf("Not jolly\n");
			return 0;
		}
		vis[abs(a-b)] = true;
		a = b;
	}
	printf("Jolly\n");
	return 0;
}
