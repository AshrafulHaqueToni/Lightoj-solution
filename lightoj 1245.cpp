#include<bits/stdc++.h>
using namespace std;

#define  ll long long

void solve(int ii)
{
    ll n;

    scanf("%lld",&n);

    ll i=1,cnt=0,re=0;

    for(;i*i<=n;i++)
    {
        re+=n/i;

        if(cnt+i<n)
        {
            ll val=(n-cnt-(n/(i+1)));
            cnt+=val;
            re+=val*i;
        }

        //cout<<i<<" "<<re<<" "<<cnt<<endl;
    }

    printf("Case %d: %lld\n",ii,re);
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);

    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
