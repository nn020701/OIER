#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long

inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,cnt,lowans;
int f[205][205][205];
int a[205];
int w[205];

void chuli(){
	int num[205];
	memset(num,0,sizeof num);
	bool flag;
	int len;
	for(int i = 1;i <= cnt;i++)
		num[a[i]]++;
	while(1){
		flag = false; len = 0;
		for(int i = 1;i <= cnt;i++){
			if(num[a[i]] == 1){
				lowans += w[i]*w[i];
				num[a[i]]--;
				flag = true;
			}
			else if(a[i] == a[len]){
				w[len] += w[i];
				num[a[i]]--;
				flag = true;
			}
			else{
				w[++len] = w[i];
				a[len] = a[i];
			}
		}
		cnt = len;
		if(flag == false) break;
	}
}

int dp(int l,int r,int k){
	if(l > r) return 0;
	int &ans = f[l][r][k];
	if(ans >= 0) return ans;
	ans = dp(l,r-1,0)+(w[r]+k)*(w[r]+k);
	for(int i = r-1;i >= l;i--)
		if(a[i] == a[r])
			ans = max(ans,dp(i+1,r-1,0)+dp(l,i,k+w[r]));
	return ans;
}

int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int t = read();
	for(int T = 1;T <= t;T++){
		memset(f,-1,sizeof f);
		// memset(w,0,sizeof w);
		cnt = 0; lowans = 0; n = read();
		for(int i = 1;i <= n;i++){
			int x = read();
			if(x == a[cnt])
				w[cnt]++;
			else{
				a[++cnt] = x;
				w[cnt] = 1;
			}
		}
		chuli();
		if(cnt == 0)
			printf("Case %d: %d\n",T,lowans);
		else
			printf("Case %d: %d\n",T,dp(1,cnt,0)+lowans);
	}
	return 0;
}