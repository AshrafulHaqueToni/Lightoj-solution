// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 15005
#define ll long long
#define mod 100000007

int ar[mx];
char ch[mx];
int dp[3][mx];
int n,m,k,ii;

int add(int a,int b)
{
   a+=b;
   if(a>=mod)a-=mod;
   return a;
}

int sub(int a,int b)
{
    a-=b;
    if(a<0)a+=mod;
    return a;
}

void solve()
{
   scanf("%d%d%d",&n,&m,&k);
   int cur=0;
   memset(dp,0,sizeof(dp));
   dp[0][0]=1;
   for(int i=1;i<=n;i++)
   {
      cur^=1;
      dp[cur][0]=0;
      for(int j=1;j<=k;j++)
      {
        dp[cur][j]=add(dp[cur][j-1],dp[cur^1][j-1]);
        if(j>m)dp[cur][j]=sub(dp[cur][j],dp[cur^1][j-m-1]);
       
      }
   }
   printf("Case %d: %d\n",++ii,dp[cur][k]);
    
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
