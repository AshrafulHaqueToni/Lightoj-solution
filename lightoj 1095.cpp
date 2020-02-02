#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define mx 1005

ll fact[mx];

void factorial()
{
    fact[0]=1;
    for(int i=1;i<=mx;i++)fact[i]=(fact[i-1]*i)%mod;
}

ll bigmod(ll val,ll pow)
{
    if(pow==0)return 1LL;
    if(pow==1)return val;
    if(pow%2==1)
    {
        return (val*bigmod(val,pow-1))%mod;
    }
    else
    {
        ll x=bigmod(val,pow/2)%mod;
        return (x*x)%mod;
    }
}

ll mod_inverse(ll val)
{
    return bigmod(val,mod-2);
}

ll nCr(ll n,ll r)
{
    return (((fact[n]*mod_inverse(fact[r]))%mod)*mod_inverse(fact[n-r]))%mod;
}

void solve(int ii)
{
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);

    ll tot_option=nCr(m,k);

    ll per_cnt=fact[n-k];

    /// finds how many permutations of a size-n set does not have any of the firts k elements
    /// in their correspondient position (kth position).

    for(int i=1;i<=(m-k);i++)
    {
        if(i%2==1)per_cnt-=(nCr(m-k,i)*fact[n-k-i])%mod;
        else per_cnt+=(nCr(m-k,i)*fact[n-k-i])%mod;
        per_cnt=(per_cnt+mod)%mod;
    }

    printf("Case %d: %lld\n",ii,(tot_option*per_cnt)%mod);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    factorial();
    int t=1;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
