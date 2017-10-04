//by mfhraven
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LL long long

using namespace std;
const int maxn=100000000;
LL ans[12001],nans[12001],mid[12001];
LL res[12001],flag[12001],num[12001],s[12001];
int n,Len,st;

int check()
{
	int pos=1;  int pow=1;  nans[1]=0;
	for (int i=1;i<=st;i++)
	{
		nans[pos]+=ans[i]*pow;
		pow*=10;
		if (!(i%8)) pos++,pow=1,nans[pos]=0;
	}
	for (;!nans[pos];pos--);	nans[0]=pos;
	
	for (int i=1;i<=res[0];i++) res[i]=0;
	res[0]=1;   res[1]=1;
	for (int i=1;i<=n;i++)
	{
		for (int i=1;i<=mid[0];i++) mid[i]=0;   mid[0]=0;
		
		for (int i=1;i<=nans[0];i++)
		for (int j=1;j<=res[0];j++)
		mid[i+j-1]+=nans[i]*res[j];
		
		mid[0]=nans[0]+res[0]-1;	int j=1;
		for (;mid[j] || j<=mid[0];j++)
			if (mid[j]>=maxn)   mid[j+1]+=mid[j]/maxn,mid[j]%=maxn;
		
		mid[0]=j;
		//if (mid[0]>Len) return 0;
		for (int i=0;i<=mid[0];i++) res[i]=mid[i];
	}
	
	for (int i=1;i<=flag[0];i++)	flag[i]=0;  flag[0]=0;
	for (int i=1;i<=res[0];i++)
	for (int j=1;j<=8;j++)  
	flag[++flag[0]]=res[i]%10,res[i]/=10;
	
	for (;!flag[flag[0]];flag[0]--);
	
	if (flag[0]>Len)	return 0;
	
	int i=Len;
	for (;flag[i]==num[i] && i;i--);
	
	if (flag[i]<=num[i] || !i) return 1;
	else							return 0;
}

int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%d",&n); char c=getchar();	Len=0;
	for (char c=getchar();c>='0' && c<='9';c=getchar())  s[++Len]=c-'0';
	
	for (int i=1;i<=Len;i++)					num[Len-i+1]=s[i];
	
	if (n==1)
	{
		for (int i=1;i<=Len;i++)				printf("%d",s[i]);
		printf("\n");
		
		return 0;
	}
	
	st=(Len/n)+3;   ans[0]=st;
	int zzy=0;
	for (int i=st;i>=1;i--)
	{
		int l=0;			int r=10;
		for (;l+1!=r;)
		{
			int mid=(l+r)>>1;   ans[i]=mid;
			if (check())		l=mid;
			else				r=mid; 
			++zzy;
		}
		
		ans[i]=l;
		if (zzy>100)break;
	}
	
	for (;!ans[st] && st>=0;st--);
	for (int i=st;i>=1;i--) printf("%d",ans[i]);
	if (st<=0)printf("0\n");
	printf("\n");
}


