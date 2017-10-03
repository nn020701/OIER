#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node
{
	int x,y;
}num[12890];
int n,top;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

void init(){
	top=0;
	for(int i=1;i<=n;i++)
 		for(int j=0;j<=i;j++){
    		int a=j,b=i;
    		if(gcd(a,b)==1){
				num[top].x=a,num[top].y=b;
				top++;
      		}
    	}
}

int cmp(const node &a,const node &b){return (double)a.x/a.y<(double)b.x/b.y;}

int main(void)
{
	n=read();
	init();
	sort(num,num+top,cmp);
	for(int i=0;i!=top;i++) printf("%d/%d\n",num[i].x,num[i].y);
	return 0;
}
