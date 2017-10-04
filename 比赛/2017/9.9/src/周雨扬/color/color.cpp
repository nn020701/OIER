#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int h,w,n,tot,t,cnt[15];
ll a[N*9],ans;
struct P{int x,y;}p[N];
bool cmp(P a,P b){
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d%d",&h,&w,&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (p[i].x!=p[i-1].x||p[i].y!=p[i-1].y)
			p[++t]=p[i];
	n=t;
	for (int i=1;i<=n;i++)
		for (int j=-1;j<=1;j++)
			for (int k=-1;k<=1;k++){
				int nx=p[i].x+j,ny=p[i].y+k;
				if (nx<=1||nx>=h||ny<=1||ny>=w) continue;
				a[++tot]=1ll*w*nx+ny;
			}
	sort(a+1,a+tot+1);
	int la=1;
	for (int i=2;i<=tot;i++)
		if (a[i]!=a[i-1]) cnt[i-la]++,la=i;
	cnt[tot-la+1]++;
	ans=1ll*(h-2)*(w-2);
	for (int i=1;i<=9;i++) ans-=cnt[i];
	printf("%lld\n",ans);
	for (int i=1;i<=9;i++)
		printf("%d\n",cnt[i]);
}
