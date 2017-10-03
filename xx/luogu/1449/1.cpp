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

int Scarlet[1010],Flandre;

int main(){
	char ch = getchar();
	int x;
	while(ch != '@'){
		if(ch >= '0' && ch <= '9'){
			x = 0;
			while(ch >= '0' && ch <= '9'){
				x = x*10+ch-'0';
				ch = getchar();
			}
			Scarlet[++Flandre] = x;
		}
		if(ch == '.') ch = getchar();
		if(ch == '*'){
			x = Scarlet[Flandre--];
			x *= Scarlet[Flandre--];
			Scarlet[++Flandre] = x;
			ch = getchar();
		}
		if(ch == '/'){
			x = Scarlet[Flandre--];
			x = Scarlet[Flandre--]/x;
			Scarlet[++Flandre] = x;
			ch = getchar();
		}
		if(ch == '+'){
			x = Scarlet[Flandre--];
			x += Scarlet[Flandre--];
			Scarlet[++Flandre] = x;
			ch = getchar();
		}
		if(ch == '-'){
			x = Scarlet[Flandre--];
			x = Scarlet[Flandre--]-x;
			Scarlet[++Flandre] = x;
			ch = getchar();
		}
	}
	printf("%d\n",Scarlet[Flandre]);
	return 0;
}