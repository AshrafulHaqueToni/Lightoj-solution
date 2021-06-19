// Created by ash_98
#include<bits/stdc++.h>
using namespace std;
#define mx 1005
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
 
void solve()
{
    int f;
    scanf("%d%d%d",&m,&f,&n);
    bp.init();
    vector<pair<int,int>>male,female;
    for(int i=1;i<=n;i++)
    {
        char c1,c2;
        int u,v;
        scanf(" %c%d %c%d",&c1,&u,&c2,&v);
        if(c1=='M')male.push_back({u,v});
        else female.push_back({u,v});
    }
    int sz=male.size();
    int sz1=female.size();
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz1;j++)
        {
            if(male[i].first==female[j].second or male[i].second==female[j].first)
            {
                bp.g[i+1].push_back(j+1+sz);
            }
        }
    }
    int re=sz+sz1-bp.Max_Matching(sz+sz1);
    printf("Case %d: %d\n",++ii,re );
}
 
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
