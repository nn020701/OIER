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

bool cmp1(const int &a,const int &b){return a<b;}

bool cmp2(const int &a,const int &b){return a>b;}

int main()
{
    int m,s1,c,i;
    int a[210],b[210],sum;
    m=read();s1=read();c=read();
    for(i=0;i<c;i++) a[i]=read();
    sort(a,a+c,cmp1); 
    if(m>=c){
        cout<<c<<endl;
        return 0;
    }
    for(i=0;i<c-1;i++) b[i]=a[i+1]-a[i]-1;
    sort(b,b+c-1,cmp2);
    sum=a[c-1]-a[0]+1;
    for(i=0;i<m-1;i++) sum=sum-b[i];
    cout<<sum<<endl;  
    return 0;
}
