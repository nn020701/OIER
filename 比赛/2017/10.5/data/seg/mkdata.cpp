#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define int unsigned int
using namespace std;
int rnd(){
	int s=0;
	for (int i=1;i<=20;i++)
		s=s*10+rand();
	return s;
}
inline void write(int x){
	static int a[12],top;
	top=0;
	for (;x;a[++top]=x%10,x/=10);
	for (;top;top--) putchar('0'+a[top]);
}
char s[20];
int n;
signed main(){
	srand(925638417);
	s[0]='s'; s[1]='e'; s[2]='g'; 
	s[5]='.'; s[6]='i'; s[7]='n'; 
	for (int p=1;p<=10;p++){
		s[3]='0'+p/10; s[4]='0'+p%10;
		freopen(s,"w",stdout);
		if (p<=4) n=3000;
		else if (p<=8) n=100000;
		else n=500000;
		int q=n-(rnd()%(int)(0.1*n));		
		n=n-(rnd()%(int)(0.1*n));
		write(n); putchar(' '); write(q); puts("");
		for (int i=1;i<=n;i++)
			write(rnd()),putchar(' ');
		puts("");
		for (int i=1;i<=q;i++)
			if (rand()%3==2) putchar('1'),putchar(' '),write(rnd()%n+1),putchar(' '),write(rnd()),puts("");
			else{
				int l=rnd()%(n/2)+1,r=n/2+rnd()%(n-n/2)+1;
				if (l>r) swap(l,r);
				putchar('2'),putchar(' '),write(l),putchar(' '),write(r),puts("");
			}
		fclose(stdout);
	}
}
