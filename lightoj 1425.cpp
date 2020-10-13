// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;
vector<int>v;

bool func(int tar)
{
   for(int i=0;i<n;i++)
   {
      if(v[i]>tar)return false;
      if(v[i]==tar)tar--;
   }
   return true;
}

void solve()
{
   scanf("%d",&n);
   int last=0;
   v.clear();
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&ar[i]);
      v.push_back(ar[i]-last);
      last=ar[i];
   }
   int be=1,en=1e9+5;
   int re=en;
   while(be<=en)
   {
      int mid=(be+en)/2;
      if(func(mid))
      {
        re=mid;
        en=mid-1;
      }
      else be=mid+1;
   }

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
