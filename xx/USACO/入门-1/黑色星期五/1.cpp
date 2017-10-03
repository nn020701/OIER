#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int pd(int year)
{
	if((year%400==0)||(year%4==0 && year%100!=0))
		return 1;
    return 0;
}
int n;
int thirteen[10];
int main()
{
	cin>>n;
	int day=1,fday;
	int now=1;
	for(int i=1900;i<=1900+n-1;i++)
		for(int j=1;j<=12;j++)
		{
			if(j==2)
				fday=pd(i)+month[j];
			else
				fday=month[j];
			while(day<=fday)
            {
                if(now==8)
                    now=1;
                if(day==13)
                    thirteen[now]++;
                now++;
                day++;
            }
            day=1;
		}
	cout<<thirteen[6]<<" "<<thirteen[7]<<" "<<thirteen[1]<<" "<<thirteen[2]<<" "<<thirteen[3]<<" "<<thirteen[4]<<" "<<thirteen[5]<<" \n";
	return 0;
}
