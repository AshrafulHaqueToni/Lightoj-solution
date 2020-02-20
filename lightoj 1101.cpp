#include<bits/stdc++.h>
using namespace std;

#define mx 50005
#define LOG 20

int par[mx][LOG];
int ans[mx][LOG];
int depth[mx];
vector<pair<int,int>>g[mx];
pair<int,pair<int,int>>tem[100005];
int n,m;
int parent[mx];

int find_par(int u)
{
    return parent[u]=((parent[u]==u)?u:find_par(parent[u]));
}

void kruskal()
{
    for(int i=1;i<=n;i++)parent[i]=i;
    sort(tem+1,tem+m+1);
    int cnt=0;

    for(int i=1;i<=m;i++)
    {
        int u=tem[i].second.first;
        int v=tem[i].second.second;
        int w=tem[i].first;
        if(find_par(u)!=find_par(v))
        {
            parent[find_par(u)]=find_par(v);
            cnt++;
            //cout<<u<<" "<<v<<" "<<w<<endl;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            if(cnt==n-1)break;
        }
    }
}

void dfs(int u,int p,int lvl)
{
    //cout<<u<<" "<<p<<endl;
    par[u][0]=p;
    depth[u]=lvl;
    for(auto it:g[u])
    {
        int v=it.first;
        int w=it.second;
        if(v==p)continue;
        ans[v][0]=w;
        dfs(v,u,lvl+1);
    }
    //cout<<"me";
}

void init(int root)
{
    //cout<<"hi";
    dfs(root,-1,1);
   // cout<<"ami";
    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(par[i][j-1]!=-1)
            {
                par[i][j]=par[par[i][j-1]][j-1];
                ans[i][j]=max(ans[i][j-1],ans[par[i][j-1]][j-1]);
            }
            else par[i][j]=-1;

        }
    }
}

int query(int u,int v)
{
    if(u==v)return 0;
    if(depth[u]<depth[v])swap(u,v);
    int diff=depth[u]-depth[v];
    int re=0;
    //cout<<diff<<endl;

    for(int i=LOG-1;i>=0;i--)
    {
        if(diff>=(1<<i))
        {
            diff-=(1<<i);
            //u=par[u][i];
            re=max(re,ans[u][i]);
            u=par[u][i];
            //cout<<par[u][i]<<endl;
        }
        //cout<<ans[u][i]<<" ";
    }
    if(u==v)return re;

    for(int i=LOG-1;i>=0;i--)
    {
        if( par[u][i]!=par[v][i])
        {
            re=max({re,ans[u][i],ans[v][i]});
            u=par[u][i];
            v=par[v][i];
        }
        //if (u==-1)return u;
    }
    re=max({re,ans[u][0],ans[v][0]});
    return re;
}

void solve(int ii)
{
    memset(par,0,sizeof par);
    memset(ans,0,sizeof ans);
    for(int i=1;i<=n;i++)g[i].clear();

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        tem[i]={w,{x,y}};
    }

    kruskal();
    //for(int i=1;i<=n;i++)
    //for(auto it:g[i])cout<<i<<" "<<it.first<<" "<<it.second<<endl;

    init(1);
    int q;
    scanf("%d",&q);

    printf("Case %d:\n",ii);

    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
    }
}

int main()
{
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);

    return 0;
}
