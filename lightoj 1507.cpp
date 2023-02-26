// Created by ash_98
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007 //998244353
 

int Trie[mx*61][2];
int n,m,ii,k;
int st;
ll re;

void Insert(ll x){
    int cur=1;
    for(int i=59;i>=0;i--){
        bool pres=((1LL<<i)&x)==(1LL<<i);
        if(Trie[cur][pres]==0)Trie[cur][pres]=++st;
        cur=Trie[cur][pres];
    }
}

void query1(ll x,int bit,ll ans,int cur){
    if(bit==-1){
        re=min(re,ans);
        return;
    }
    bool pres=((1LL<<bit)&x)==(1LL<<bit);
    if(Trie[cur][pres^1])query1(x,bit-1,ans-(1LL<<bit),Trie[cur][pres^1]);
    else{
        query1(x,bit-1,ans,Trie[cur][pres]);
    }

}

void query(ll x,int bit,int cur){
   // cout<<x<<" "<<bit<<" "<<ans<<" "<<cur<<endl;
    if(bit==-1){
        re=0;
        return;
    }
    bool pres=((1LL<<bit)&x)==(1LL<<bit);
    
    if(Trie[cur][pres])query(x,bit-1,Trie[cur][pres]);
    if(Trie[cur][pres^1]){
        ll val=(1LL<<bit);
        query1(x,bit-1,val,Trie[cur][pres^1]);
    }
    
    
}

 
void solve()
{
    scanf("%d",&n);
    re=1e18;
    st=1;
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        query(x,59,1);
        Insert(x);
    }
    printf("Case %d: %lld\n",++ii,re );
    for(int i=1;i<=st;i++)Trie[i][0]=Trie[i][1]=0;
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
