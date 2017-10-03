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

const int score[20] = {0,-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40,-50};
int a[5];
int num[5];
int pai[5];
int c[5][20];
int S12,D11,C10;

int main(){
	while(1){
		memset(a,0,sizeof a);
		memset(num,0,sizeof num);
		memset(pai,0,sizeof pai);
		memset(c,0,sizeof c);
		S12 = D11 = C10 = 0;
		for(int i = 1;i <= 4;i++){
			scanf("%d",&a[i]);
			for(int j = 1;j <= a[i];j++){
				char s = getchar(); int b;
				while(!(s >= 'A' && s <= 'Z'))
					s = getchar();
				scanf("%d",&b);
				if(s == 'H')
					c[i][++pai[i]] = b;
				else if(s == 'C') C10 = i;
				else if(s == 'S') S12 = i;
				else if(s == 'D') D11 = i;
			}
		}
		bool flag = true;
		for(int i = 1;i <= 4;i++)
			if(a[i] != 0)
				flag = false;
		if(flag) break;
		int p;
		for(int i = 1;i <= 4;i++){
			if(pai[i] == 13){
				num[i] = 200;
				p = i;
				flag = true;
			}
		}
		if(flag){
			if(D11 == p &&S12 == p){
				num[p] = 500;
			}
			else{
				num[D11] += 100;
				num[S12] -= 100;
			}
			if(pai[C10] == 0 && D11 != C10 && S12 != C10) num[C10] = 50; 
			else num[C10] *= 2;
		}
		else{
			for(int i = 1;i <= 4;i++){
				for(int j = 1;j <= pai[i];j++)
					num[i] += score[c[i][j]];
			}
			num[D11] += 100;
			num[S12] -= 100;
			if(pai[C10] == 0 && D11 != C10 && S12 != C10) num[C10] = 50;
			else num[C10] *= 2;
		}
		for(int i = 1;i <= 4;i++)
			if(num[i] > 0) printf("+%d ",num[i]);
			else printf("%d ",num[i]);
		puts("");
	}
	return 0;
}
