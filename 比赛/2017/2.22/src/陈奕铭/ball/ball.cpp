#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,e;
int memory[9];
char Map[110][110];
void you_shang(int x,int y);
void zuo_xia(int x,int y);
void zuo_shang(int x,int y);
void you_xia(int x,int y){
	if(Map[x][y]!=0)
		return;
	int i=x,j=y;
	while(i<=n&&j<=m){
		Map[i][j]='\\';
		i++;j++;
	}
	if(i==n+1&&j==m+1)
		return;
	else if(i==n+1){
		if(e>memory[3]){
			e-=memory[3];
			you_shang(n,j);
		}
	}
	else if(j==m+1){
		if(e>memory[2]){
			e-=memory[2];
			zuo_xia(i,m);
		}
	}
}
void you_shang(int x,int y){
	if(Map[x][y]!=0)
		return;
	int i=x,j=y;
	while(i>=1&&j<=m){
		Map[i][j]='/';
		i--;j++;
	}
	if(i==0&&j==m+1)
		return;
	else if(i==0){
		if(e>memory[1]){
			e-=memory[1];
			you_xia(1,j);
		}
	}
		
	else if(j==m+1){
		if(e>memory[2]){
			e-=memory[2];
			zuo_shang(i,m);
		}
	}
		
}
void zuo_shang(int x,int y){
	if(Map[x][y]!=0)
		return;
	int i=x,j=y;
	while(i>=1&&j>=1){
		Map[i][j]='\\';
		i--;j--;
	}
	if(i==0&&j==0)
		return;
	else if(i==0){
		if(e>memory[1]){
			e-=memory[1];
			zuo_xia(1,j);
		}
	}
	else if(j==0){
		if(e>memory[4]){
			e-=memory[4];
			you_shang(i,1);
		}
	}
}
void zuo_xia(int x,int y){
	if(Map[x][y]!=0)
		return;
	int i=x,j=y;
	while(i<=n&&j>=1){
		Map[i][j]='/';
		i++;j--;
	}
	if(i==n+1&&j==0)
		return;
	else if(i==n+1){
		if(e>memory[3]){
			e-=memory[3];
			zuo_shang(n,j);
		}
	}
	else if(j==0){
		if(e>memory[4]){
			e-=memory[4];
			you_xia(i,1);
		}
	}
		
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();e=read();
	for(int i=1;i<=8;i++)
		memory[i]=read();
	you_xia(1,1);
	printf(" ");
	for(int i=1;i<=m;i++)
		printf("-");
	printf(" \n");
	for(int i=1;i<=n;i++){
		printf("|");
		for(int j=1;j<=m;j++)
			if(Map[i][j]!=0)
				printf("%c",Map[i][j]);
			else
				printf(" ");
		printf("|\n");
	}
	printf(" ");
	for(int i=1;i<=m;i++)
		printf("-");
	printf(" \n");
	return 0;
}
