// Add some code// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
int n,m,ii,k;

int f_cnt[mx];

int lp[mx];
vector<int>prime;

void sieve()
{
    for(int i=2;i<mx-3;i++)
    {
        if(lp[i]==0)
        {
            prime.push_back(i);
            lp[i]=i;
        }
        for(int j=0;j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<mx-3;j++)
            lp[i*prime[j]]=prime[j];
    }
}


void solve()
{
    scanf("%d",&n);
    int boro=0;
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]),boro=max(boro,ar[i]);
    sort(ar+1,ar+n+1);
    ll sum=0;


    for(int i=1;i<=n;i++){

        sum+=(ll)ar[i]*ar[i]; 

        int val=ar[i];

        while(val>1){
            int sp=lp[val];
            f_cnt[sp]++;
            while(val%sp==0)val/=sp;
        }

    }

    vector<pair<int,int>>get_extra;

    for(int p:prime){
        if(p>boro)break;
        if(p>10 and f_cnt[p])
            get_extra.push_back({-f_cnt[p],p});
        f_cnt[p]=0;
    }

    sort(get_extra.begin(),get_extra.end());


    ll cost=1e18;
    int gc=1;
    
    for(int p:prime){
        if(p>boro*2 or p>10)break;

        ll val=0;
        int gcd=0;
        for(int i=1;i<=n;i++){
            int j=ar[i];
            int ex=ar[i]%p;
            if(ex)j+=p-ex;
            val+=(ll)j*j;
            gcd=__gcd(gcd,j);

        }
        if(cost>val){
            cost=val;
            gc=gcd;
        }
        else if(cost==val){
            gc=max(gc,gcd);
        }
    }

    int sz=get_extra.size();

    sz=min(sz,50);

    for(int i=0;i<sz;i++){
        int p=get_extra[i].second;

        ll val=0;
        int gcd=0;
        for(int i=1;i<=n;i++){
            int j=ar[i];
            int ex=ar[i]%p;
            if(ex)j+=p-ex;
            val+=(ll)j*j;
            gcd=__gcd(gcd,j);

        }
        if(cost>val){
            cost=val;
            gc=gcd;
        }
        else if(cost==val){
            gc=max(gc,gcd);
        }

    }
  

    printf("Case %d: %lld %d\n",++ii,cost-sum,gc );
    
    
}
 
int main()
{
    int t=1;
    sieve();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
