#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int step[2][4]={{-1,0,0,1},{0,-1,1,0}};
int n,m;
char Map[260][260];
bool book[260][260];
int lang,sheep;
int ans_l,ans_s;
bool flag;
void dfs(int x,int y){
	if(Map[x][y]=='k')
		sheep++;
	else if(Map[x][y]=='v')
		lang++;
	book[x][y]=true;
	int p_x,p_y;
	for(int i=0;i<4;i++){
		p_x=x+step[0][i];
		p_y=y+step[1][i];
		if(p_x<0||p_x>=n||p_y<0||p_y>=m){
			flag=true;
			continue;
		}
		if(!book[p_x][p_y])
			dfs(p_x,p_y);
	}
}
int main(){
	freopen("story.in","r",stdin);
	freopen("story.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",Map[i]);
		for(int j=0;j<m;j++)
			if(Map[i][j]=='#')
				book[i][j]=true;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(book[i][j]||Map[i][j]=='.')
				continue;
			sheep=0;
			lang=0;
			flag=false;
			dfs(i,j);
			if(!flag){
				if(sheep>lang)
					ans_s+=sheep;
				else
					ans_l+=lang;
			}
			else{
				ans_s+=sheep;
				ans_l+=lang;
			}
		}
	printf("%d %d",ans_s,ans_l);
	return 0;
}
