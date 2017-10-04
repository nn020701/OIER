#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int Map[30][30];
bool d[30][30];
bool vis[30];
int M13[13];
int ans=999999999;
int edge[13];
int top;
void dfs(int x,int step){
	int q[13],l;
	memset(q,0,sizeof q);
	if(x==n){
		ans=min(ans,step);
		return;
	}
	if(step>=ans) return;
	bool flag;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&!d[x][i]){
			l=0; flag=false;
			for(int j=top;j>=1;j--){
				l+=edge[j];
				if((l+Map[x][i])%13==0){
					flag=true;
					break;
				}
			}
			if(flag) continue;
			vis[i]=true;
			edge[++top]=Map[x][i];
			dfs(i,step+Map[x][i]);
			vis[i]=false;
			--top;
		}
}
int main(){
	freopen("att.in","r",stdin);
	freopen("att.out","w",stdout);
	scanf("%d",&n);
	char s[30];
	memset(Map,0x3f,sizeof Map);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=1;j<=n;j++){
			if(s[j-1]>='A'&&s[j-1]<'Z'&&s[j-1]!='M')
				Map[i][j]=s[j-1]-'A'+1;
			else if(s[j-1]>='a'&&s[j-1]<'z'&&s[j-1]!='m')
				Map[i][j]=s[j-1]-'a'+27;
			else d[i][j]=true;
		}
	}
	vis[1]=true;
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}