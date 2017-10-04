#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second

//#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN()
{
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

db res;
int n,m,k;

db Calc(int x,int y)
{
	db tx=2.0*x*(n-x+1)-1;
	db ty=2.0*y*(m-y+1)-1;
	return tx*ty/(1.0*n*n*m*m);
}

int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	k=IN(),n=IN(),m=IN();
	For(i,1,n+1) For(j,1,m+1) res+=1-pow(1-Calc(i,j),k);
	printf("%.20lf\n",res);
}
