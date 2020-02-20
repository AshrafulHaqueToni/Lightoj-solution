#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define LOG 21

int par[mx][LOG];
int depth[mx];
int min_ans[mx][LOG];
int max_ans[mx][LOG];
vector<pair<int,int>>g[mx];
int n;

void dfs(int u,int p,int lvl)
{
    par[u][0]=p;
    depth[u]=lvl;

    for(auto it:g[u])
    {
        int v=it.first;
        int w=it.second;

        if(p!=v)
        {
            min_ans[v][0]=w;
            max_ans[v][0]=w;
            dfs(v,u,lvl+1);
        }
    }

}
void init(int root)
{
    dfs(root,-1,1);

    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
                min_ans[i][j]=min(min_ans[i][j-1],min_ans[par[i][j-1]][j-1]);
                max_ans[i][j]=max(max_ans[i][j-1],max_ans[par[i][j-1]][j-1]);
            }
            else par[i][j]=-1;
        }
    }
}
int min_chai(int u,int v)
{
    if(u==v)return 0;
    if(depth[u]<depth[v])swap(u,v);
    int diff=depth[u]-depth[v];
    int re=10000000;

    for(int i=LOG-1;i>=0;i--)
    {
        if(diff>=(1<<i))
        {
            diff-=(1<<i);
            re=min(re,min_ans[u][i]);
            u=par[u][i];
        }
    }
    if(u==v)return re;

    for(int i=LOG-1;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            re=min({re,min_ans[u][i],min_ans[v][i]});
            u=par[u][i];
            v=par[v][i];
        }
    }
    re=min({re,min_ans[u][0],min_ans[v][0]});
    return re;
}

int max_chai(int u,int v)
{
    if(u==v)return 0;
    if(depth[u]<depth[v])swap(u,v);
    int diff=depth[u]-depth[v];
    int re=0;

    for(int i=LOG-1;i>=0;i--)
    {
        if(diff>=(1<<i))
        {
            diff-=(1<<i);
            re=max(re,max_ans[u][i]);
            u=par[u][i];
        }
    }
    if(u==v)return re;

    for(int i=LOG-1;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            re=max({re,max_ans[u][i],max_ans[v][i]});
            u=par[u][i];
            v=par[v][i];
        }
    }
    re=max({re,max_ans[u][0],max_ans[v][0]});
    return re;
}

void solve(int ii)
{
    for(int i=1;i<=mx;i++)
        g[i].clear();

    memset(max_ans,0,sizeof max_ans);
    memset(min_ans,100005,sizeof min_ans);
    memset(par,0,sizeof par);
    memset(depth,0,sizeof depth);

    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int w,v,u;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    init(1);
    int q;
    scanf("%d",&q);
    printf("Case %d:\n",ii);
    while(q--)
    {
       int x,y;
       scanf("%d%d",&x,&y);
       printf("%d %d\n",min_chai(x,y),max_chai(x,y));
    }
}

int main()
{
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
