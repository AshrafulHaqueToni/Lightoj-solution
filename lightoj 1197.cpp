#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100005

ll n,l,r;
bool is_composite[mx];
vector<ll>prime;



void sieve(int n)
{

    for(int i=2; i*i<=n; i++)
    {
        if(!is_composite[i])
        {
            for(int j=i*i; j<=n; j+=i)
            {
                is_composite[j]=true;
            }
        }
    }
    prime.push_back(2);


    for(int i=3;i<=n;i+=2)if(!is_composite[i])prime.push_back(i);
}

void solve(int ii)
{
    scanf("%lld%lld",&l,&r);

    bool is_prime[r-l+1];

    for(int i=0;i<r-l+1;i++)is_prime[i]=true;

    for(int i=0; prime[i]*prime[i]<=r; i++)
    {
        ll base=(l/prime[i])*prime[i];

        if(base<l)
            base+=prime[i];

        for(ll j=base; j<=r; j+=prime[i])
        {
            is_prime[j-l]=false;
        }

        if(base==prime[i])
            is_prime[base-l]=true;
    }

    int ans=0;

    if(l==1)
        ans--;

    for(int i=0; i<r-l+1; i++)
        if(is_prime[i]==true)
            ans++;

    printf("Case %d: %d\n",ii,ans);


    return;
}


int main()
{
    int t=1;
    sieve(100000);
    scanf("%d",&t);

    for(int i=1; i<=t; i++)
        solve(i);

    return 0;
}

