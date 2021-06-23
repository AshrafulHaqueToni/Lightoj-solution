// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
int dist[mx][mx];
vector<pair<int,int>>g[mx];
bool chk[mx][mx];

int dijkstra(int u,int t,int li)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=li;j++)dist[i][j]=mod;
    }
    dist[u][0]=0;
    priority_queue<pair<pair<int,int>,int>>pq;
    pq.push({{0,0},u});

    while(!pq.empty())
    {
        int w=-pq.top().first.first;
        u=pq.top().second;
        int have=pq.top().first.second;
        pq.pop();
        if(dist[u][have]<w)continue;
        if(u==t)return w;

        for(auto it:g[u])
        {
            int v=it.first;
            int cost=it.second;

            for(int i=max(have,cost);i<=li;i++)
            {
                int tot=w+(i-have)*ar[u];
                if(tot>=dist[v][i-cost])continue;
                dist[v][i-cost]=tot;
                pq.push({{-tot,i-cost},v});
            }
        }
    }
    return mod;
}
 
void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    int q;
    scanf("%d",&q);
    printf("Case %d:\n",++ii );
    for(int i=1;i<=q;i++)
    {
        int c,x,y;
        scanf("%d%d%d",&c,&x,&y);
        x++,y++;
        int re=dijkstra(x,y,c);
        if(re==mod)printf("impossible\n");
        else printf("%d\n",re);
    }
    for(int i=1;i<=n;i++)g[i].clear();
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
