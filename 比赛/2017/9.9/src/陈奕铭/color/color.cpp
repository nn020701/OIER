#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

inline ll readll(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

const int step_x[9] = {-1,-1,-1,0,0,0,1,1,1};
const int step_y[9] = {-1,0,1,-1,0,1,-1,0,1};
ll n,m;
int k;
map<pair<int,int>,int> mp;
ll ans[10];

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n = readll(); m = readll();
	k = read();	ans[0] = (n-2)*(m-2);
	for(int i = 1;i <= k;i++){
		int x = read()-1,y = read()-1;
		for(int j = 0;j < 9;j++){
			int xx = x+step_x[j];
			int yy = y+step_y[j];
			if(xx < 1 || xx > n-2 || yy < 1 || yy > m-2)
				continue;
			pair<int,int> a = make_pair(xx,yy);
			int num = mp[a]; mp[a]++;
			ans[num]--;
			ans[num+1]++;
		}
	}
	for(int i = 0;i < 10;i++)
		printf("%lld\n",ans[i]);
	return 0;
}