#include<queue>
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

int num;
bool flag = false;
int bin[11] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main(){
	num = read();
	if(num == 0){
		printf("0\n");
		return 0;
	}
	if(num < 0){
		num = -num;
		printf("-");
	}
	for(int i = 1;i <= 9;i++){
		if(num % bin[i] == 0 && !flag)
			continue;
		printf("%d",(num%bin[i])/bin[i-1]);
		num -= (num%bin[i]);
		// printf("%d\n",num);
		flag = true;
		if(num == 0) break;
	}
	return 0;
}