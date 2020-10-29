// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int ar[mx];
bool done[mx];
int dp[mx][3];
int vis[mx][3];
char ch[mx];
int n,m,k,ii;

vector<int>g[mx];

int func(int u,int ti,int p)
{
   done[u]=true;
   if(vis[u][ti]==ii)return dp[u][ti];
   vis[u][ti]=ii;
   int re=0;
   for(int v:g[u])
   {
       if(v!=p)
       {
          if(!ti)
          {
            re+=func(v,ti^1,u);
          }
          else
          {
            re+=max(1+func(v,ti^1,u),func(v,ti,u));
          }
       }
   }
   return dp[u][ti]=re;

}

void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
   }
   int re=0;
   for(int i=1;i<=n;i++)
   {
      if(!done[i])
      {
         ii++;
         int tem=1+func(i,0,-1);
         ii++;
         tem=max(tem,func(i,1,-1));
         re+=tem;
      }
   }
   printf("Case %d: %d\n",++k,re);

   for(int i=1;i<=n;i++)g[i].clear(),done[i]=false;

    
}

int main()
{
  int t=1;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
