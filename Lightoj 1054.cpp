#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;

const int mod=1e9+7;
const int N = 1000005;

map<ll,vector<ll> >mm;

vector<ll>prime;

void seive()
{

    bool a[N+3];
    for(ll i=1; i<=N; i++)
        a[i]=true;
    for(ll i=3; i*i<=N; i+=2)
    {
        if(a[i])
        {
            for(ll j=i*i; j<=N; j+=i)
                a[j]=false;
        }
    }
    prime.push_back(2);
    for(ll i=3; i<=N; i+=2)
    {
        if(a[i])
            prime.push_back(i);
    }

}


void primefactorize(ll n)
{
    for(ll i=0; prime[i]*prime[i]<=n&&i<prime.size(); i++)
    {
        if(n%prime[i]==0)
        {
            int k=0;

            while(n%prime[i]==0)
            {
                k++;
                n/=prime[i];
            }
            mm[prime[i]].push_back(k);
        }
    }
    if(n>1)
    {
        mm[n].push_back(1);
    }
}


ll bigmod(ll n,ll p)
{
    if(p==0)return 1;
    if(p==1)return (n+mod)%mod;
    if(p&1){
        ll re=bigmod(n,p-1)%mod;
        return (re*n+mod)%mod;
    }
    else{
        ll re=bigmod(n,p/2)%mod;

        return (re*re+mod)%mod;
    }
}

ll modinverse(ll n)
{
    return bigmod(n,mod-2)%mod;
}




int main()
{
    //freopen("inputt.txt","r",stdin);
    seive();

    int t;
    scanf("%d",&t);
    ll n,m;
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%llu%llu",&n,&m);

        mm.clear();

        primefactorize(n);

        ll re=1;

        if(n!=mod)

        for(auto it: mm)
        {
            ll r=it.first,p=it.second[0];

            ll h=(bigmod(r,p*m+1)-1)%mod;
            ll lo=modinverse(r-1)%mod;

            ll fi;
            fi=(h%mod*lo%mod)%mod;

            re=(re%mod*fi%mod)%mod;
        }


       printf("Case %d: %llu\n",tc,re);

    }

    return 0;
}
