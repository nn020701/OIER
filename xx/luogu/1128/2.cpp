#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 50000
#define SIZE 10000
#define LOGN 15
#define MOD 100000000LL
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const double INFI = 123456789012345.0;
const int p[LOGN+1] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int n;
int t[LOGN+1],ct[LOGN+1],ts;
double Log[LOGN+1],Min;

class bignum
{
public:
	ll num[SIZE];
	int tot;
	bignum() {}
	bignum(ll x)
	{
		clear();
		while (x) num[tot++] = x % MOD, x /= MOD;
	}
	void clear()
	{
		tot = 0;
		for (int i = 0; i < SIZE; ++i) num[i] = 0LL;
	}
	void operator *= (const int &x)
	{
		for (int i = 0; i < tot; ++i) num[i] *= x;
		for (int i = 0; i < tot; ++i)
			if (num[i] >= MOD)
			{
				num[i + 1] += num[i] / MOD;
				num[i] %= MOD;
			}
		while (num[tot])
		{
			if (num[tot] >= MOD)
			{
				num[tot + 1] += num[tot] / MOD;
				num[tot] %= MOD;
			}
			++tot;
		}
	}
	void print()
	{
		printf("%lld", num[tot - 1]);
		for (int i = tot - 2; i >= 0; --i)
			printf("%08lld", num[i]);
	}
}ans(1);

void dfs(int d,int x,int m,double clog){
	if(clog > Min) return;
	if(x == 1){
		if(clog < Min){
			Min = clog; ts = d-1;
			for(int i = 1;i < d;i++)
				t[i] = ct[i];
		}
		return;
	}
	for(int i = 1;i*i <= x && i <= m;i++)
		if(!(x%i)){
			if(i != 1){
				ct[d] = i;
				dfs(d+1,x/i,i,clog+Log[d]*(double)(i-1));
			}
			if(x/i <= m && x/i != i){
				ct[d] = x/i;
				dfs(d+1,i,x/i,clog+Log[d]*(double)(x/i-1));
			}
		}
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= LOGN ;i++) Log[i] = log((double)p[i]);
	Min = INFI;
	dfs(1,n,n,0);
	for(int i = 1;i <= ts;i++)
		for(int j = t[i]-1;j > 0;j--)
			ans *= p[i];
	ans.print();
	return 0;
}
