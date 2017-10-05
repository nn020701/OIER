#include<cstdio>
#include<cstring>
#define N 1000005
#define mo 1000000007
#define ll long long
using namespace std;
int n,Q,len,cnt,k;
int ch[N][26],sz[N],c[3005][220],num[3005];
ll ans;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		len=strlen(s+1);
		for (int j=1,x=0;j<=len;j++){
			if (!ch[x][s[j]-'a']) ch[x][s[j]-'a']=++cnt;
			x=ch[x][s[j]-'a']; sz[x]++;
		}
	}
	for (int i=1;i<=cnt;i++) num[sz[i]]++;
	for (int i=0;i<=n;i++){
		c[i][0]=1;
		for (int j=1;j<=i&&j<=210;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
	}
	while (Q--){
		scanf("%d",&k);
		ans=0;
		for (int i=1;i<=n;i++)
			if (num[i])
				for (int j=0;j<=k&&j<=i;j++)
					ans=(ans+1ll*(i-j)*(i-j-1)/2*c[i][j]%mo*c[n-i][k-j]%mo*num[i])%mo;
		printf("%lld\n",ans);
	}
}
