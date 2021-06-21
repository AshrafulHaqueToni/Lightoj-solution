// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 10005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k,d;

struct node
{
    int v,w,ti;
};
int dist[mx][15];
vector<node>g[mx];

void dijsktra(int u)
{
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{u,0}});
    while(!pq.empty())
    {
        u=pq.top().second.first;
        int kth=pq.top().second.second;
        int w=-pq.top().first;
        pq.pop();
        //cout<<u<<" "<<w<<" "<<kth<<endl;
        if(dist[u][kth]<w)continue;
        for(node it:g[u])
        {
            int v=it.v;
            int w1=it.w;
            int tot=kth+it.ti;
            if(tot>d)continue;
            if(dist[v][tot]<=w+w1)continue;
            dist[v][tot]=w+w1;
            pq.push({-dist[v][tot],{v,tot}});
        }
    }
}
 
void solve()
{
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++;
        y++;
        g[x].push_back({y,w,0});
    }
    for(int i=1;i<=k;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++;
        y++;
        g[x].push_back({y,w,1});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=d;j++)dist[i][j]=mod;
    }
    dist[1][0]=0;
    dijsktra(1);
    int re=mod;
    for(int i=0;i<=d;i++)re=min(re,dist[n][i]);
    if(re==mod)printf("Case %d: Impossible\n",++ii );
    else printf("Case %d: %d\n",++ii,re );
    for(int i=1;i<=n;i++)g[i].clear();
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
