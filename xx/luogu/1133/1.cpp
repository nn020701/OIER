#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int f1[N],f2[N][2],f3[N];
int a[N][4];
int n,ans;

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= 3;j++)
			a[i][j] = read();
	for(int k = 1;k <= 4;k++){
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		memset(f3,0,sizeof f3);
		if(k == 1) f1[1] = a[1][1];
		if(k == 2) f2[1][0] = a[1][2];//默认第一位置的2号树由下降得来 
		if(k == 3) f2[1][1] = a[1][2];//默认第一位置的2号树由上升得来 
		if(k == 4) f3[1] = a[1][3];
		for(int i = 2;i <= n;i++){
			if(f2[i-1][1]) f1[i] = f2[i-1][1]+a[i][1];
			if(f3[i-1]) f1[i] = max(f1[i],f3[i-1]+a[i][1]);
			if(f3[i-1]) f2[i][0] = f3[i-1]+a[i][2];
			if(f1[i-1]) f2[i][1] = f1[i-1]+a[i][2];
			if(f2[i-1][0]) f3[i] = f2[i-1][0]+a[i][3];
			if(f1[i-1]) f3[i] = max(f3[i],f1[i-1]+a[i][3]);
		}
		if(k == 1) ans = max(ans,f2[n][1]),ans = max(ans,f3[n]);//如果第1位置选的1号树，那么答案可能是n号位的3号树或n号位上升的来的2号树 
		if(k == 2) ans = max(ans,f3[n]);//下降得来就是3号树 
		if(k == 3) ans = max(ans,f1[n]);//上升得来就是1号树 
		if(k == 4) ans = max(ans,f2[n][0]),ans = max(ans,f1[n]);//如果第1位置选的3号树，那么答案可能是n号位的1号树或n号位下降的来的2号树 
	}
	printf("%d\n",ans);
	return 0;
}
