// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000000007 //998244353
 
int ar[mx];
vector<int>g[17];
int Small[17][17];
ll dp[1<<17];
int vis[1<<17];
int n,m,ii,k;

ll func(int mask)
{
    if(mask==(1<<m)-1)return 0;
    if(vis[mask]==ii)return dp[mask];
    vis[mask]=ii;
    ll re=1e12;
   
    for(int i=0;i<m;i++)
    {
        if((mask&(1<<i))==0)
        {
            ll cost=0;
            for(int j=0;j<m;j++)
            {
                if(i!=j and (mask&(1<<j))==0){
                    cost+=Small[i+1][j+1];
                }
            }

            
            
            re=min(re,cost+func(mask|(1<<i)));

        }
    }
    return dp[mask]=re;
}
 
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
        g[ar[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        vector<int>pre(n+1,0);
        for(int p:g[i])pre[p]++;
        for(int j=1;j<=n;j++)pre[j]+=pre[j-1];
        Small[i][i]=0;
        for(int j=1;j<=m;j++)
        {
            if(i==j)continue;
            int cost=0;
            for(int p:g[j])cost+=pre[p];
            Small[j][i]=cost;
        }

    }
    ii++;
    printf("Case %d: %lld\n",ii,func(0));

    for(int i=1;i<=m;i++)g[i].clear();
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
