#include<bits/stdc++.h>
#define N 10005
using namespace std;
bool a[N][N];
int fl[N],n,q,x,y,z,l,r,ans;
int main(){
	freopen("c1.in","r",stdin);
	freopen("bl.out","w",stdout);
	scanf("%d%d",&n,&q);
	while (q--){
		scanf("%d%d%d",&x,&y,&z);
		l=max(1,x-z); r=min(n,x+z);
		for (int i=l;i<=r;i++){
			if (a[i][y]) fl[i]=0;
			else fl[i]=1;
			a[i][y]=1;
		}
		//if (q%100==0) printf("%d\n",q);
	}
	for (int i=1;i<=n;i++) ans+=1-fl[i];
	printf("%d\n",ans);
}
