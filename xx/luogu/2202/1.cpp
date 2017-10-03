#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 50005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,ans;
struct node{
	int x,y;
}a[N];

bool cmp(node a,node b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main(){
	n = read(); k = read();
	for(int i = 1;i <= n;i++){
		a[i].x = read(); a[i].y = read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1,j = 1;i <= n;i++){
		for(;j < i;j++)
			if(a[i].x - a[j].x < k)
				break;
		for(int z = j;z < i;z++)
			if(abs(a[z].y-a[i].y) < k)
				if(ans == 0){
					int shang = min(a[i].y+k/2,a[z].y+k/2);
					int xia = max(a[i].y-k/2,a[z].y-k/2);
					int you = min(a[i].x+k/2,a[z].x+k/2);
					int zuo = max(a[i].x-k/2,a[z].x-k/2);
					ans = (shang-xia)*(you-zuo);
				}
				else{
					ans = -1;
					break;
				}
		if(ans == -1)
			break;
	}
	printf("%d\n",ans);
	return 0;
}
