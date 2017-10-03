#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

inline void write(int x){
	if(x<0) {putchar('-'); x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

void writeln(int x){
	write(x);
	puts("");
}

const int N=10010;
int n,m;
int color[N],f[N];
vector<int> e[N];

int dfs(int x,int fa){
	int b=0,w=0,q=0;
	if(x<=m){
		return color[x];
	}
	else{
		for(int i=0;i<e[x].size();i++)
			if(e[x][i]!=fa){
				int p=dfs(e[x][i],x);
				if(p==0) b++;
				else if(p==1) w++;
				else q++;
				f[x]+=f[e[x][i]];
			}
		if(b>w)		{color[x]=0; f[x]-=b+q-1;}
		else if(w>b){color[x]=1; f[x]-=w+q-1;}
		else 		{color[x]=-1; f[x]-=w+q-1;}
		return color[x];
	}
}

int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		color[i]=read();
		f[i]=1;
	}
	int a,b;
	for(int i=1;i<n;i++){
		a=read(); b=read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(m+1,0);
	for(int i = 1;i <= n;++i){
		printf("%d\n", f[i]);
	}
	printf("%d\n",f[m+1]);
	return 0;
}