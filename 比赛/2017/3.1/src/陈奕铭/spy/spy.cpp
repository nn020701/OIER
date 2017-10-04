#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int book[610];
vector<int> edge[610];
int n;
bool visDfs[610];
void dfs(int x,int p){
	visDfs[x]=true;
	if(book[x]==2) return;
	if(book[x]==0) book[x]+=p;
	else if(book[x]==1) book[x]=2;
	for(int i=0;i<edge[x].size();i++)
		if(!visDfs[edge[x][i]]){
			if(book[x]==2)
				dfs(edge[x][i],2);
			else
				dfs(edge[x][i],1);
		}
}
int main() {
	freopen("spy.in","r",stdin);
	freopen("spy.out","w",stdout);
	n=read();
	int a,b;
	for(int i=1;i<=n;i++){
		a=read();
		if(a==0)
			book[i]=3;
		else
			while(a--){
				b=read();
				edge[b].push_back(i);
			}
	}
	/*for(int i=1;i<=n;i++){					//debug
		printf("%d: ",i);
		for(int j=0;j<edge[i].size();j++){
			printf("%d ",edge[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i=1;i<=n;i++)
		if(book[i]==3){
			dfs(i,1);
			memset(visDfs,0,sizeof visDfs);
		}
	bool flag=false;
	for(int i=1;i<=n;i++)
		if(book[i]<2){
			flag=true;
			printf("%d\n",i);
		}
	if(!flag)
		printf("BRAK");
	return 0;
}
