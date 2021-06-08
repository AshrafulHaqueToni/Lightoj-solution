// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005
#define ll long long
#define mod 1000000007
 

int n,m,ii,k;


int lp[mx];
vector<int>prime;

void sieve()
{
    for(int i=2;i<mx-4;i++)
    {
        if(lp[i]==0)
        {
            prime.push_back(i);
            lp[i]=i;
        }
        for(int j=0;j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<mx-4;j++)
            lp[i*prime[j]]=prime[j];
    }

}

int func(ll val)
{
    ll re=1;
    int sz=prime.size();
    for(int i=0;i<sz&& (ll)prime[i]*prime[i]<=val;i++)
    {
        if(val%prime[i]!=0)continue;
        int cnt=0;
        while(val%prime[i]==0)
        {
            val/=prime[i];
            cnt++;
        }
        re*=(cnt+1);

    }
    if(val>1)re*=2;
   // cout<<re<<endl;
    return (re)/2;

}


 
void solve()
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    int re=0;
    ll jabe=sqrt(a);
    if(jabe<b)
    {
        printf("Case %d: 0\n",++ii );
        return;
    }
    re=func(a);
    for(int i=1;i<b;i++)
    {
        if(a%i==0)re--;
    }
    printf("Case %d: %d\n",++ii,re );
}
 
int main()
{
    int t=1;
    sieve();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
