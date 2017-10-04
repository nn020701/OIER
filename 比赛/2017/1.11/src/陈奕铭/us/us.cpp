#include<bits/stdc++.h>
using namespace std;
int p,a[101],b[101];
int l1[76],l2[76],l3[76];
string mode="Begin the Escape execution at the Break of Dawn";
int chet=0;
string st;
void go()
{
	cout<<"0 "<<"0\n";
	exit(0);
}
void dfs(string st)
{
	if(st==mode)
       	cout<<"1 "<<p<<"\n";
	int C[20]={0},O[20]={0},W[20]={0},a[50]={0};
    if(chet>=200000)
		go();
    chet++;
    for(int i=0;i<st.length();i++)
	{
		if(st[i]=='C')
		{
			C[++C[0]]=i;
			a[++a[0]]=i;
		}
		if(st[i]=='O')
		{
			O[++O[0]]=i;
			a[++a[0]]=i;
		}
		if(st[i]=='W')
		{
			W[++W[0]]=i;
			a[++a[0]]=i;
		}
    }
    for(int i=1;i<a[0];i++)
		if(mode.find(st.substr(a[i]+1,a[i+1]-a[i]-1))==string::npos)
            return;
    for(int i=1;i<=C[0];i++)
		if(C[i]>W[W[0]])
			return;
    for(int i=1;i<=O[0];i++)
		if(O[i]>W[W[0]]||O[i]<C[1])
			return;
    for(int i=1;i<=W[0];i++)
		if(W[i]<C[1])
			return;
    if(O[1]<C[1]||W[1]<C[1]||O[O[0]]>W[W[0]]||C[C[0]]>W[W[0]])
		return;
    if(st.substr(0,C[1])!=mode.substr(0,C[1]))
		return;
    if(mode.substr(mode.length()-st.length()+W[W[0]]+1,st.length()-W[W[0]]-1)!=st.substr(W[W[0]]+1,st.length()-W[W[0]]-1))
		return;
    for(int j=1;j<st.length();j++)
        if(st[j]=='O')
		{
            int i=j;
            while(i>0)
			{
                i--;
                if(st[i]=='C')
				{
                    int k=st.length();
                    while(k>j+1)
					{
                        k--;
                        if(st[k]=='W')
						{
                            string ss=st;
                            string p1=ss.substr(i+1,j-i-1),p2=ss.substr(j+1,k-j-1);
                            p1=p2+p1;
                            ss.replace(i,k-i+1,p1);
                            dfs(ss);
                        }
                    }
				}
			}
		}
}
int main()
{
	//freopen("us.in","r",stdin);
	//freopen("us.out","w",stdout);
    getline(cin,st);
    for(int i=0;i<mode.length();i++)
        a[mode[i]-'A']++;
    for(int i=0;i<st.length();i++)
        b[st[i]-'A']++;
    if(!(b['C'-'A']==b['O'-'A']&&b['O'-'A']==b['W'-'A']))
		go();
    for(int i=0;i<='z'-'A';i++)
	{
        if(i=='C'-'A'||i=='O'-'A'||i=='W'-'A')
			continue;
        if(a[i]!=b[i])
			go();
    }
    if((st.length()-mode.length())%3!=0)
        go();
    else 
		p=(st.length()-mode.length())/3;
    dfs(st);
    go();
    return 0;
}
