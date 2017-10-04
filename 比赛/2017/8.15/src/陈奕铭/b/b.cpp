#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
#define poi(x,y) ((x)*m+y)
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

struct node{
	int num[10];
	node operator +(node b){
		node p;
		for(int i = 0;i < 10;i++)
			p.num[i] = num[i]+b.num[i];
		return p;
	}
	node operator -(node b){
		node p;
		for(int i = 0;i < 10;i++)
			p.num[i] = num[i]-b.num[i];
		return p;
	}
}c[N],p;
int n,m;
int sum;
int a[N];

bool check(node p,int x,int y){
	if(p.num[0] == x*y) return false;	
	if(x*y % 2 != 0 ){
		if(x*y > 1 && p.num[0] == x*y-1) return false;
		bool flag = false;
		for(int i = 0;i < 10;i++)
			if(p.num[i]%2 != 0){
				if(!flag) flag = true;
				else return false;
			}
	}
	else{
		for(int i = 0;i < 10;i++)
			if(p.num[i]%2 != 0)
				return false;
	}
	return true;
}

void work(int x){
	for(int y = m;y >= 1;y--)			//枚举宽 
		for(int i = 1;i <= n-x+1;i++)		//枚举左上角纵坐标 
			for(int j = 1;j <= m-y+1;j++){	//枚举左上角横坐标 
				p = c[poi(i+x-1,j+y-1)]+c[poi(i-1,j-1)]-c[poi(i+x-1,j-1)]-c[poi(i-1,j+y-1)];
				if(check(p,x,y)){
					sum = max(sum,x*y);
					if(sum >= (x-1)*m){
						printf("%d\n",sum);
						exit(0);
					}
					return;			//在长相同的情况下，没有比现在更大的了 
				}
			}
}

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			a[poi(i,j)] = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			c[poi(i,j)] = c[poi(i-1,j)]+c[poi(i,j-1)]-c[poi(i-1,j-1)];
			c[poi(i,j)].num[a[poi(i,j)]]++;
		}
	for(int x = n;x >= 1;x--)		//枚举长 
		work(x);
	printf("%d\n",sum);
	return 0;
}
