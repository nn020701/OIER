#include <iostream>
#include <cstdio>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int num,n;
char s[105];
char ans[105];

bool cmple(){
	int len1 = strlen(s+1);
	int len2 = strlen(ans+1);
	if(len1 > len2) return true;
	if(len1 < len2) return false;
	for(int i = 1;i <= len1;i++){
		if(s[i] > ans[i])
			return true;
		if(s[i] < ans[i])
			return false;
	}
	return true;
}

int main(){
	n = read();
	ans[1] = '\0';
	for(int i = 1;i <= n;i++){
		scanf("%s",s+1);
		if(cmple()){
			int len = strlen(s+1);
			for(int i = 1;i <= len;i++)
				ans[i] = s[i];
			ans[len+1] = '\0';
			num = i;
		}
	}
	printf("%d\n%s\n",num,ans+1);
	return 0;
}