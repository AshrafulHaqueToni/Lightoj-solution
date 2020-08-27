#include<bits/stdc++.h>
using namespace std;


#define mx 5005
#define ll long long 
#define inf 1e9

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}



vector<pair<int,int>>g[mx];
int dis[mx][2],vis[mx];
int m,n,k,ii,re;


void bfs(int u)
{
   priority_queue<pair<int,int>>q;
   dis[u][k]=0;
   q.push({0,u});
   while(!q.empty())
   {
        u=q.top().second;
       int val=q.top().first;
       val*=-1;
       q.pop();
       if(dis[u][k]<val)continue;
       for(auto it:g[u])
       {
          int val1=val+it.second;
          int v=it.first;
          if(val1<dis[v][k])
          {
            dis[v][k]=val1;
            q.push({-val1,v});
          }
       }
   }
}

void dfs(int u)
{
    vis[u]=1;
     for(auto it:g[u])
     {
         int v=it.first;

         //cout<<u<<" "<<v<<endl;
        
         if(dis[u][0]+dis[v][1]+it.second!=dis[n][0])
         {
            re=min(re,dis[u][0]+dis[v][1]+it.second);
         }
         else
         re=min(re,dis[u][0]+dis[v][1]+it.second*3);
         if(dis[u][1]+dis[v][0]+it.second!=dis[n][0])
         {
            re=min(re,dis[u][1]+dis[v][0]+it.second);
         }
         else
         re=min(re,dis[u][1]+dis[v][0]+it.second*3);
         if(u!=n && u!=1)
         re=min(re,dis[n][0]+dis[u][0]*2);//,cout<<u<<" "<<dis[u][0]<<endl;
         if(v!=n && v!=1)
         re=min(re,dis[n][0]+dis[v][0]*2);//,cout<<v<<" "<<dis[v][0]<<endl;
          if(vis[v]==1)continue;
         dfs(v);

     }
}

void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++)
   {
      int x,y,w;
      
      scanf("%d%d%d",&x,&y,&w);
     
      g[x].push_back({y,w});
      g[y].push_back({x,w});
   }
   for(int i=1;i<=n;i++)dis[i][0]=dis[i][1]=inf,vis[i]=0;
   k=0;
   bfs(1);
   k=1;
   bfs(n);
   re=inf;
   dfs(1);

  // for(int i=1;i<=n;i++)printf("%d %d\n",dis[i][0],dis[i][1] );
   
   printf("Case %d: %d\n",++ii,re);
 
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
