#include<iostream>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<algorithm>
using namespace std;
stringstream ss;
string s,t;
int main(){
	ss<<5;ss>>s;
	cout<<s<<endl;
	ss.clear();
	ss<<"orzJPY"<<333;
	ss>>s;
	cout<<s<<t<<endl;
	return 0;
}
