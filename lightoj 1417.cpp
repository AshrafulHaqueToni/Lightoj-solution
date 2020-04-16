#include<bits/stdc++.h>
using namespace std;

#define mx 50005

vector<int>g[mx],g_rev[mx],st(mx),en(mx),component[mx],option,visit;
vector<pair<int,int>>dekhi;
int node,cnt,tem;
int mp[mx];

void dfs_fi(int u)
{
    if(visit[u])return;
    visit[u]=true;
    tem++;
    for(auto it:g[u])
    {
        if(visit[it])continue;
        dfs_fi(it);
    }
}

void dfs1(int u)
{
    visit[u]=true;
    st[u]=++cnt;
    for(auto it:g[u])
    {
        if(visit[it])continue;
        dfs1(it);
    }
    en[u]=++cnt;
}

void dfs2(int u)
{
    visit[u]=true;
    component[cnt].push_back(u);
    for(auto it:g_rev[u])
    {
        if(visit[it])continue;
        dfs2(it);
    }
}
void fast_clear(int u)
{
    if(visit[u]==false)return;
    visit[u]=false;
    for(auto it:g[u])if(visit[it])fast_clear(it);
}
void solve(int ii)
{
    scanf("%d",&node);
    for(int i=1;i<=node;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);///directed graph
        g[u].push_back(v);
        g_rev[v].push_back(u);
        mp[u]++;
        mp[v]++;
    }

    visit.assign(node+2,false);

    for(int i=1;i<=node;i++)
    {
        if(visit[i]==true || mp[i]==0)continue;

        dfs1(i);
    }
    for(int i=1;i<=node;i++)
    {
        if(visit[i]==true && mp[i])dekhi.push_back({en[i],i});
    }

    sort(dekhi.begin(),dekhi.end());
    reverse(dekhi.begin(),dekhi.end());

    visit.assign(node+2,false);
    cnt=1;

    for(int i=0;i<dekhi.size();i++)
    {
        int pos=dekhi[i].second;
        if(visit[pos] || mp[pos]==0)continue;
        dfs2(pos);
        cnt++;
    }

    int re=node,val=0;

    for(int i=1;i<cnt;i++)
    {
        int pos=component[i][0];
        fast_clear(pos);
        tem=0;
        dfs_fi(pos);
        if(tem>val)
        {
            val=tem;
            re=pos;
        }
        else if(tem==val)re=min(re,pos);
    }
    printf("Case %d: %d\n",ii,re);

    for(int i=1;i<=node+2;i++)
    {
        g[i].clear();
        g_rev[i].clear();
        component[i].clear();
    }
    option.clear();
    cnt=0;
    st.clear();
    en.clear();
    dekhi.clear();
    memset(mp,0,sizeof(mp));

    return ;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;
}
