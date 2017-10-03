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
int a,b;
string s;
char p[100000];

int main(){
	cin>>a;
	cin>>s;
	for(int i = 0;i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9') n = n*a+s[i]-'0';
		else n = n*a+s[i]-'A'+10;
		
	}
	int len = 0;
	cin>>b;
	while(n > 0){
		int l = n%b;
		n /= b;
		if(l >= 0 && l <= 9) p[++len] = l+'0';
		else p[++len] = l-10+'A';
	}
	for(int i = len;i >= 1;i--)
		printf("%c",p[i]);
	return 0;
}
