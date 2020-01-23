#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int ii)
{
    ll x;
    scanf("%lld",&x);

    bool neg=false;

    if(x<0)
        neg=true,x=abs(x);


    for(ll i=2; i*i<=x; i++)
    {
        if(x%i==0)
        {
            ll tem=x;
            int cnt=0;

            while(tem%i==0)
            {
                tem/=i;
                cnt++;
            }
            if(tem==1)
            {


                if(cnt%2==1 || neg==false)
                {
                    printf("Case %d: %d\n",ii,cnt);
                    return;
                }
            }
        }
    }

    printf("Case %d: 1\n",ii);
}

int main()
{
    int t=1;
    scanf("%d",&t);

    for(int ii=1; ii<=t; ii++)
        solve(ii);

    return 0;
}
