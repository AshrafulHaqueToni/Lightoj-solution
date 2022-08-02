// Created by ash_98
 
#include<bits/stdc++.h>
using namespace std;

#define mx 10005
#define ll long long


vector<int>g[mx];
int articular_point[mx];
int n,m,k,ii;
int st[mx],low[mx];
int Time=1;

int dfs(int u,int p)
{
    st[u]=low[u]=Time++;
    int child=0;
    for(auto it:g[u])
    {
        if(it==p)continue;
        if(st[it]==0)
        {
            child++;
            dfs(it,u);
            if(st[u]<=low[it])articular_point[u]=1;
            low[u]=min(low[u],low[it]);
        }
        else low[u]=min(low[u],st[it]);

    }
    return child;
}

void solve()
{
   scanf("%d%d",&n,&m);
   Time=1;
   for(int i=1;i<=m;i++)
   {
       int x,y;
       scanf("%d%d",&x,&y);
       g[x].push_back(y);
       g[y].push_back(x);
   }
   for(int i=1;i<=n;i++)
   {
       if(st[i])continue;
       articular_point[i]=(dfs(i,-1)>1);
   }
   int re=0;
   for(int i=1;i<=n;i++)
   {
      if(articular_point[i] and g[i].size()>1)re++;
      st[i]=low[i]=0;
      articular_point[i]=0;
      g[i].clear();
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
