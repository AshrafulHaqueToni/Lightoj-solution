#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long


int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        ll n,k;
        scanf("%llu%llu",&n,&k);

        ll val=k;
        int re=1;

        while(val%n)
        {
            val=(val*10+k)%n;
            re++;
        }

        printf("Case %d: %d\n",ii,re);
    }



    return 0;
}
