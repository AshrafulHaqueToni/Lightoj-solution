// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 10005
#define ll long long
#define mod 1000000007

int n,m,ii,k;
vector<pair<int,int>>g[mx],r_g[mx];
ll dist[mx][3];

void dijkstra(int u)
{
    dist[u][0]=0;
    priority_queue<pair<ll,int>>pq;
    pq.push({0,u});
    while(!pq.empty())
    {
        u=pq.top().second;
        ll w=-pq.top().first;
        pq.pop();
        if(w>dist[u][0])continue;
        for(auto it:g[u])
        {
            int v=it.first;
            int cost=it.second;
            if(dist[v][0]<=cost+w)continue;
            dist[v][0]=cost+w;
            pq.push({-dist[v][0],v});
        }
    }
}

void r_dijkstra(int u)
{
    dist[u][1]=0;
    priority_queue<pair<ll,int>>pq;
    pq.push({0,u});
    while(!pq.empty())
    {
        u=pq.top().second;
        ll w=-pq.top().first;
        pq.pop();
        if(w>dist[u][1])continue;
        for(auto it:r_g[u])
        {
            int v=it.first;
            int cost=it.second;
            if(dist[v][1]<=cost+w)continue;
            dist[v][1]=cost+w;
            pq.push({-dist[v][1],v});
        }
    }
}

 
void solve()
{
    int s,t,p;
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
    vector<pair<pair<int,int>,int>>edge;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge.push_back({{x,y},z});
        g[x].push_back({y,z});
        r_g[y].push_back({x,z});
    }
    for(int i=1;i<=n;i++)dist[i][0]=dist[i][1]=1e15;
    dijkstra(s);
    r_dijkstra(t);
    int re=-1;
    for(auto it:edge)
    {
        int u=it.first.first;
        int v=it.first.second;
        int w=it.second;
        if(dist[v][1]+dist[u][0]+w>p)continue;
        re=max(re,w);
    }
    printf("Case %d: %d\n",++ii,re );

    for(int i=1;i<=n;i++)g[i].clear(),r_g[i].clear();

   

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
