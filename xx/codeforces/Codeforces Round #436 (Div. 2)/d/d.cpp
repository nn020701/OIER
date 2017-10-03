#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[N];
int cnt,ans;
int num[N];
bool vis[N];

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a[i] = read();
		num[a[i]]++;
		if(num[a[i]] > 1) ans++;
	}
	cnt = 1;
	while(num[cnt] > 0)	
		cnt++;
	for(int i = 1;i <= n;i++){
		if(num[a[i]] > 1){
			if(cnt < a[i] || vis[a[i]]){
				num[a[i]]--; a[i] = cnt;
				num[cnt]++;
				while(num[cnt] > 0)
					cnt++;
			}
			else vis[a[i]] = true;
		}
	}
	printf("%d\n",ans);
	for(int i = 1;i < n;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}