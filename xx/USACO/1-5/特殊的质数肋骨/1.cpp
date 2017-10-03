#include<fstream>
#include<cmath>
#include<iostream>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct Element{
	int pos;
	int shuju[4];
	Element(){
		pos=0;
		shuju[0]=1;
		shuju[1]=3;
		shuju[2]=7;
		shuju[3]=9;
	}
};

bool isPrime(int i);
Element wei[8];

bool isPrime(int i)
{
	bool tag=true;
	int place=(int)sqrt((double)i);
	int value;
	for(int j=3;j<=place;j+=2){
		if(i%j==0){
			tag=false;
			break;
		}
	}
	return tag;
}

int main()
{
	int N;
	int which=1;
	unsigned value;
	int i=0;
	unsigned temp=1;
	N=read();
	wei[0].shuju[0]=2;
	wei[0].shuju[1]=3;
	wei[0].shuju[2]=5;
	wei[0].shuju[3]=7;
	for(int j=0;j!=N;++j) temp=temp*10;
	value=wei[0].shuju[0];
	while(true)
		if(wei[which].pos<=3){
			value=value*10+wei[which].shuju[wei[which].pos];
			if(isPrime(value)){
				if(which!=N-1) which++;
				else{
					if(value<temp)
						cout<<value<<endl;
					wei[which].pos++;
					value=value/10;
				}
			}else{
				wei[which].pos++;
				value=value/10;
			}
		}else{
			wei[which].pos=0;
			which--;
			if(which<0) break;
			value=value/10;
			wei[which].pos++;
		}
	return 0;
}
