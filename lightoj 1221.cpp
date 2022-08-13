// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct Edge
{
    int u,v,w;
    Edge(){};
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

vector<Edge>E;
ll dist[105];
int n,tc;

bool bellman_ford()
{
    /// here i can start from 1 .if given that stating node i can set dist[src]=0

    for(int i=1;i<=n;i++)dist[i]=10000000;

    dist[1]=0;

    for(int i=1;i<n;i++)
        for(Edge it: E)
            if(dist[it.v]>dist[it.u]+it.w)
                dist[it.v]=dist[it.u]+it.w;


    for(Edge it:E)
        if(dist[it.v]>dist[it.u]+it.w)return true;
    return false;
}
 
void solve()
{
    int r,p;
    E.clear();
    scanf("%d%d%d",&n,&r,&p);
    for(int i=1;i<=r;i++){
        int x,y,income,expenses;
        scanf("%d%d%d%d",&x,&y,&income,&expenses);
        E.push_back({x+1,y+1,expenses*p-income});  /// income/expenses > p; income > p*expenses ; if in cycle sum of all p*expense-income are negative, it's satify the condition
    }
    if(bellman_ford())printf("Case %d: YES\n",++tc );
    else printf("Case %d: NO\n",++tc);
 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
