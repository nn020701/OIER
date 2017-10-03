#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a,b,f,k;
int num,ans;

int main(){
	a = read(); b = read(); f = read(); k = read();
	num = b;
	for(int i = 1;i <= k;i++){
		if(i%2 == 1){
			if(i == k){
				if(num < a){
					if(num < f){
						printf("-1\n");
						return 0;
					}
					ans++;
					num = b;
					if(num < a-f){
						printf("-1\n");
						return 0;
					}
				}
			}
			else{
				if(num < a*2-f){
					if(num < f){
						printf("-1\n");
						return 0;
					}
					num = b;
					ans++;
					if(num < a*2-2*f){
						printf("-1\n");
						return 0;
					}
					num = b-(a-f);
				}
				else{
					num -= a;
				}
			}
		}
		else{
			if(i == k){
				if(num < a){
					if(num < a-f){
						printf("-1\n");
						return 0;
					}
					ans++;
					num = b;
					if(num < f){
						printf("-1\n");
						return 0;
					}
				}
			}
			else{
				if(num < a+f){
					if(num < a-f){
						printf("-1\n");
						return 0;
					}
					num = b;
					ans++;
					if(num < f*2){
						printf("-1\n");
						return 0;
					}
					num = b-f;
				}
				else{
					num -= a;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}