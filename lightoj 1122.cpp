// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 15
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
ll dp[mx][mx];
int vis[mx][mx];
int n,m,k,ii;

ll func(int idx,int last)
{
  if(idx>n)return 1;
  if(vis[idx][last]==ii)return dp[idx][last];
  vis[idx][last]=ii;
  ll re=0;
  for(int j=1;j<=m;j++)
  {
    if(last==0)
    {
      re+=func(idx+1,ar[j]);
    }
    else
    {
      if(abs(ar[j]-last)<=2)re+=func(idx+1,ar[j]);
    }
  }
  return dp[idx][last]=re;
}
void solve()
{
   scanf("%d%d",&m,&n);
   for(int i=1;i<=m;i++)scanf("%d",&ar[i]);
   ii++;
   printf("Case %d: %lld\n",ii,func(1,0));
    
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
