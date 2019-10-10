#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[51][51][51];
int vis[51][51][51];

int n,m,k,ii;

ll func(int n,int k,int m)
{
    if(n<=0 || k<=0)
    {
        if (n==0 && k==0)return 1LL;

        return 0LL;
    }

    if(vis[n][k][m])return dp[n][k][m];

    vis[n][k][m]=1;

    ll re=0LL;

    for(int i=1;i<=m;i++)
    {
        re+=func(n-i,k-1,m);
    }

    return dp[n][k][m]=re;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(ii=1; ii<=t; ii++)
    {

        scanf("%d%d%d",&n,&k,&m);

        printf("Case %d: %lld\n",ii,func(n,k,m));
        //printf("%lld\n",func(n,k,m));

    }


    return 0;
}
