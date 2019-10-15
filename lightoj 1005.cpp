#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[31][31];
int vis[31][31],ii;

ll func(int n,int r)
{
    if(r==1)return (ll)n;

    if(n==r)return 1LL;

    if(vis[n][r]==ii)return dp[n][r];

    vis[n][r]=ii;

    return dp[n][r]=func(n-1,r-1)+func(n-1,r);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(ii=1;ii<=t;ii++)
    {
        int n,k;
        scanf("%d%d",&n,&k);

        printf("Case %d: ",ii);

        if(n<k)
        {
            printf("0\n");
            continue;
        }
        if(k==0)
        {
            printf("1\n");
            continue;
        }

        ll re=1;

        for(ll i=n-k+1;i<=n;i++)re*=i;
        //cout<<re<<endl;

        printf("%lld\n",func(n,k)*re);
    }

    return 0;
}
