#include		<iostream>
#include		<cstdio>
#include		<cstdlib>
#include		<cstring>
#define   Maxn 10001
using namespace std;
int a[Maxn],W[10];
char ss[Maxn],s[Maxn],Sans[Maxn];
int i,j,n,m,len,ans,k,l;
void			change1(int x,int y,int tot)
{
	for ( int i=0;i<len;i++)
	{
		if (ss[i]-48==x) {
			ss[i]=char(y+48);
			tot--;
			if (!tot) return;
		}
 
	}
}
void			change2(int x,int y,int tot)
{
	for ( int i=len-1;len>=0;i--)
	{
		if (ss[i]-48==x) {
			ss[i]=char(y+48);
			tot--;
			if (!tot) return;
		}
 
	}
}
int main()
{
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	scanf("%d %d\n",&n,&k);
	gets(s);
	len=strlen(s);
	for (i=0;i<len;i++){
		W[s[i]-48]++;
		Sans[i]=s[i];
		if (W[s[i]-48]>=k) 
		{ 
               cout<<0<<endl;
               printf("%s",s);
               return 0;
        }
	}
	m=999999999;
	for (i=0;i<10;i++)
	{
		l=0;
		for (j=0;j<len;j++) ss[j]=s[j];
		for (j=0;j<10;j++) a[j]=W[j];
		ans=0;
		while (l<10 && a[i]<k)
		{
			l++;
            if (i+l<=9 && a[i+l]>0 && a[i]<k)
			{
				if (a[i+l]+a[i]<k)
				{
					a[i]=a[i]+a[i+l];
					change1(i+l,i,a[i+l]);
					ans+=l*a[i+l];
				} 			else
				{	
					change1(i+l,i,k-a[i]);
					ans+=l*(k-a[i]);a[i]=k;
				}
			}
			if (i-l>=0 && a[i-l]>0 && a[i]<k)
			{
				if (a[i-l]+a[i]<k)
				{
					a[i]=a[i-l]+a[i];
					change2(i-l,i,a[i-l]);
					ans+=l*a[i-l];
				}			else
				{
					change2(i-l,i,k-a[i]);
					ans+=l*(k-a[i]);a[i]=k;
				}
			}
		}
		if (a[i]>=k &&(m>ans || m==ans && (strcmp(ss,Sans)<0)))
		{
			m=ans;
			for (j=0;j<len;j++) Sans[j]=ss[j];
		}
	}
	
	printf("%d\n",m);	
	printf("%s",Sans);
	fclose(stdout);
	return 0;

}
