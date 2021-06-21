// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 

#define mx 2005
#define ll long long
int n,m,ii,k;
struct BPM
{
    bool Done[mx];
    vector<int>g[mx];
    int macth[mx];

    void addEdge(int u,int v)
    {
        g[u].push_back(v);
    }

    void init()
    {
        for(int i=0;i<mx;i++)g[i].clear();
    }

    bool Tem_Matching(int u)
    {
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(Done[v]) continue;
            Done[v] = true;
            if(macth[v]==-1 || Tem_Matching(macth[v]))
            {
                macth[v] = u;
                return true;
            }
        }
        return false;
    }
    int Max_Matching(int num)
    {
    // Be Careful with this section. when passin num.
        memset(macth,-1,sizeof(macth));
        int re = 0;
        for(int i=1;i<=num;i++)
        {
            memset(Done,false,sizeof(Done));
            if(Tem_Matching(i)) re++;
            
        }
        return re;
    }
};

BPM bp;

vector<int>g[mx],g_rev[mx],st(mx),en(mx),component[mx],option,Visit,SC[mx];
vector<pair<int,int>>dekhi;
int node,edge,cnt,tem;
int mp[mx],id[mx];
int Tarjen[mx][mx];

void dfs1(int u)
{
    Visit[u]=true;
    st[u]=++cnt;
    for(auto it:g[u])
    {
        if(Visit[it])continue;
        dfs1(it);
    }
    en[u]=++cnt;
}

void dfs2(int u)
{
    Visit[u]=true;
    component[cnt].push_back(u);
    id[u]=cnt;
    for(auto it:g_rev[u])
    {
        if(Visit[it])continue;
        dfs2(it);
    }
}

void dfs3(int u)
{
    Visit[u]=1;
    for(int v:SC[u])
    {
        if(!Visit[v])dfs3(v);
        for(int i=1;i<cnt;i++)
        {
            if(Tarjen[v][i])Tarjen[u][i]=true;
        }
        Tarjen[u][v]=true;
    }
}

void clean()
{
    for(int i=1;i<=node+2;i++)
    {
        g[i].clear();
        g_rev[i].clear();
        component[i].clear();
        SC[i].clear();
    }
    option.clear();
    cnt=0;
    st.clear();
    en.clear();
    dekhi.clear();
    memset(mp,0,sizeof(mp));
    memset(id,0,sizeof(id));
    memset(Tarjen,0,sizeof(Tarjen));
}

 
void solve()
{
    bp.init();
    scanf("%d%d",&node,&edge);
    vector<pair<int,int>>ed;
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);///directed graph
        g[u].push_back(v);
        g_rev[v].push_back(u);
        ed.push_back({u,v});
        mp[u]++;
        mp[v]++;
    }

    Visit.assign(node+2,false);

    for(int i=1;i<=node;i++)
    {
        if(Visit[i]==true || mp[i]==0)continue;

        dfs1(i);
    }
    for(int i=1;i<=node;i++)
    {
        if(Visit[i]==true && mp[i])dekhi.push_back({en[i],i});
    }

    sort(dekhi.begin(),dekhi.end());
    reverse(dekhi.begin(),dekhi.end());

    Visit.assign(node+2,false);
    cnt=1;

    for(int i=0;i<dekhi.size();i++)
    {
        int pos=dekhi[i].second;
        if(Visit[pos] || mp[pos]==0)continue;
        dfs2(pos);
        cnt++;
    }
    Visit.assign(node+2,false);
    
    //  for(int i=1;i<cnt;i++)
    // {
    //     for(auto it:component[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    sort(ed.begin(),ed.end());
    pair<int,int>last={0,0};
    for(auto it:ed)
    {
        if(it==last)continue;
        last=it;
        if(id[it.first]!=id[it.second]) 
        {
            SC[id[it.first]].push_back(id[it.second]);
        }
    }
    for(int i=1;i<cnt;i++)
    {
        if(!Visit[i])dfs3(i);
    }
    for(int i=1;i<cnt;i++)
    {
        for(int j=1;j<cnt;j++)
        {
            if(Tarjen[i][j])bp.addEdge(i,j+cnt-1);
        }
    }
    cnt--;
    int re=0;
    if(cnt)re=cnt-bp.Max_Matching(cnt);
    for(int i=1;i<=node;i++)if(id[i]==0)re++;
    printf("Case %d: %d\n",++ii,re );
    clean();

}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
