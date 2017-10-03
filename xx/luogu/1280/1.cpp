#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 10005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}


struct node{
	int x,t;
	friend bool operator <(node a,node b){
		return a.x > b.x || (a.x == b.x && a.t > b.t);
	}
}a[N];
int f[N];
int num[N];
int n,k,top = 1;

int main(){
	n = read(); k = read();
	for(int i = 1;i <= k;i++){
		scanf("%d%d",&a[i].x,&a[i].t);
		num[a[i].x]++;
	}
	sort(a+1,a+k+1);
	for(int i = n;i >= 1;i--){
		if(num[i] == 0)
			f[i] = f[i+1]+1;
		else
			for(int j = 1;j <= num[i];j++,top++)
				f[i] = max(f[i],f[i+a[top].t]);
	}
	printf("%d\n",f[1]);
	return 0;
}