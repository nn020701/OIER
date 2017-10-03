#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[N];
int b[N];
map<int,int> num;
int ans;

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		int x = read();
		if(x == 1) a[i] = 1;
		else a[i] = -1;
		b[i] = a[i]+b[i-1];
	}
	for(int i = 1;i <= n;i++){
		if(b[i] == 0) ans = max(ans,i);
		else if(num[b[i]] == 0) num[b[i]] = i;
		else ans = max(ans,i-num[b[i]]);
	}
	printf("%d\n",ans);
	return 0;
}
