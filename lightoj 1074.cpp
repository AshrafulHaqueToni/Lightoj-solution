// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 205
#define ll long long
#define mod 10000000 //998244353
 
int ar[mx];
bool vis[mx];
ll cost[mx];
int n,m,ii,k;
vector<pair<int,ll>>g[mx];

/*struct Edge
{
    int u,v;
    ll w;
    Edge(){};
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

vector<Edge>E,edge;
ll dist[mx];

bool bellman_ford()
{
    /// here i can start from 1 .if given that stating node i can set dist[src]=0

    for(int i=1;i<=n;i++)dist[i]=mod;

    dist[1]=0;

    for(int i=1;i<n;i++)
        for(Edge it: E)
            if(dist[it.v]>dist[it.u]+it.w)
                dist[it.v]=dist[it.u]+it.w;


    for(Edge it:E)
        if(dist[it.v]>dist[it.u]+it.w)return true;
    return false;
}

void dfs(int u){
    vis[u]=1;
    for(auto[v,w]:g[u]){
        if(vis[v])continue;
        dfs(v);
    }
}*/
 
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]),cost[i]=mod,vis[i]=0,g[i].clear();
    scanf("%d",&m);
   /* edge.clear();
    E.clear();*/
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        ll dif=ar[y]-ar[x];
        dif*=dif*dif;
        g[x].push_back({y,dif});
       // edge.push_back(Edge(x,y,dif));
    }
   /* dfs(1);
    for(auto it:edge){
        if(vis[it.u])E.push_back(it);
    }*/
    printf("Case %d:\n",++ii);
    /*if(bellman_ford()){
        int q;
        scanf("%d",&q);
        while(q--){
            int x;
            scanf("%d",&x);
            printf("?\n");
        }
        return;

    }*/
    priority_queue<pair<ll,int>>pq;
    pq.emplace(0,1);
    while(!pq.empty()){
        auto[w,u]=pq.top();
        pq.pop();
        w*=-1;
        if(w<=-8000)continue;
        if(cost[u]<w)continue;
        for(auto[v,c]:g[u]){
            if(cost[v]>c+w){
                cost[v]=c+w;
                pq.push({-cost[v],v});
            }
        }
    }
   // cout<<"reach";
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(cost[x]>=mod or cost[x]<3)
         printf("?\n");
        else printf("%lld\n",cost[x]);
    }

 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
