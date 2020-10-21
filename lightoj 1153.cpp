// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long
#define mod 1000000007

char ch[mx];
int n,m,k,ii,st,en;
int parent[mx];

int ar[mx][mx];
vector<int>g[mx];

bool dfs(){
  bitset<mx>bt;
  stack<int>s;
  s.push(st);
  bt[st]=1;
  while(!s.empty()){
      int u=s.top();
      s.pop();
      for(int v:g[u]){
        if(!bt[v] && ar[u][v]>0){
          bt[v]=1;
          s.push(v);
          parent[v]=u;
          if(v==en)break;
        }
      }
  }

  return bt[en]==true;

}

void solve()
{
   scanf("%d%d%d%d",&n,&st,&en,&m);
   for(int i=1;i<=m;i++){
       int x,y,w;
       scanf("%d%d%d",&x,&y,&w);
       g[x].push_back(y);
       g[y].push_back(x);
       ar[x][y]+=w;
       ar[y][x]+=w;
   }
   ll re=0;
   while(dfs()){
      int prv=en;
      int val=1e9;
      while(prv!=st){
           val=min(val,ar[parent[prv]][prv]);
           prv=parent[prv];
      }
      prv=en;
      while(prv!=st){
        ar[parent[prv]][prv]-=val;
        ar[prv][parent[prv]]-=val;
        prv=parent[prv];
      }
      re+=val;
   }
   printf("Case %d: %lld\n",++ii,re );
   for(int i=1;i<=n;i++)
    {
      g[i].clear();
      for(int j=1;j<=n;j++)ar[i][j]=0;
    }

    
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
