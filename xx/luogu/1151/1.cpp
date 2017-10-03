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

int p[6];
int k;
int len;
bool flag = true;

int main(){
	k = read();
	for(int i = 10000;i <= 30000;i++){
		int x = i;
		len = 0;
		while(x){
			p[++len] = x%10;
			x /= 10;
		}
		int a = p[1] + p[2]*10 + p[3]*100;
		int b = p[2] + p[3]*10 + p[4]*100;
		int c = p[3] + p[4]*10 + p[5]*100;
		if(a % k == 0 && b % k == 0 && c % k == 0)
			printf("%d\n",i),flag = false;
	}
	if(flag) printf("No\n");
	return 0;
}
