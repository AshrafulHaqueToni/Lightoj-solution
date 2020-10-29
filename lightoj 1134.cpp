// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;

void solve()
{
   map<int,int>mp;
   mp[0]++;
   scanf("%d%d",&n,&m);
   ll re=0,sum=0;
   for(int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      sum+=x;
      re+=mp[sum%m];
      mp[sum%m]++;
   }
   printf("Case %d: %lld\n",++ii,re );
    
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
