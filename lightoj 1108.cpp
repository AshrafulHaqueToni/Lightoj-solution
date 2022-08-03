// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 1005
#define ll long long
#define mod 1000000007 //998244353
int n,m,ii,k;
int vis[mx];

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
ll dist[mx];
vector<int>g[mx];

int ncyc[mx];

void candi(int u){
    vis[u]=1;
    ncyc[u]=1;
    for(int v:g[u]){

        if(vis[v])continue;
        candi(v);

    }

}

void bellman_ford(){

    for(int i=1;i<=n;i++)dist[i]=100000000;

    dist[1]=0;

    for(int i=1;i<=n;i++)
        for(Edge it: E)
            if(dist[it.v]>dist[it.u]+it.w)
                dist[it.v]=dist[it.u]+it.w;


    for(Edge it:E)
        if(dist[it.v]>dist[it.u]+it.w){
            dist[it.v]=dist[it.u]+it.w;
            if(!vis[it.v])candi(it.v);
        }
}
 

void solve()
{
    scanf("%d%d",&n,&m);
    E.clear();

    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++;
        y++;
        g[y].push_back(x);
        E.push_back({y,x,z});
    }

    bellman_ford();

    vector<int>res;
    for(int i=1;i<=n;i++)if(ncyc[i])res.push_back(i);

    printf("Case %d:",++ii );
    if(res.empty())printf(" impossible");
    for(int a:res)printf(" %d",a-1);
    printf("\n");

    for(int i=1;i<=n;i++)g[i].clear(),vis[i]=0,ncyc[i]=0;


 
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
