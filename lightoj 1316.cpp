// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 505
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
int dist[mx];
vector<pair<int,int>>g[mx],mask_g[20];
pair<int,int> dp[17][1<<17];
int vis[17][1<<17];


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

pair<int,int>func(int i,int mask)
{
    if(vis[i][mask]==ii)return dp[i][mask];
    vis[i][mask]=ii;
    pair<int,int>re={-mod,0};
    if(mask_g[i].size() && mask_g[i].back().first==k+1)re={0,mask_g[i].back().second};
    for(auto it:mask_g[i])
    {
        if(chk(mask,it.first))continue;
        pair<int,int>re1=func(it.first,Set(mask,it.first));
        re1.first++;
        re1.second+=it.second;
        if(re1.first>re.first)re=re1;
        else if(re1.first==re.first)re.second=min(re1.second,re.second);
    }
    return dp[i][mask]=re;
}

void dijkstra(int u,int id)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=mod;
    }
    dist[u]=0;
    priority_queue<pair<int,int>>pq;

    pq.push({0,u});

    while(!pq.empty())
    {
        int w=-pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(dist[u]<w)continue;

        for(auto it:g[u])
        {
            int v=it.first;
            int cost=it.second;
            
            if(dist[v]>w+cost)
            {
                dist[v]=w+cost;
                pq.push({-dist[v],v});
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(dist[ar[i]]<mod)
        {
            mask_g[id].push_back({i,dist[ar[i]]});
        }
    }
    if(dist[n]<mod)mask_g[id].push_back({k+1,dist[n]});
}
 
void solve()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(ar,-1,sizeof(ar));
    for(int i=1;i<=k;i++)
    {
        int x;
        scanf("%d",&x);
        x++;
        ar[i]=x;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        g[x].push_back({y,z});
    }
    sort(ar+1,ar+k+1);
    dijkstra(1,0);
    for(int i=1;i<=k;i++)dijkstra(ar[i],i);
    ii++;
    int st=0;
    if(k && ar[1]==1)st=1;
    pair<int,int>re=func(st,0);
    if(re.first<0)printf("Case %d: Impossible\n",ii );
    else printf("Case %d: %d %d\n",ii,re.first,re.second);
   
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=0;i<=k;i++)mask_g[i].clear();
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
