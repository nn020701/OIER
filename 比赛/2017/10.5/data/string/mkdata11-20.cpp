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
char S[20],T[30];
char s[10005][1005];
int n,l,r,Cnt;
int b[30],be[1000005],que[10005];
int main(){
	srand(925638417);
	S[0]='s'; S[1]='t'; S[2]='r';
	S[3]='i'; S[4]='n'; S[5]='g';
	S[8]='.'; S[9]='i'; S[10]='n';
	for (int i=1;i<=26;i++) b[i]=(int)(pow(1.5,i));
	for (int i=1;i<=26;i++) T[i]='a'+i-1;
	for (int i=1;i<=26;i++)
		for (int j=1;j<=b[i];j++) be[++Cnt]=i;
	for (int p=11;p<=20;p++){
		S[6]='0'+p/10,S[7]='0'+p%10;
		freopen(S,"w",stdout); 
		int n=2500+rnd()%500;
		printf("%d ",n);
		if (p<=14) printf("1\n");
		else if (p<=18) printf("10\n");
		else printf("%d\n",200);
		for (int i=2;i<=26;i++) swap(T[i],T[rnd()%(i-1)+1]);
		int cnt=1000000/n;
		for (int i=1;i<=n;i++){
			que[i]=i;
			if (i%300==1)
				for (int j=1;j<=cnt;j++)
					s[0][j]=T[be[rnd()%Cnt+1]];
			memcpy(s[i],s[0],sizeof(s[0]));
			for (int j=1;j<=5;j++)
				s[i][rnd()%cnt+1]=T[be[rnd()%Cnt+1]];
		}
		random_shuffle(que+1,que+n+1);
		for (int i=1;i<=n;puts(""),i++)
			for (int j=1;j<=cnt;j++) putchar(s[que[i]][j]);
		if (p<=14) printf("%d\n",1);
		else if (p<=18) for (int i=1;i<=10;i++) printf("%d\n",i);
		else for (int i=1;i<=200;i++) printf("%d\n",i);
		fclose(stdout);
	}
}
