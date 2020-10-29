// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long
#define mod 1000000007

pair<int,pair<int,int>> ar[mx];
char ch[mx];
int dp[mx][mx*mx];
int vis[mx][mx*mx];
int n,m,k,ii;

int func(int i,int baki)
{
   if(i>n)return 0;
   if(vis[i][baki]==ii)return dp[i][baki];
   vis[i][baki]=ii;
   int re=func(i+1,baki);
   if(baki>=ar[i].second.second)re=max(re,ar[i].first+func(i,baki-ar[i].second.second));
   return dp[i][baki]=re;
}

void solve()
{
   scanf("%d%d",&n,&m);
   int tot=0;
   for(int i=1;i<=n;i++)
   {
      scanf("%d%d%d",&ar[i].first,&ar[i].second.first,&ar[i].second.second);
      tot+=ar[i].second.first*ar[i].second.second;
   }
   if(tot>m)
   {
     printf("Case %d: Impossible\n",++ii );
     return;
   }
   ii++;
   printf("Case %d: %d\n",ii,func(1,m-tot));
    
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
