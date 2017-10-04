#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long ll;
int read(){
	char c=getchar();
	while(c<'0' || c>'9')
		c=getchar();
	int val=0;
	while(c>='0' && c<='9')
		val=val*10+c-'0',c=getchar();
	return val;
}
bool have[1001][1001];
bool on[1001];
int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		on[i]=1;
	while(m--){
		int x=read(),l=read(),k=read();
		for(int i=max(x-k,1);i<=min(x+k,n);i++){
			on[i]=have[i][l];
			have[i][l]=true;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=on[i];
	printf("%d",ans);
}

