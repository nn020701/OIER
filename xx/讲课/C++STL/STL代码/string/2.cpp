#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;

char ss[20];
char s[20];
int a=5;

int main(){
	sprintf(ss,"%d",a);
	sscanf(ss,"%s",s);
	printf("%s\n",s);
	sprintf(ss,"orzJPY333");
	sscanf(ss,"%s",s);
	printf("%s\n",s);
	return 0;
}
