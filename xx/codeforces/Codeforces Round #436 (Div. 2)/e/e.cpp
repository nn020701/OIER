#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int f[105][2005];
int last[105][2005];
bool vis[105][2005];
int n,ans,mxt,num;
int sta[105],top;
struct node{
	int a,b,c,num;
}x[105];

bool cmp(node a,node b){
	return a.b < b.b;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++){
		x[i].a = read(); x[i].b = read(); x[i].c = read();
		x[i].num = i;
		mxt = max(mxt,x[i].b);
	}
	sort(x+1,x+n+1,cmp);
	for(int i = 1;i <= n;i++){
		for(int j = x[i].a;j < x[i].b;j++){
			if(f[i][j] <= f[i-1][j-x[i].a]+x[i].c){
				f[i][j] = f[i-1][j-x[i].a]+x[i].c;
				last[i][j] = j-x[i].a;
				vis[i][j] = true;
			}
		}
		for(int j = 0;j < mxt;j++){
			if(f[i][j] <= f[i-1][j]){
				f[i][j] = f[i-1][j];
				last[i][j] = j;
				vis[i][j] = false;
			}
		}
	}
	for(int i = 0;i < mxt;i++){
		if(ans < f[n][i]){
			ans = f[n][i];
			num = i;
		}
	}
	printf("%d\n",ans);
	for(int i = n;i >= 1;i--){
		if(vis[i][num]){
			sta[++top] = x[i].num;
		}
		num = last[i][num];
	}
	printf("%d\n",top);
	while(top > 0){
		printf("%d ",sta[top]);
		top--;
	}
	printf("\n");
	return 0;
}