#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

char s[110];
char Map[110][110];
int step_x[10]={-1,0,1,-1,1,-1,0,1};
int step_y[10]={-1,-1,-1,0,0,1,1,1};
struct data{
	int num;
	int a[8];
}xz[30];
int linshi_a[8];
int linshi_num;
int k=1;
int m,n;

bool pd(data temp){
	if(linshi_num!=temp.num)
		return false;
	for(int i=0;i<=8;i++)
		if(linshi_a[i]!=temp.a[i])
			return false;
	return true;
}

void DFS1(int x,int y){
	linshi_num++;
	Map[x][y]='2';
	int ans=0;
	for(int i=0;i<=7;i++)
		if(Map[x+step_x[i]][y+step_y[i]]!='0'&&x+step_x[i]<=m&&x+step_x[i]>=1&&y+step_y[i]>=1&&y+step_y[i]<=n){
			ans++;
			if(Map[x+step_x[i]][y+step_y[i]]=='1')
				DFS1(x+step_x[i],y+step_y[i]);
		}
	linshi_a[ans]++;
}

void DFS2(int x,int y,int p){
	Map[x][y]='a'+p-1;
	for(int i=0;i<=7;i++)
		if(Map[x+step_x[i]][y+step_y[i]]=='2'&&x+step_x[i]<=m&&x+step_x[i]>=1&&y+step_y[i]>=1&&y+step_y[i]<=n)
			DFS2(x+step_x[i],y+step_y[i],p);
}

int main(){
	freopen("star.in","r",stdin);
	freopen("star.out","w",stdout);
	bool flag;
	int p;
	cin>>m>>n;
	for(int j=0;j<=27;j++){
		xz[j].num=0;
		for(int i=0;i<=8;i++)
			xz[j].a[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=m;j++)
			Map[i][j]=s[j-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Map[i][j]!='1')
				continue;
			linshi_num=0;
			for(int z=0;z<=8;z++){
				linshi_a[z]=0;
			}
			DFS1(i,j);
			flag=false;
			for(int z=1;z<k;z++)
				if(pd(xz[z])){
					flag=true;
					p=z;
					break;
				}
			if(flag)
				DFS2(i,j,p);
			else{
				DFS2(i,j,k);
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%c",Map[i][j]);
		printf("\n");
	}
	return 0;
}
