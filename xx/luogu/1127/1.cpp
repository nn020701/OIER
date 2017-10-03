#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int len[N],path[N],top;
int num[26];
int head[N],to[N*N],nxt[N*N],cnt;
bool vis[N],ans;
string s[N];

void add(int x,int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}

void dfs(int x){
	path[++top] = x;
	vis[x] = true;
	for(int i = head[x];i;i = nxt[i])
		if(!vis[to[i]])
			dfs(to[i]);
	if(top == n){
		cout<<s[path[1]];
		for(int i = 2;i <= top;i++)
			cout<<"."<<s[path[i]];
		cout<<endl;
		exit(0);
	}
	vis[x] = false;
	top--;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		cin>>s[i];
	sort(s+1,s+n+1);
	for(int i = 1;i <= n;i++)
		len[i] = s[i].length();
	for(int i = 1;i <= n;i++)
		for(int j = n;j >= 1;j--)
			if(i!=j)
				if(s[i][len[i]-1] == s[j][0])
					add(i,j);
	for(int i = 1;i <= n;i++){
		num[s[i][0]-'a']++;
		num[s[i][len[i]-1]-'a']--;
	}
	int k = 0,h;
	for(int i = 0;i < 26;i++){
		if(num[i] == 1) k++,h = i;
		else if(num[i] == 2) k = 2;
		if(k == 2) break;
	}
	if(k == 2){
		printf("***\n");
		return 0;
	}
	if(k == 1){
		for(int i = 1;i <= n;i++)
			if(s[i][0]-'a' == h)
				dfs(i);
	}
	else{
		for(int i = 1;i <= n;i++)
			dfs(i);
	}
	if(!ans){
		printf("***\n");
		return 0;
	}
	return 0;
}
