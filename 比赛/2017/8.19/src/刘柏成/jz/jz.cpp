#include <cstdio>
#include <bitset>
using namespace std;
bitset<10001> a[10001];
int main(){
	freopen("jz.in","r",stdin);
	freopen("jz.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	int x=1,y=1;
	a[x][y]=1;
	while(q--){
		int op,t;
		scanf("%d%d",&op,&t);
		if (op==1)
			while(t--)
				x--,a[x][y]=1;
		if (op==2)
			while(t--)
				y--,a[x][y]=1;
		if (op==3)
			while(t--)
				y++,a[x][y]=1;
		if (op==4)
			while(t--)
				x++,a[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i].count();
	printf("%d\n",ans);
}
