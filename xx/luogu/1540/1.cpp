#include <iostream>
#include <cstdio>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int n,m;
int cnt,ans;
bool check[1005];
queue<int> q;

int main(){
	m = read(); n = read();
	for(int i = 1;i <= n;i++){
		int x = read();
		if(check[x] == true)
			continue;
		else{
			ans++;
			check[x] = true;
			q.push(x);
			if(cnt == m){
				int y = q.front(); q.pop();
				check[y] = false;
			}
			else cnt++;
		}
	}
	printf("%d\n",ans);
	return 0;
}