// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 10005
#define ll long long
#define mod 1000000007

int ar[mx];
int root[mx],mafia[mx];
char ch[mx];
int n,m,k,ii;
vector<int>g[mx];

int dfs(int u,int p)
{
    int re=0;
    for(int v:g[u])
    {
      re+=dfs(v,u);
    }
    re+=abs(mafia[u]-1);
    mafia[p]+=mafia[u]-1;
    return re;
}

void solve()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      g[i].clear();
      root[i]=1;
   }
   for(int i=1;i<=n;i++)
   {
      int u,num,v;
      scanf("%d%d%d",&u,&num,&v);
      mafia[u]=num;
      for(int j=1;j<=v;j++)
      {
        int x;
        scanf("%d",&x);
        root[x]=0;
        g[u].push_back(x);
      }
   }

   int st;
   for(int i=1;i<=n;i++)
   {
     if(root[i])st=i;
   }

   printf("Case %d: %d\n",++ii,dfs(st,0));
    
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
