#include <iostream>

#include <stack>

using namespace std;

stack<int> intstack;

int runround (unsigned long num)
{
    int count_num[10]={0};
    unsigned long temp=num;
    int length=0;
    while (temp>0)
    {
        int i=temp%10;
        intstack.push(i);
        count_num[i]++;
        if (count_num[i]>1)
            return 0;
        temp/=10;
        length++;
    }
    int array[length];
    for (int i=0;i<length;i++)
    {
        array[i]=intstack.top();
        intstack.pop();
    }
    for (int i=0,count=0;count<length;count++)
    {
        i+=array[i];
        while (i>=length)
            i-=length;
        count_num[array[i]]++;
    }
    for (int i=0;i<10;i++)
        if (count_num[i]!=0&&count_num[i]!=2)
            return 0;
    return 1;
}
int main()
{
    unsigned long n;
    cin>>n;
    unsigned long i=n+1;
    for (;runround(i)==0;i++);
    cout<<i<<endl;
    return 0;
}
