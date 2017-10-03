//单纯的暴力模拟 
#include<map>
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

int a,b;
int ans,fa,fb,p;
int ans_fa,ans_fb;
map<int,bool> mp;

int main(){
	a = read(); b = read();
	fb++; p = b;
//	printf("%d %d\n",fa,fb);
//	printf("%d %d\n",ans_fa,ans_fb);
	ans = p;
	ans_fa = 0;
	ans_fb = 1;
	mp[p] = true;
	while(1){
		fb += (a-p)/b+1;
		fa += (p+b*((a-p)/b+1))/a;
		p = (p+b*((a-p)/b+1))%a;
//		printf("%d\n",p);
		if(p == 0) break;
		if(ans > p){
			ans = p;
			ans_fb = fb;
			ans_fa = fa;
		}
		if(ans == 1) break;
		if(mp[p]) break;
		mp[p] = true;
	}
	printf("%d\n",ans);
	printf("%d %d\n",ans_fa,ans_fb);
	return 0;
}
