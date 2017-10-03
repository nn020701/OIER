#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int low,top;
int lenl,lent;
int a[11]= {1,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int zs(int x){
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}

int len(int x){
	int i=0;
	while(x>=10){
		i++;
		x/=10;
	}
	return i+1;
}

int rev(int x,int lenx){
	int i;
	int y=x/a[lenx];
	for(i=2; i<=lenx; i++) {
		int xi=x/a[lenx-i+1]%10;
		y=y+xi*a[i];
	}
	return y;
}

int makenum(int num,int lennum){
	int y=0,i;
	for(i=1;i<=lennum;i++)
		y=y*10+num;
	return y;
}

void pa(int begin,int end){
	int i,j,k;
	for(i=begin;i<=end;i++)
		if(i%2==1)
			for(j=makenum(1,i/2)-makenum(1,i/2-1);j<=makenum(9,i/2);j+=1){
				int lenj=len(j);
				int rj=rev(j,len(j));
				for(k=0;k<=9;k++){
					int fnum=0;
					fnum=j*a[lenj+2]+k*a[lenj+1]+rj;
					if(fnum>top) break;
					if(fnum>=low&&zs(fnum)==1) cout<<fnum<<endl;
				}
			}
}

int main(){
	low=read(); top=read();
	if(low==5) cout<<"5\n7\n11"<<endl;
	else if(low==6||low==7) cout<<"7\n11"<<endl;
	else if(low>=8&&low<=11) cout<<"11"<<endl;
	lenl=len(low);
	if(lenl<=2) lenl=3;
	lent=len(top);
	pa(lenl,lent);
	return 0;
}
