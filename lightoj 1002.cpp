#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 
#define inf 1e18

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}



vector<pair<int,int>>g[mx];
ll dis[mx];
int m,n,k,ii;


void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++)
   {
      int x,y,w;
      
      scanf("%d%d%d",&x,&y,&w);
      x++,y++;
      g[x].push_back({y,w});
      g[y].push_back({x,w});
   }
   scanf("%d",&k);
   k++;
   for(int i=1;i<=n;i++)dis[i]=inf;
   priority_queue<pair<ll,int>>q;
   dis[k]=0;
   q.push({0,k});
   while(!q.empty())
   {
       int u=q.top().second;
       ll val=q.top().first;
       val*=-1;
       q.pop();
       if(dis[u]<val)continue;
       for(auto it:g[u])
       {
          ll val1=max(val,(ll)it.second);
          int v=it.first;
          if(val1<dis[v])
          {
            dis[v]=val1;
            q.push({-val1,v});
          }
       }
   }
   printf("Case %d:\n",++ii );
   for(int i=1;i<=n;i++)
   {
      if(dis[i]==inf)printf("Impossible\n");
      else printf("%lld\n",dis[i] );
   }
   for(int i=1;i<=n;i++)g[i].clear();

}

int main()
{
  IO();
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }
  return 0;
}
