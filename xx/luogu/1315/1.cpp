// ´íÎóµÄÌ°ÐÄ 
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
#define M 10005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int p,num;
}p[N];
int n,m,k;
int s[N],ed[M];
int num,Maxt;
ll ans;
vector<int> g[N];

bool cmp(node a,node b){
	return a.p > b.p;
}

void work(){
	ans = 0; num = 0,Maxt = 0;
	for(int i = 1;i < n;i++){
		for(int j = 0;j < g[i].size();j++){
			int v = g[i][j];
			if(g[i][j] > Maxt){
				ans += 1LL*(g[i][j]-Maxt)*num;
				Maxt = g[i][j];
				num++;
			}
			else{
				ans += Maxt-g[i][j];
				num++;
			}
		}
		ans += 1LL*s[i]*num;
		num -= ed[i];
		Maxt += s[i];
	}
	printf("%lld\n",ans);
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n = read(); m = read(); k = read();
	for(int i = 1;i < n;i++){
		s[i] = read(); p[i].p = 0;
		p[i].num = i;
	}
	for(int i = 1;i <= m;i++){
		int t = read(),x = read(),y = read();
		g[x].push_back(t); ed[y-1]++;
		p[y-1].p++;
	}
	sort(p+1,p+n,cmp);
	for(int i = 1;i < n;i++){
		if(s[p[i].num] >= k){
			s[p[i].num] -= k;
			k = 0;
			break;
		}
		else{
			k -= s[p[i].num];
			s[p[i].num] = 0;
		}
	}
	work();
	return 0;
}
