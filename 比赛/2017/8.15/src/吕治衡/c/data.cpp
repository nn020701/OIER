#include<bits/stdc++.h>
#define int long long
int random(int x){return (((rand()%1024*1ll)<<50)+((rand()%1024*1ll)<<40)+((rand()%1024*1ll)<<30)+((rand()%1024*1ll)<<20)+((rand()%1024*1ll)<<10)+((rand()%1024*1ll)))%x;}
using namespace std;
signed main(){
	freopen("c.in","w",stdout);
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int n=random(1000)+1,m=random(1000)+1;
	cout<<n<<' '<<m<<endl;
	for (int i=1;i<=m;i++){
			cout<<random(n)+1<<' '<<random(1000)<<' '<<random(n)+1<<endl;
		}
}
