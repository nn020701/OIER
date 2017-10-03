#include<stdio.h>
int main() 
{    int a,b,n,m,i,j,s=0,ans=0,x=1;
    char c;
    scanf("%d%c",&a,&c);
    while(c!='\n')
    {    if(c=='+')
        {    x*=a;
            ans+=x;
            x=1;
            s=0;
        }
        else
        {    x*=a;
            x%=10000;
            s=1;
        }
        ans%=10000;
        scanf("%d%c",&a,&c);
    }
    if(s)
        printf("%d",(ans+x*a)%10000);
    else 
        printf("%d",(ans+a)%10000);
    return 0;
}
