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

char s[N];
int le[N],ri[N],sum[N],ans[N];
int n,p,mid;

int main(){
	n = read(); mid = n;
	scanf("%s",s+1);
	for(int i = 1;i <= n;i++)
		ri[i] = le[i] = s[i]-'a'+1;
	p = read();
	if(n == 1){
		printf("%c",ri[n]+'a'-1);
		return 0;
	}
	sort(le+1,le+n+1);
	printf("%c",ri[p]+'a'-1);
	for(int i = 1;i <= n;i++) sum[le[i]] = i;
	for(int i = 1;i <= n;i++)
		if(le[i] == ri[p]){
			ans[n] = ri[i];
			p = ri[i];
			break;
		}
	while(1){
		if(n == 2) break;
		n--;
		ans[n] = ri[sum[p]];
		sum[p]--;
		p = ans[n];
	}
	for(int i = 2;i <= mid;i++)
		printf("%c",ans[i]+'a'-1);
	return 0;
}
