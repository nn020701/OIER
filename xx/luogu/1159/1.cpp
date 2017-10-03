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
string s1[105],s2[105];
string down[105],up[105];
int d1,d2,u1,u2;

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		cin>>s1[i]>>s2[i];
		if(s2[i] == "DOWN") down[++d1] = s1[i];
		else if(s2[i] == "UP") up[++u1] = s1[i];
	}
	for(int i = 1;i <= n;i++){
		if(s2[i] == "SAME")cout<<s1[i]<<endl;
		else if(d2 < d1) cout<<down[++d2]<<endl;
		else if(u2 < u1) cout<<up[++u2]<<endl;
	}
	return 0;
}
