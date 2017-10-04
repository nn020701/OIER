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
struct query{
	int t,p,l;
	bool typ;
	bool operator <(const query& rhs)const{
		return p<rhs.p;
	}
}a[200002];
int cnt[100001];
__gnu_pbds::priority_queue<pair<int,int> > q;
__gnu_pbds::priority_queue<pair<int,int> >::point_iterator it[100001]; 
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n=read(),m=read(),cur=0;
	for(int i=1;i<=m;i++){
		int x=read(),l=read(),k=read();
		a[++cur]=(query){i,max(x-k,1),l,1};
		if (x+k<n)
			a[++cur]=(query){i,x+k+1,l,0};
	}
	sort(a+1,a+cur+1);
	int ans=0;
	for(int i=1;i<=cur;i++){
		if (a[i].p!=a[i-1].p && i!=1 && (q.empty() || cnt[q.top().second]>1))
			ans+=a[i].p-a[i-1].p;
		if (a[i].typ){
			it[a[i].t]=q.push(make_pair(a[i].t,a[i].l));
			cnt[a[i].l]++;
		}else{
			//assert(!q[a[i].l].empty());
			cnt[a[i].l]--;
			q.erase(it[a[i].t]);
		}
	}
	if (q.empty() || cnt[q.top().second]>1)
		ans+=n+1-a[cur].p;
	printf("%d",ans);
}
