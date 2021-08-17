// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 10005
#define ll long long
#define mod 1000000007
 
int ar[mx];
char ch[mx];
int n,m,ii,k;
vector<int>g[mx];
set<int>ng[mx];
bool odd_length_cycle;
int vis[mx];
int st[mx],low[mx],depth[mx];
int Time=1;
int len;

void dfs(int u,int p)
{
    st[u]=low[u]=Time++;
    int child=0;
    for(auto it:g[u])
    {
        if(it==p)continue;
        if(st[it]==0)
        {
            dfs(it,u);
            if(st[u]<low[it])
            {
                ng[u].erase(ng[u].find(it));
                ng[it].erase(ng[it].find(u));
            }
            low[u]=min(low[u],low[it]);
        }
        else low[u]=min(low[u],st[it]);

    }
}

void dfs_cycle(int u,int l)
{
    vis[u]=1;
    depth[u]=l;
    len++;
    for(int v:ng[u])
    {
        if(vis[v])
        {
            if((depth[u]-depth[v])%2==0)odd_length_cycle=true;
        }
        else
        dfs_cycle(v,l+1);
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    Time=1;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        g[x].push_back(y);
        g[y].push_back(x);
        ng[x].insert(y);
        ng[y].insert(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;
        dfs(i,-1);
    }
    int re=0;

    for(int i=1;i<=n;i++)
    {
       len=0;
       odd_length_cycle=false;
       if(vis[i])continue;
       dfs_cycle(i,0);
       if(odd_length_cycle)re+=len;
    }
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        ng[i].clear();
        vis[i]=0;
        st[i]=0;
        low[i]=0;
    }
    printf("Case %d: %d\n",++ii,re );

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
