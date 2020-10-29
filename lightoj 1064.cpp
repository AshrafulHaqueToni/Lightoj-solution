// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 27
#define ll unsigned long long
#define mod 1000000007

int ar[mx];
char ch[mx];
ll tot[mx];
ll dp[mx][200];
int vis[mx][200];
int n,m,k,ii;

ll func(int i,int sum)
{
   if(i>n)
   {
      return sum>=k;
   }
   if(vis[i][sum]==ii)return dp[i][sum];
   vis[i][sum]=ii;
   ll re=0;
   for(int j=1;j<=6;j++)
   {
      re+=func(i+1,sum+j);
   }
   return dp[i][sum]=re;
}

void pre()
{
  tot[0]=1;
  for(int i=1;i<=25;i++)tot[i]=tot[i-1]*6;
}

void solve()
{
   scanf("%d%d",&n,&k);
   ii++;
   ll op=func(1,0);
   ll ace=tot[n];
   if(op==0)
   {
    printf("Case %d: 0\n",ii );
    return;
   }
   ll gc=__gcd(op,ace);
   if(gc==ace)printf("Case %d: 1\n",ii );
   else printf("Case %d: %llu/%llu\n",ii,op/gc,ace/gc );
    
}

int main()
{
  int t=1;
  pre();
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
