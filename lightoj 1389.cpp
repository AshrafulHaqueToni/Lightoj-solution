// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int dp[mx];
int vis[mx];
int n,m,k,ii;

int func(int idx)
{
  if(idx>=n)return 0;
  if(vis[idx]==ii)return dp[idx];
  vis[idx]=ii;
  int re=0;
  if(ch[idx]=='#')re=func(idx+1);
  else
  {
    re=1+func(idx+3);
  }
  return dp[idx]=re;
}

void solve()
{
   scanf("%d%s",&n,ch);
   ii++;
   printf("Case %d: %d\n",ii,func(0));
    
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
