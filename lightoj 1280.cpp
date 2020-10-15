// Created by ash_98
     
#include<bits/stdc++.h>
using namespace std;
 
#define mx 20005
#define ll long double
#define mod 1000000007
 
int n,m,k,ii;
vector<pair<ll,ll>>v;
ll tar;
 
bool func(ll ace)
{
  tar=ace/100.0;
  sort(v.begin(),v.end(),[](const auto& a,const auto& b){
    return (a.first-a.second*tar)>(b.first-b.second*tar);
  });
 
  ll got=0,tot=0;
  for(int i=0;i<n-k;i++)got+=v[i].first,tot+=v[i].second;
  return (got/tot)*100.0>=ace;
}
 
void solve()
{
   scanf("%d%d",&n,&k);
   v.clear();
   
   for(int i=1;i<=n;i++)
   {
      ll x,y;
      scanf("%LF%LF",&x,&y);
      v.push_back({x,y});
   }
 
   ll be=0,en=100,re=0;
   int magic=30;
   while(magic--)
   {
      ll mid=(be+en)/2.00;
      if(func(mid))
      {
        re=mid;
        be=mid;
      }
      else en=mid;
   }
   
   printf("Case %d: %0.12LF\n",++ii,re );
 
   
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
