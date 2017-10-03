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
int ans;

int main(){
	int n = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i; j++){
			if(a[i] < a[j]){
				swap(a[i],a[j]);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
