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

int tri[26][5000001];
bool show[101][5000001];
int n,cnt;

void insert(int x){
	char s[25];
	scanf("%s",s);
	int len = strlen(s);
	int now = 0;
	for(int i = 0;i < len;i++){
		if(tri[s[i]-'a'][now] == 0) tri[s[i]-'a'][now] = ++cnt;
		now = tri[s[i]-'a'][now];
	}
	show[x][now] = true;
}

void check(){
	char s[25];
	scanf("%s",s);
	bool flag = true;
	int len = strlen(s);
	int now = 0;
	for(int i = 0;i < len;i++){
		if(tri[s[i]-'a'][now] == 0){
			flag = false;
			break;
		}
		now = tri[s[i]-'a'][now];
	}
	if(flag){
		for(int i = 1;i < n;i++)
			if(show[i][now])
				printf("%d ",i);
		if(show[n][now])
			printf("%d",n);
	}
	puts("");
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		int l = read();
		for(int j = 1;j <= l;j++)
			insert(i);
	}
	int m = read();
	for(int i = 1;i <= m;i++)
		check();
	return 0;
}
