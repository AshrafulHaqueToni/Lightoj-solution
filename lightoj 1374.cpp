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
   scanf("%d",&n);
   bool f=true;
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&ar[i]);
       if(ar[i]>=n)f=false;
       mp[ar[i]]++;
   }
   for(int i=0;i<=n-1;i++)
   {
      int another=n-i-1;
      if(i==another)
      {
         if(mp[i]>1)f=false;
      }
      else if(mp[another]+mp[i]>2)f=false;
   }

   if(f)printf("Case %d: yes\n",++ii );
   else printf("Case %d: no\n",++ii );
    
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
