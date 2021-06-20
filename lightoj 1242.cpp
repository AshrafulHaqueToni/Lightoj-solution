// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;
 
#define mx 105
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

vector<int>g2[mx],g1[mx];

bool dfs(int a,int p1,int b,int p2)
{
    int jerry_sub=0;
    int tom_sub=0;
    for(int u:g1[a])
    {
        if(p1==u)continue;
        jerry_sub++;
    }
    for(int v:g2[b])
    {
        if(p2==v)continue;
        tom_sub++;
    }
    if(jerry_sub<tom_sub)return false;
    if(tom_sub==0)return true;
    vector<pair<int,int>>tem;
    for(int u:g1[a])
    {
        if(p1==u)continue;
        for(int v:g2[b])
        {
            if(p2==v)continue;
            if(dfs(u,a,v,b))
            {
                tem.push_back({u,v});
            }
        }
    }
    bp.init();
    for(auto it:tem)bp.addEdge(it.first,it.second);
    int val=bp.Max_Matching(n);
    //cout<<val<<endl;
    if(val==tom_sub)return true;
    return false;

}

 
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    scanf("%d",&m);
    for(int i=1;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    if(dfs(1,-1,1,-1))printf("Case %d: Yes\n",++ii);
    else printf("Case %d: No\n",++ii);
    for(int i=0;i<mx;i++)g1[i].clear(),g2[i].clear();
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
