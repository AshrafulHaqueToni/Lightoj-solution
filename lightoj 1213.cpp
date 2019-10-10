#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll mod;

ll power(ll a,ll b)
{
    if(b==0)return 1;

    if(b%2==0)
    {
        ll x=power(a,b/2);
        return(x*x)%mod;
    }
    else{
        return (power(a,b-1)*a)%mod;
    }

}

int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        ll n,k,sum=0;

        scanf("%lld %lld %lld",&n,&k,&mod);

        for(int i=0;i<n;i++)
        {
            int val;
            scanf("%d",&val);
            sum+=val;
        }

        ll re=power(n,k-1);

        //cout<<re<<endl;

        re=(re*(sum%mod)*(k%mod))%mod;

        printf("Case %d: %lld\n",ii,re);
    }


    return 0;
}
