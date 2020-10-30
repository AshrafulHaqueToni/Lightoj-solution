// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int dp[mx][mx];
int vis[mx][mx];

int n,m,k,ii;

int func(int be,int en)
{
    if(be>en)return 0;
    if(vis[be][en]==ii)return dp[be][en];
    vis[be][en]=ii;
    int re=1+func(be+1,en);
    for(int i=be+1;i<=en;i++)
    {
      if(ar[i]==ar[be]){
        re=min(re,func(be+1,i)+func(i+1,en));
      }
    }
    return dp[be][en]=re;
}

void solve()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
    ii++;
    printf("Case %d: %d\n",ii,func(1,n));
    
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
