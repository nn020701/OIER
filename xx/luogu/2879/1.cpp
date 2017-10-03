#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 10005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a[N];
int n,I,H,R;
map<pair<int,int>,bool> mp;

int main(){
	n = read(); I = read(); H = read(); R = read();
	for(int i = 1;i <= n;i++)
		a[i] = H;
	for(int i = 1;i <= R;i++){
		int x = read(),y = read();
		if(x > y) swap(x,y);
		pair<int,int> p = make_pair(x,y);
		if(mp[p]) continue;
		mp[p] = true;
		for(int l = x+1;l <= y-1;l++)
			a[l]--;
	}
	for(int i = 1;i <= n;i++)
		printf("%d\n",a[i]);
	return 0;
}
