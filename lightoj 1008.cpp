#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        ll n,r,c;

        scanf("%lld",&n);

        ll sq=sqrt(n);

        printf("Case %d: ",ii);

        if(n&1 && sq*sq==n)
        {
            printf("1 %lld\n",sq);
            continue;
        }

        if(n%2==0 && sq*sq==n)
        {
            printf("%lld 1\n",sq);
            continue;
        }

        if(sq%2==0)
        {
            ll val=sq+1;
            ll fi=val*val;

            if(n>=fi-val+1)
            {
                c=fi-n+1;
                r=val;
            }
            else{
               c=val;
               ll minas=fi-val+1-n;
               r=val-minas;
            }

            printf("%lld %lld\n",c,r);
            continue;
        }

        else{
            ll fi=(sq+1)*(sq+1);
            ll val=sq+1;

            if(n>=fi-val+1)
            {
                c=val;
                ll pluss=fi-n+1;
                r=pluss;

            }
            else{
                r=val;
                ll minas=fi-val+1-n;
                c=val-minas;

            }

            printf("%lld %lld\n",c,r);
        }
    }

    return 0;
}
