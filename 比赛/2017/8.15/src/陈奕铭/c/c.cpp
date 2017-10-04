#include<set>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

struct node{
	int x;
	int num,opt;
}a[N];
int n,m,cnt,ans;
int l[N];
int sum[N];
set<int> s;

bool cmp(node a,node b){
	return a.x < b.x;
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= m;i++){
		int x = read(); l[i] = read();
		int k = read();
		node p; p.x = x-k; p.num = i; p.opt = 1;
		a[++cnt] = p;
		p.x = x+k+1; p.num = i; p.opt = -1;
		a[++cnt] = p;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1,p = 1;i <= n;i++){
		while(p <= cnt && a[p].x <= i){
			if(a[p].opt > 0){
				s.insert(a[p].num);
				sum[l[a[p].num]]++;
			}
			else{
				s.erase(a[p].num);
				sum[l[a[p].num]]--;
			}
			p++;
		}
		if(s.empty()) ans++;
		else{
			set<int>:: iterator it = s.end();
			it--;
			if(sum[l[*it]] != 1) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
