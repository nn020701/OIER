#include <bits/stdc++.h>
using namespace std;
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
int a[1002][1002];
ll sum[1002][1002],qwq[1002][1002];
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n=read(),w=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			sum[i][j]=sum[i-1][j-1]+a[i][j];
			qwq[i][j]=qwq[i-1][j+1]+a[i][j];
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){ // odd
			int l=0,r=min(min(i,j)-1,n-max(i,j));
			if (a[i][j]>w)
				continue;
			//printf("%d %d %d\n",i,j,r);
			while(l<r){
				int mid=(l+r+1)/2;
				//printf("%d %d %d\n",l,r,sum[i+mid][j+mid]-sum[i-mid-1][j-mid-1]+qwq[i+mid][j-mid]-qwq[i-mid-1][j+mid+1]);
				if (sum[i+mid][j+mid]-sum[i-mid-1][j-mid-1]+qwq[i+mid][j-mid]-qwq[i-mid-1][j+mid+1]-a[i][j]<=w)
					l=mid;
				else r=mid-1;
			}
			//printf("%d\n",l);
			ans=max(ans,l*2+1);
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++){ //even
			int l=0,r=min(min(i,j),n-max(i,j));
			while(l<r){
				int mid=(l+r+1)/2;
				if (sum[i+mid][j+mid]-sum[i-mid][j-mid]+qwq[i+mid][j-mid+1]-qwq[i-mid][j+mid+1]<=w)
					l=mid;
				else r=mid-1;
			}
			ans=max(ans,l*2);
		}
	printf("%d",ans);
}
