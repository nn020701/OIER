#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 10005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a[N];
int n,k;

int main(){
	n = read(); k = read();
	for(int i = 1;i <= n;i++) a[i] = read();
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		if(a[i] != a[i-1]){
			k--;
			if(k == 0){
				printf("%d\n",a[i]);
				return 0;
			}
		}
	}
	printf("NO RESULT\n");
	return 0;
}
