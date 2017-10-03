#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 255
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char s[N];
int k;

int main(){
	scanf("%s",s);
	k = read();
	int l = 0,r = 1;
	while(k){
		if(l < 0) s[++l] = s[r++];
		while(s[l] <= s[r]) s[++l] = s[r++];
		l--; k--;
	}
	s[l+1] = '\0';
	for(l = 0;s[l] == '0';l++);
	if(s[l] == '\0') for(;s[r] == '0';r++);
	printf("%s",s+l);
	printf("%s\n",s+r);
	return 0;
}
