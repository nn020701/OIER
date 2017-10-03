#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char ans[N];
char s[N];
char c;
int num,firs;
int les;

int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	scanf("%s",ans);
	int len1 = strlen(ans);
	for(int i = 0;i < len1;i++)
		if(ans[i] >= 'A' && ans[i] <= 'Z')
			ans[i] = ans[i]-'A'+'a';
	// printf("%s\n",ans);
	c = getchar();
	while(c == ' ') c = getchar();
	// getchar();
	c = 0;
	// puts("1");
	num = 0;
	firs = 0;
	int len;
	bool flag;
	while(1){
		len = 0;
		if(c == '\n') break;
		// printf("%c\n",c);
		c = getchar();
		while(c == ' '){
			les++;
			c = getchar();
		}
		// if(c == '\n') break;
		while(c != ' ' && c != '\n'){
			s[len++] = c;
			c = getchar();
		}

		for(int i = 0; i < len;i++)
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i]-'A'+'a';
		s[len] = '\0';
		// printf("%s %d\n",s,len);
		if(len != len1){
			les += len+1;
			continue;
		}
		flag = false;
		for(int i = 0;i < len;i++)
			if(s[i] != ans[i]){
				flag = true;
				break;
			}
		if(flag){
			les += len+1;
			continue;
		}
		num = num+1;
		if(num == 1)
			firs = les;
		// printf("%d %d\n",num,firs);
		les += len+1;
	}
	if(num == 0){
		printf("-1\n");
		return 0;
	}
	printf("%d %d\n",num,firs);
	return 0;
}