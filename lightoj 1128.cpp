#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define LOG 21

int depth[mx];
int par[mx][LOG];
int val[mx];
int n,q;
vector<int>g[mx];

void dfs(int u,int p,int lvl)
{
    par[u][0]=p;
    depth[u]=lvl;

    for(auto it:g[u])
    {
        if(it==p)continue;
        dfs(it,u,lvl+1);
    }
}

void init(int root)
{
    dfs(root,0,0);

    for(int j=1;j<LOG;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
            }
            else par[i][j]=-1;
        }
    }

}

int func(int u,int v)
{
    int i=log2(depth[u]);

    for(;i>=0;i--)
    {
        if(par[u][i]!=-1 && val[par[u][i]]>=v)u=par[u][i];
    }
    return u;
}

void solve(int ii)
{
    memset(par,0,sizeof par);
    memset(depth,0,sizeof depth);
    val[0]=1;
    for(int i=1;i<=n;i++)g[i].clear();

    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int u;
        scanf("%d%d",&u,&val[i]);
        g[u].push_back(i);
    }
    init(0);
    printf("Case %d:\n",ii);

    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",func(x,y));
    }

}

int main()
{
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
