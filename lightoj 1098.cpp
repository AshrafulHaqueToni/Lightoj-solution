#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>v;



int main()
{
    pre_cal();

    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        ll n;
        scanf("%lld",&n);

        ll re=0;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                re+=i;

                if(n/i!=i)re+=n/i;
            }
        }

        printf("Case %d: %lld\n",ii,re);
    }
}
