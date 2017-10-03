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

int x[110],y[110];
bool map[55][55];
int n;
int a,b;

int main(){
	a = read(); b = read(); n = read();
	for(int i = 1;i <= n;i++){
		x[i] = read(); y[i] = read();
		map[x[i]][y[i]] = true;
	}
	bool tr = true;
	for(int i = 1;i <= n;i++){
		bool flag = true;
		for(int j = 1;j <= x[i]-1;j++)
			if(map[j][y[i]])
				flag = false;
		if(flag) continue;
		flag = true;
		for(int j = y[i]+1;j <= b;j++)
			if(map[x[i]][j])
				flag = false;
		if(flag) continue;
		tr = false;
		break;
	}
	if(tr){
		puts("0");
		return 0;
	}
	for(int k = 1;k <= n;k++){
		tr = true;
		map[x[k]][y[k]] = false;
		for(int i = 1;i <= n;i++){
			if(i != k){
				bool flag = true;
				for(int j = 1;j <= x[i]-1;j++)
					if(map[j][y[i]])
						flag = false;
				if(flag) continue;
				flag = true;
				for(int j = y[i]+1;j <= b;j++)
					if(map[x[i]][j])
						flag = false;
				if(flag) continue;
				tr = false;
				break;
			}
		}
		if(tr){
			puts("1");
			printf("%d\n",k);
			return 0;
		}
		map[x[k]][y[k]] = true;
	}
	printf("-1\n");
	return 0;
}
