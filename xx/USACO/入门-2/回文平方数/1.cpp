#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int w,a[20];

int turn(int n){
    memset(a,0,sizeof(a)); 
    int i=0,j;
    while(n>0){
        a[++i]=n%w;
        n/=w;
    }
    return i;    
}

bool judge(int x){
    int i=1,j=x;
    while(i<j) if(a[i++]!=a[j--]) return false;
    return true;
}

void print(int n){
    int b[20],i=0,j;
    while(n>0){
        b[++i]=n%w;
        n/=w;
    }
    for(j=i;j>=1;j--){
        if(b[j]>=10) printf("%c",'A'+b[j]-10);
        else printf("%d",b[j]);
    }
    printf(" ");
}

void search(){
    int i,j;
    for(i=1;i<=300;i++){
        int x=turn(pow(i,2));
        if(judge(x)){
            print(i);
            for(j=x;j>=1;j--){
                if(a[j]>=10) printf("%c",'A'+a[j]-10);
                else printf("%d",a[j]);
            }
            printf("\n");
        }
    }    
}
int main()
{
    int i,j;
    w=read();
    search();
    return 0;
}
