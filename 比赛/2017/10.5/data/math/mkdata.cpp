#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mo 43219846132874629LL
using namespace std;
long long rnd(){
	long long s=0;
	for (int i=1;i<=20;i++)
		s=(s*10+rand())%mo;
	return s;
}
char s[20];
int n,l,r; 
int main(){
	srand(925638417);
	s[0]='m'; s[1]='a'; s[2]='t'; s[3]='h';
	for (int p=1;p<=20;p++){
		if (p<=9) s[5]='.',s[6]='i',s[7]='n';
		else s[6]='.',s[7]='i',s[8]='n';
		if (p<=9) s[4]='0'+p;
		else s[4]='0'+p/10,s[5]='0'+p%10;
		freopen(s,"w",stdout); 
		printf("%d\n",5);
		for (int lzh=5;lzh;lzh--){
			int klim,nlim,k;
			if (p<=3) nlim=3;
			else if (p<=7) nlim=6;
			else nlim=17;
			printf("%d",9);
			for (int i=2;i<=nlim;i++)
				printf("%d",rnd()%10);
			printf(" ");
			if (p==8||p==9||p==10) printf("1 0");
			else if (p==11||p==12||p==13) printf("2 %d",rnd()&1);
			else{
				if (p<=19) klim=2;
				else klim=3;
				k=4;
				for (int i=2;i<=klim;i++)
					k=k*10+rnd()%10;
				printf("%d %d",k,rnd()%k);
			}
			puts("");
		}
		fclose(stdout);
	}
}
