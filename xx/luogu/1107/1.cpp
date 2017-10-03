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
string a[30];

bool cmp(string a,string b){
	return (a+b) > (b+a);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 1;i <= n;i++)
			cin>>a[i];
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n;i++)
			cout<<a[i];
		puts("");
	}
	return 0;
}
