// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 15
#define ll long long
#define mod 1000000007 //998244353
 

ll dis[16][16];
int n,m,ii,k;
ll dp[1<<mx];
int vis[1<<mx];
int deg[mx];


ll Set(ll N,int pos)
{
    return N=N|(1LL<<pos);
}

ll Reset(ll N,int pos)
{
    return N=N & ~(1LL<<pos);
}

bool chk(ll N,int pos)
{
    return (bool)(N &(1LL<<pos));
}

ll func(int mask)
{
    if(mask==0)
    {
        return 0;
    }
    if(vis[mask]==ii)return dp[mask];
    vis[mask]=ii;

    ll re=1e18;

    int st_pos=__builtin_ctz(mask);
    //cout<<st_pos<<endl;

    for(int i=st_pos+1;i<n;i++)
    {
        if(!chk(mask,i))continue;
       // cout<<st_pos<<" "<<i<<endl;
        re=min(re,dis[st_pos+1][i+1]+func(Reset(Reset(mask,st_pos),i)));
    }
    return dp[mask]=re;
}
 
void solve()
{
    scanf("%d%d",&n,&m);

    ll re=0;

    for(int i=1;i<=n;i++)
    {
        deg[i]=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j)dis[i][j]=0;
            else dis[i][j]=1e18;
        }
    }

    for(int i=1;i<=m;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        ll val=z;
        dis[x][y]=dis[y][x]=min(dis[x][y],val);
        deg[x]++;
        re+=z;
        deg[y]++;
    }
   
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    int mask=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]&1)mask|=(1<<(i-1));
    }
    ++ii;
    
    printf("Case %d: %lld\n",ii,func(mask)+re);
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
