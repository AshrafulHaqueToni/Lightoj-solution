// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int ar[mx][2];
int cost[mx][2];
int dp[mx][2];
int vis[mx][2];
char ch[mx];
int n,m,k,ii;

int func(int i,int ti)
{
  if(i==n)return ar[i][ti];
  if(vis[i][ti]==ii)return dp[i][ti];
  vis[i][ti]=ii;
  int re=1e9;
  re=min(re,ar[i][ti]+func(i+1,ti));
  re=min(re,ar[i][ti]+cost[i][ti]+func(i+1,ti^1));
  return dp[i][ti]=re;
}

void solve()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)scanf("%d",&ar[i][0]);
   for(int i=1;i<=n;i++)scanf("%d",&ar[i][1]);
   for(int i=1;i<n;i++)scanf("%d",&cost[i][0]);
   for(int i=1;i<n;i++)scanf("%d",&cost[i][1]);
    ii++;
    int re=func(1,1);
    ii++;
    printf("Case %d: %d\n",++k,min(func(1,0),re));
    
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
