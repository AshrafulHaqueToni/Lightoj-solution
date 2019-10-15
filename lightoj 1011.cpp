#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool chk(int pos,int val)
{
    return (bool) (val & (1<<pos));
}

int Set(int pos,int val)
{
    return val=(val | (1<<pos));
}

int dp[1<<17][17];
int vis[1<<17][17];
int a[17][17];
int ii,n;

int func(int mask,int pos)
{
    if(pos==n)
        return 0;

    //cout<<mask<<endl;

    if(vis[mask][pos]==ii)
        return dp[mask][pos];

    vis[mask][pos]=ii;

    int re=0;


    for(int j=0; j<n; j++)
    {
        if(!chk(j,mask))
        {

            re=max(re,(a[pos][j]+func(Set(j,mask),pos+1)));

        }

    }

    return dp[mask][pos]=re;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(ii=1; ii<=t; ii++)
    {
        scanf("%d",&n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);

        printf("Case %d: %d\n",ii,func(0,0));
    }

    return 0;
}
