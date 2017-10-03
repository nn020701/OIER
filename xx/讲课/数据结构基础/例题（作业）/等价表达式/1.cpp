#include<cstdio>
#include<cstring>
#define INF 1000000007
#define x1 17
#define x2 29
int i,p,n,m,topnum=0,topsym=0;
long long ansa,ansb;
char a[51],sym[51];
struct expression
{
    long long y1,y2;
}num[51];
short level(char ch)
{
    switch (ch)
    {
        case '+': return 1; break;
        case '-': return 1; break;
        case '*': return 2; break;
        case '^': return 3; break;
        case '(': return 0; break;
    } 
}
void calc(char ch)
{
    long long a1=num[topnum-1].y1,b1=num[topnum].y1;
    long long a2=num[topnum-1].y2,b2=num[topnum].y2;
    if(ch=='+')
    {
        num[topnum-1].y1=(a1+b1)%INF;
        num[--topnum].y2=(a2+b2)%INF;
    }
    else if(ch=='-')
    {
        num[topnum-1].y1=(a1-b1)%INF;
        if(num[topnum-1].y1<0)
			num[topnum-1].y1+=INF;
        num[--topnum].y2=(a2-b2)%INF;
        if(num[topnum].y2<0)
			num[topnum].y2+=INF;
    }
    else if(ch=='*')
    {
        num[topnum-1].y1=(a1%INF*b1)%INF;
        num[--topnum].y2=(a2%INF*b2)%INF;
    }
    else if(ch=='^')
    {
        long long cnt=a1;
        for(int i=1;i<b1;i++)
        	cnt=(cnt*a1)%INF;
        num[topnum-1].y1=cnt;
        cnt=a2;
        for(int i=1;i<b2;i++)
        	cnt=(cnt*a2)%INF;
        num[--topnum].y2=cnt;
    }
}
void work()
{
    gets(a);
    m=strlen(a);
    p=0;
    while(p<m)
    {
        if(a[p]==' ')
		{
			p++;
			continue;
		}
        if(a[p]>='0'&&a[p]<='9')
        {
            int x=a[p++]-'0';
            while(a[p]>='0'&&a[p]<='9')
            	x=10*x+a[p++]-'0';
            p--;
            num[++topnum].y1=x;
			num[topnum].y2=x;
        }
        else if(a[p]=='a')
        {
            num[++topnum].y1=x1;
			num[topnum].y2=x2;
        }
        else if(a[p]=='(') 
			sym[++topsym]='(';
        else if(a[p]==')') 
        {
            while(topsym>1&&sym[topsym]!='(')
            	calc(sym[topsym--]);
            if(topsym>=1) 
				topsym--;
        }
        else if(topsym==0 || level(sym[topsym])<level(a[p])) 
            sym[++topsym]=a[p];
        else
        {
            calc(sym[topsym--]);
            while(topsym>0 && level(sym[topsym])>=level(a[p]))
            	calc(sym[topsym--]);
            sym[++topsym]=a[p];
        }
        p++;
    }
    while(topsym>0)
    	calc(sym[topsym--]);        
}
int main()
{  
    work();
    ansa=num[1].y1;
    ansb=num[1].y2;
    topnum=0;
    scanf("%d",&n);
    gets(a);
    for(i=0;i<n;i++)
    {        
        work();
        if(num[1].y1==ansa&&num[1].y2==ansb)
        	printf("%c",'A'+i);
        topnum=0;
    }
    return 0;
}
