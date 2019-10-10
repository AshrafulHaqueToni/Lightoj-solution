#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000003


ll bigmod(ll n,ll p)
{
    if(p==0)
        return 1;
    if(p==1)
        return (n+mod)%mod;
    if(p%2)
        return (bigmod(n,p-1)*n+mod)%mod;
    else
    {
        ll x=bigmod(n,p/2);
        return (x*x+mod)%mod;
    }
}


ll inverse_mod(ll n)
{
    return bigmod(n,mod-2)%mod;
}


ll v[1000005];

void fac()
{
    v[0]=1;

    for(int i=1;i<=1000005;i++)
    {
        v[i]=((v[i-1]%mod)*i)%mod;
    }
}

int main()
{
    fac();

    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
         ll re= ((v[n]%mod)*((inverse_mod(v[k])*inverse_mod(v[n-k]))%mod))%mod;

         printf("Case %d: %lld\n",ii,re);
    }
    return 0;
}
