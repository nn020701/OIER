#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	vector<int> v1;
	vector<int> v2;
	v1.push_back(101);
/*	v1.push_back(102);
	v2.push_back(20);
	v2.push_back(301);*/
	cout<<v1.max_size()<<endl;
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<endl;
	v2.assign(2,9);
	for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<endl;
	/*if(v1>v2)
		cout<<"v1>v2";
	else if(v1<v2)
		cout<<"v1>v2";
	else
		cout<<"v1=v2";*/
	return 0;
}
