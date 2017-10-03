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

int n;
char s[210];
bool vis[50];
int ans,MX;

int main(){
	n = read();
	scanf("%s",s+1);
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			bool flag = false;
			ans = 0;
			memset(vis,0,sizeof vis);
			for(int z = i;z <= j;z++){
				if(s[z] >= 'A' && s[z] <= 'Z'){
					flag = true;
					break;
				}
				int a = s[z]-'a';
				if(!vis[a]){
					vis[a] = true;
					ans++;
				}
			}
			if(flag) continue;
			MX = max(MX,ans);
		}
	}
	printf("%d\n",MX);
	return 0;
}