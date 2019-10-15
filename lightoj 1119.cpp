#include<bits/stdc++.h>
using namespace std;

int n,ii;
int w[20][20];
int dp[(1<<15)+2];
int vis[(1<<15)+2];

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}

bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

int func(int mask)
{
    if(mask==(1<<n)-1)
        return 0;

    if(vis[mask]==ii)
        return dp[mask];

    vis[mask]=ii;

    int ans=1<<28;

    for(int i=0; i<n; i++)
    {
        if(chk(mask,i)==0)
        {
            int price=w[i][i];

            for(int j=0; j<n; j++)
            {
                if(i!=j && chk(mask,j)!=0)
                    price+=w[i][j];
            }

            int re=price+func(Set(mask,i));

            ans=min(ans,re);
        }
    }

    return dp[mask]=ans;
}


int main()
{
    int t;
    scanf("%d",&t);

    for(ii=1; ii<=t; ii++)
    {

        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&w[i][j]);
            }
        }

        printf("Case %d: %d\n",ii,func(0));

    }

    return 0;
}
