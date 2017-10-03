#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
    return x*f;
}

struct point{
    int l,r;
    int sum1,sum0;
    int lsum1,rsum1,lsum0,rsum0;
    int maxsum1,maxsum0;
    bool lazy;
    int a;
}t[400005];
int x[100005];
int n,m;

void update(int num){
    int l = num<<1,r = num<<1|1;
    t[num].sum1 = t[l].sum1+t[r].sum1;
    t[num].sum0 = t[l].sum0+t[r].sum0;
    if(t[r].rsum1 == t[r].r-t[r].l+1)
        t[num].rsum1 = t[l].rsum1+t[r].rsum1;
    else t[num].rsum1 = t[r].rsum1;
    if(t[l].rsum1 == t[l].r-t[l].l+1)
        t[num].lsum1 = t[l].lsum1+t[r].lsum1;
    else t[num].lsum1 = t[l].lsum1;
    t[num].maxsum1 = max(t[l].maxsum1,t[r].maxsum1);
    t[num].maxsum1 = max(t[l].rsum1+t[r].lsum1,t[num].maxsum1);
    
    if(t[r].rsum0 == t[r].r-t[r].l+1)
        t[num].rsum0 = t[l].rsum0+t[r].rsum0;
    else t[num].rsum0 = t[r].rsum0;
    if(t[l].rsum0 == t[l].r-t[l].l+1)
        t[num].lsum0 = t[l].lsum0+t[r].lsum0;
    else t[num].lsum0 = t[l].lsum0;
    t[num].maxsum0 = max(t[l].maxsum0,t[r].maxsum0);
    t[num].maxsum0 = max(t[l].rsum0+t[r].lsum0,t[num].maxsum0);        
    return;
}

void downdate(int num){
    int l = num<<1,r = num<<1|1;
    if(t[num].a == 1){
        t[l].a = t[r].a = 1;
        t[num].a = -1;
        t[l].lsum1 = t[l].rsum1 = t[l].sum1 = t[l].maxsum1 = t[l].r-t[l].l+1;
        t[l].lsum0 = t[l].rsum0 = t[l].sum0 = t[l].maxsum0 = 0;
        t[r].lsum1 = t[r].rsum1 = t[r].sum1 = t[r].maxsum1 = t[r].r-t[r].l+1;
        t[r].lsum0 = t[r].rsum0 = t[r].sum0 = t[r].maxsum0 = 0;
        t[l].lazy = t[r].lazy = false;
    }
    if(t[num].a == 0){
        t[l].a = t[r].a = 0;
        t[num].a = -1;
        t[l].lsum1 = t[l].rsum1 = t[l].sum1 = t[l].maxsum1 = 0;
        t[l].lsum0 = t[l].rsum0 = t[l].sum0 = t[l].maxsum0 = t[l].r-t[l].l+1;
        t[r].lsum1 = t[r].rsum1 = t[r].sum1 = t[r].maxsum1 = 0;
        t[r].lsum0 = t[r].rsum0 = t[r].sum0 = t[r].maxsum0 = t[r].r-t[r].l+1;
        t[l].lazy = t[r].lazy = false;
    }
    if(t[num].lazy){
        t[num].lazy = false;
        t[l].lazy = !t[l].lazy;
        t[r].lazy = !t[r].lazy;
        swap(t[l].sum0,t[l].sum1);
        swap(t[l].lsum0,t[l].lsum1);
        swap(t[l].rsum0,t[l].rsum1);
        swap(t[l].maxsum0,t[l].maxsum1);
        swap(t[r].sum0,t[r].sum1);
        swap(t[r].lsum0,t[r].lsum1);
        swap(t[r].rsum0,t[r].rsum1);
        swap(t[r].maxsum0,t[r].maxsum1);        
    }
    return;
}

void build(int l,int r,int num){
    t[num].l = l;
    t[num].r = r;
    t[num].a = -1;
    t[num].lazy = false;
    if(l == r){
        if(x[l] == 1){
            t[num].sum1 = t[num].lsum1 = t[num].rsum1 = t[num].maxsum1 = 1;
            t[num].sum0 = t[num].lsum0 = t[num].rsum0 = t[num].maxsum0 = 0;
        }
        else{
            t[num].sum1 = t[num].lsum1 = t[num].rsum1 = t[num].maxsum1 = 0;
            t[num].sum0 = t[num].lsum0 = t[num].rsum0 = t[num].maxsum0 = 1;            
        }
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,num<<1);
    build(mid+1,r,num<<1|1);
    update(num);
    return;
}

