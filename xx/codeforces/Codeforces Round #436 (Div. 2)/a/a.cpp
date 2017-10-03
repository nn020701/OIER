#include<cstdio>
#include<map>
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

int n,cnt;
bool v[120];
int a[120];

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		int x = read();
		a[x]++;
	}
	for(int i = 1;i <= 100;i++)
		for(int j = i+1;j <= 100;j++){
			if(a[i]+a[j] == n && a[i] != 0 && a[j] != 0 && a[i] == a[j]){
				printf("YES\n");
				printf("%d %d\n",i,j);
				return 0;
			}
		}
		printf("NO\n");
	return 0;
}