#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll f[20];
char p[20] = "1helloworld";
char c;

int main(){
	f[0] = 1;
	while((c = getchar()) != EOF){
		for(int i = 10;i;i--)
			if(c == p[i] || c == p[i]-'a'+'A')
				f[i] = (f[i]+f[i-1])%mod;
	}
		
	printf("%lld\n",f[10]);
	return 0;
}