void change0(int l,int r,int x,int y,int num){
    if(l >= x && r <= y){
        t[num].a = 0;
        t[num].lsum1 = t[num].rsum1 = t[num].maxsum1 = t[num].sum1 = 0;
        t[num].lsum0 = t[num].rsum0 = t[num].maxsum0 = t[num].sum0 = r-l+1;
        t[num].lazy = false;
        return;
    }
    downdate(num);
    int mid = (l+r)>>1;
    if(mid < y) change0(mid+1,r,x,y,num<<1|1);
    if(mid >= x) change0(l,mid,x,y,num<<1);
    update(num);
    return;
}

void change1(int l,int r,int x,int y,int num){
    if(l >= x && r <= y){
        t[num].a = 1;
        t[num].lsum1 = t[num].rsum1 = t[num].maxsum1 = t[num].sum1 = r-l+1;
        t[num].lsum0 = t[num].rsum0 = t[num].maxsum0 = t[num].sum0 = 0;
        t[num].lazy = false;
        return;
    }
    downdate(num);
    int mid = (l+r)>>1;
    if(mid < y) change1(mid+1,r,x,y,num<<1|1);
    if(mid >= x) change1(l,mid,x,y,num<<1);
    update(num);
    return;
}

void rev(int l,int r,int x,int y,int num){
    if(l >= x && r <= y){
        swap(t[num].lsum0,t[num].lsum1);
        swap(t[num].rsum0,t[num].rsum1);
        swap(t[num].sum0,t[num].sum1);
        swap(t[num].maxsum0,t[num].maxsum1);
        if(t[num].lazy == true) t[num].lazy = false;
        else t[num].lazy = true;
        return;
    }
    downdate(num);
    int mid = (l+r)>>1;
    if(mid < y) rev(mid+1,r,x,y,num<<1|1);
    if(mid >= x) rev(l,mid,x,y,num<<1);
    update(num);
    return;
}

int query1(int l,int r,int x,int y,int num){
    if(l >= x && r <= y)
        return t[num].sum1;
    downdate(num);
    int mid = (l+r)>>1;
    int ans = 0;
    if(mid < y) ans += query1(mid+1,r,x,y,num<<1|1);
    if(mid >= x) ans += query1(l,mid,x,y,num<<1);
    return ans;
}

point query2(int l,int r,int x,int y,int num){
    if(l >= x && r <= y)
        return t[num];
    downdate(num);
    int mid = (l+r)>>1;
    if(mid < x)
        return query2(mid+1,r,x,y,num<<1|1);
    else if(mid >= y)
        return query2(l,mid,x,y,num<<1);
    else{
        point lans = query2(l,mid,x,y,num<<1);
        point rans = query2(mid+1,r,x,y,num<<1|1);
        point ans;
        ans.l = lans.l;
        ans.r = rans.r;
        if(lans.lsum1 == lans.r-lans.l+1)
            ans.lsum1 = lans.lsum1+rans.lsum1;
        else ans.lsum1 = lans.lsum1;
        if(rans.rsum1 == rans.r-rans.l+1)
            ans.rsum1 = lans.rsum1+rans.rsum1;
        else ans.rsum1 = rans.rsum1;
        ans.maxsum1 = max(lans.maxsum1,rans.maxsum1);
        ans.maxsum1 = max(lans.rsum1+rans.lsum1,ans.maxsum1);
        return ans;
    }
}

int main(){
    n = read(); m = read();
    for(int i = 1;i <= n;i++) x[i] = read();
    build(1,n,1);
    for(int i = 1;i <= m;i++){
        int opt = read(),a = read()+1,b = read()+1;
        if(opt == 0)
            change0(1,n,a,b,1);
        else if(opt == 1)
            change1(1,n,a,b,1);
        else if(opt == 2)
            rev(1,n,a,b,1);
        else if(opt == 3)
            printf("%d\n",query1(1,n,a,b,1));
        else if(opt == 4)
            printf("%d\n",query2(1,n,a,b,1).maxsum1);
    }
    return 0;
}
