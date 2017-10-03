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

int num[27];
int Min = 99999,Max;
char c[110];

bool check(int x){
	for(int i = 2;i < x;i++)
		if(x%i == 0) return false;
	return true;
}

int main(){
	scanf("%s",c);
	for(int i = 0;i < strlen(c);i++)
		num[c[i]-'a']++;
	for(int i = 0;i < 26;i++){
		if(num[i] != 0)
			Min = min(Min,num[i]);
		Max = max(Max,num[i]);
	}
	if(Max-Min !=1 && Max-Min != 0 && check(Max-Min))
		printf("Lucky Word\n%d\n",Max-Min);
	else printf("No Answer\n0\n");
//	printf("%d\n",Max-Min);
	return 0;
}
