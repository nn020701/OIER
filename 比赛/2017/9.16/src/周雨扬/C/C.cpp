#include<bits/stdc++.h>
using namespace std;
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++;
}
int a[105],top,dis[102][11][11],q[15000][3];
int read(){
	char ch=gc(); top=0;
	for (;(ch<'0'||ch>'9')&&ch!='\n'&&ch!=EOF;ch=gc());
	if (ch==EOF) return 233;
	for (;ch>='0'&&ch<='9'&&ch!='\n'&&ch!=EOF;ch=gc()) a[++top]=ch-'0';
	for (;ch!='\n'&&ch!=EOF;ch=gc());
	return 666;
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	while (read()!=233){
		memset(dis,-1,sizeof(dis));
		int h=0,t=1;
		dis[1][5][6]=0; q[1][0]=1; q[1][1]=5; q[1][2]=6;
		while (h!=t){
			int x=q[++h][0];
			int y=q[h][1],z=q[h][2];
			if (x>top){
				printf("%d\n",dis[x][y][z]);
				//printf("%d %d %d\n",x,y,z);
				break;
			}
			for (int i=0;i<=3;i++){
				int ny=y;
				if (i==0) ny--;
				if (i==1) ny++;
				if (ny<1||ny>10) continue;
				if (i==3&&ny%10!=a[x]) continue;
				for (int j=0;j<=3;j++){
					int nz=z;
					if (j==0) nz--;
					if (j==1) nz++;
					if (nz<1||nz>10) continue;
					if (j==3&&nz%10!=a[x]) continue;
					if (i==3&&j==3) continue;
					if (nz<=ny) continue;
					int nx=x+((nz%10==a[x]&&j==3)||(ny%10==a[x]&&i==3));
					if (dis[nx][ny][nz]!=-1) continue;
					dis[nx][ny][nz]=dis[x][y][z]+1;
					q[++t][0]=nx;
					q[t][1]=ny;
					q[t][2]=nz;
				}
			}
		}
	}
}
