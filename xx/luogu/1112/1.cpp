#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 10000005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int num[N];
int a,b,x,y,k;

int len(int x,int k){
	int leng = 0;
	while(x){
		leng++;
		x /= k;
	}
	return leng;
}

int moni(int a,int b,int len,int k){
	int ans = 0;
	for(int i = 1;i <= len;i++){
		if(i%2 == 1) ans = ans*k+a;
		else ans = ans*k+b;
	}
	return ans;
}

void gouZao(int k){
	int l = len(x,k),r = len(y,k);
	for(int i = 1;i < k;i++)
		for(int j = 0;j < k;j++)
			if(i != j)
				for(int w = l;w <= r;w++){
					int p = moni(i,j,w,k);
					if(p >= x && p <= y)
						num[p]++;
				}
}

int main(){
	a = read(); b = read();
	x = read(); y = read();
	k = read();
	for(int i = a;i <= b;i++) gouZao(i);
	for(int i = x;i <= y;i++)
		if(num[i] == k){
			printf("%d\n",i);
		}
	return 0;
}
