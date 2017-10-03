
//		gg的dp 
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 50000
#define LOGN 15
#define SIZE 10000
#define MOD 100000000LL			//高精压位 
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const double INFI = 123456789012345.0;
const int p[LOGN+1] = {0,2,3,5,7,11,13,19,23,29,31,37,41,43,47};	//要用的质数 
int n,logn,from[N+1][LOGN+1],pos;
int t[LOGN+1],ct[LOGN+1],ts;
double f[N+1][LOGN+1],Log[N+1],Min;

struct BigNum{
	ll num[SIZE];
	ll len;
	
	BigNum(){
		len = 1;
		num[1] = 1;
	}
	
	BigNum operator * (const int &x){
		BigNum p;
		for(int i = 1;i <= len;i++){
			p.num[i] = x*num[i];
		}
		for(int i = 1;i <= len;i++)
			if(p.num[i] >= MOD){
				p.num[i+1] += p.num[i]/MOD;
				p.num[i] %= MOD;
			}
		p.len = len;
		while(p.num[p.len+1]){
			p.len++;
			if(p.num[p.len] >= MOD){
				p.num[p.len+1] += p.num[p.len]/MOD;
				p.num[p.len] %= MOD;
			}
		}
		return p;
	}
	
	void print(){
		printf("%lld",num[len]);
		for(int i = len-1;i >= 1;i--)
			printf("%08lld",num[i]);
	}
}ans;

int main(){
	n = read();
	for(int i = 1;i <= n;i++) Log[i] = log(double(i))/log(2.0);
	for(int i = 1;i <= n;i++){
		f[i][1] = Log[2]*(double)(i-1);
		from[i][1] = 1;
		for(int j = 2;j <= Log[i];j++){
			Min = INFI; pos = 0;
			for(int k = 1;k*k <= i;k++)
				if(!(i%k) && Log[k] >= j-1)
					if(Min > f[k][j-1]+Log[p[j]]*(double)(i/k-1)){
						Min = f[k][j-1]+Log[p[j]]*(double)(i/k-1);
						pos = k;
					}
			for(int k = 2;k*k <= i;k++)
				if(!(i%k) && Log[i/k] >= j-1)
					if(Min > f[i/k][j-1]+Log[p[j]]*(double)(k-1)){
						Min = f[i/k][j-1]+Log[p[j]]*(double)(k-1);
						pos = i/k;
					}
			f[i][j] = Min;
			from[i][j] = pos;
		}
	}
	Min = INFI; pos = 0;
	for(int i = 1;i <= Log[n];i++)
		if(Min > f[n][i]){
			Min = f[n][i];
			pos = i;
		}
	for(int x = n;x != 1;x = from[x][pos--])
		for(int i = x/from[x][pos]-1;i > 0;i--)
			ans = ans*p[pos];
	ans.print();
	return 0;
}
