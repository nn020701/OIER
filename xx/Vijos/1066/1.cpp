#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,cnt;
int t[32005];
int num[15005];
struct node{
	int x,y,num;
	friend bool operator <(node a,node b){
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}
}a[15005];

void updata(int x,int v){
	for(int i = x;i <= n;i += lowbit(i))
		t[i] += v;
}

int query(int x){
	int ans = 0;
	for(int i = x;i > 0;i -= lowbit(i))
		ans += t[i];
	return ans;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		a[i].x = read(); a[i].y = read();
		a[i].num = 1;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		if(a[i].x != a[i-1].x || a[i].y != a[i-1].y){
			a[++cnt].x = a[i].x;
			a[cnt].y = a[i].y;
		}
		else a[cnt].num++;
	}
	for(int i = 1;i <= cnt;i++)
		printf("%d %d %d\n",a[i].x,a[i].y,a[i].num);
	for(int i = 1;i <= cnt;i++){
		int nu = query(a[i].y);
		num[nu+a[i].num-1] += a[i].num;
		updata(a[i].y,a[i].num);
	}
	for(int i = 0;i < n;i++)
		printf("%d\n",num[i]);
	return 0;
}