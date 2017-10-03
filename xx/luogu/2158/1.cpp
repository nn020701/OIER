#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 40005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

bool vis[N];
int n,p[N],e[N],cnt,ans;

int main(){
	n = read();
	for(int i = 2;i <= n;++i){
		if(!vis[i]){
			p[++cnt] = i;
			e[i] = i-1;
		}
		for(int j = 1;j <= cnt && i*p[j] <= n-1;j++){
			vis[i*p[j]] = true;
			if(i%p[j] == 0){
				e[i*p[j]] = e[i]*p[j];
				break;
			}
			e[i*p[j]] = e[i]*(p[j]-1);
		}
	}
	for(int i = 2;i <= n-1;++i){
		ans += e[i];
	}
	printf("%d\n", ans*2+3);
	return 0;
}