// Created by ash_98
#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
 
int Trie[mx*60][2];
ll ar[mx];
int n,ii,st;
ll re,x;

void Insert(){
    int cur=1;
    for(int i=59;i>=0;i--){
        bool pres=((1LL<<i)&x);
        if(Trie[cur][pres]==0)Trie[cur][pres]=++st;
        cur=Trie[cur][pres];
    }
}

void query(){

    int cur=1;
    for(int i=59;i>=0;i--){

        int bit=i;
        bool pres=((1LL<<bit)&x);

        if(Trie[cur][pres^1]){
            ll val=(1LL<<bit);
            bit--;
            int ncur=Trie[cur][pres^1];
            while(bit>=0){
                bool npres=(1LL<<bit)&x;
                if(Trie[ncur][npres^1]){
                    val-=(1LL<<bit);
                    ncur=Trie[ncur][npres^1];
                }
                else ncur=Trie[ncur][npres];
                bit--;
            }
            re=min(re,val);
        }

        if(Trie[cur][pres])cur=Trie[cur][pres];
        else return;
    }
}

 
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&ar[i]);
    sort(ar+1,ar+n+1);
    
    for(int i=2;i<=n;i++){
        if(ar[i]==ar[i-1]){
            printf("Case %d: 0\n",++ii );
            return;
        }
    }
    
    re=2e18;
    st=1;

    for(int i=1;i<=n;i++){
        x=ar[i];
        query();
        Insert();
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
