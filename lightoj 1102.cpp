#include<bits/stdc++.h>
using namespace std;

#define mx 2000005
#define ll long long
#define mod 1000000007
ll fact[mx];
int ii;

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

void fact_cal()
{
    fact[0]=1;
    for(int i=1;i<=mx-5;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int re=(fact[n+k-1]*bigmod((fact[n]*fact[k-1])%mod,mod-2))%mod;  /// using star and bar formula...
    /// https://cp-algorithms.com/combinatorics/stars_and_bars.html
    printf("Case %d: %d\n",++ii,re);
}

int main()
{
    int t=1;
    fact_cal();
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
