// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long
#define mod 1000000007

int ar[mx],coin[mx];
int dp[100005],need[100005];
char ch[mx];
int n,m,k,ii;

void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)scanf("%d",&ar[i]);
   for(int i=1;i<=n;i++)scanf("%d",&coin[i]);
   for(int i=1;i<=m;i++)dp[i]=0;
    dp[0]=1;
   for(int i=1;i<=n;i++)
   {
       for(int j=0;j<=m;j++)
       {
          if(dp[j])need[j]=0;
          else need[j]=1e9;
       }
       for(int j=0;j+ar[i]<=m;j++)
       {
          int val=j+ar[i];
          if(!dp[val] && dp[j] && need[j]<coin[i])
          {
           // cout<<val<<endl;
            need[val]=need[j]+1;
            dp[val]=1;
          }
       }
   }
   int re=0;
   for(int i=1;i<=m;i++)re+=dp[i];
    printf("Case %d: %d\n",++ii,re );

    
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
