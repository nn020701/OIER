#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 12
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int step_x[4] = {-1,0,1,0};
const int step_y[4] = {0,1,0,-1};
/*struct node{
	int x1,y1,f1;
	int x2,y2,f2;
	int ans;
	node(int _x1,int _y1,int _f1,int _x2,int _y2,int _f2,int _ans){
		x1 = _x1; y1 = _y1; f1 = _f1; x2 = _x2; y2 = _y2; f2 = _f2; ans = _ans; 
	}
	node(){}
};*/
int n,ans;
int a[N][N];
bool mp[N][N][4][N][N][4];

bool check(int x,int y){
	if(x <= 0 || x > n || y <= 0 || y > n) return true;
	return false;
}

int main(){
	n = 10;
	int x1,y1,f1;
	int x2,y2,f2;
	for(int i = 1;i <= n;i++){
		char c[20];
		scanf("%s",c+1);
		for(int j = 1;j <= n;j++){
			if(c[j] == '.') a[i][j] = 0;
			else if(c[j] == '*') a[i][j] = 1;
			else if(c[j] == 'C') x1 = i,y1 = j,f1 = 0;
			else x2 = i,y2 = j,f2 = 0;
		}
	}
	for(int i = 0; ;i++){
		if(x1 == x2 && y1 == y2){
			ans = i;
			break;
		}
		if(mp[x1][y1][f1][x2][y2][f2]) break;
		mp[x1][y1][f1][x2][y2][f2] = true;
		int xx1 = x1 + step_x[f1],yy1 = y1 + step_y[f1];
		int xx2 = x2 + step_x[f2],yy2 = y2 + step_y[f2];
		if(check(xx1,yy1) || a[xx1][yy1]) f1 = (f1+1)%4;
		else{ x1 = xx1; y1 = yy1; }
		if(check(xx2,yy2) || a[xx2][yy2]) f2 = (f2+1)%4;
		else{ x2 = xx2; y2 = yy2; }
	}
	printf("%d\n",ans);
	return 0;
}
