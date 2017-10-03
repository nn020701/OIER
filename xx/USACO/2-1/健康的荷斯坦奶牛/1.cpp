#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int V,vit[26],G,feed[16][26],vc;
bitset<16> minbit(0);

int main()
{
	vc=17; 
	V=read();
	int in;
	for(int i=0;i!=V;i++)
		vit[i]=read();
	G=read();
	for(int i=0;i!=G;i++)
		for(int j=0;j!=V;j++)
			feed[i][j]=read();
	for(int i=0;i<(1<<G);i++){
		int v[26]={0};
		bitset<16> bit(i);
		for(int b=0;b!=G;b++)
			if(bit[b])
				for(int j=0;j!=V;j++)
					v[j]+=feed[b][j];		
		bool ok=true;
		for(int j=0;j!=V;j++)
			if(v[j]<vit[j]){
				ok=false;
				break;
			}
		if(ok&&int(bit.count())<vc&&bit.to_ulong()>minbit.to_ulong()){
			vc=bit.count();
			minbit=bit;
		}	
	}
	cout<<vc;
	for(int i=0;i!=G;i++)
		if(minbit[i])
			cout<<" "<<i+1;
	cout<<endl;
	return 0;
}
