// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 10005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii,d,s;

vector<pair<int,int>>v,vv;

bool func(int tar)
{
  vv.clear();
  for(int i=0;i<n;i++)
  {
     int dif=v[i].second-tar;
     if(dif>d)return false;
     int baki=sqrt((ll)d*d-(ll)dif*dif);
     vv.push_back({baki+v[i].first,v[i].first-baki});
  }

   sort(vv.begin(),vv.end(),[](const auto& a, const auto& b)
   {
       if(a.first==b.first)
       {
          return a.second<b.second;
       }
       else return a.first<b.first;

   });

   //cout<<tar<<endl;

   //for(auto it:vv)cout<<it.first<<" "<<it.second<<endl;

   int tot=0,idx=0;
   while(idx<n)
   {
      int val=vv[idx].first;
      while(idx<n && vv[idx].second<=val)idx++;
      tot++;
   }
  // cout<<tot<<" "<<endl;
   return tot<=s;

}

void solve()
{
   v.clear();
   scanf("%d%d%d%d",&k,&n,&s,&d);
   for(int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      v.push_back({x,y});
   }
   sort(v.begin(),v.end(),[](const auto& a, const auto& b)
   {
       if(a.first==b.first)
       {
          return a.second<b.second;
       }
       else return a.first<b.first;

   });

   int be=0,en=d;
   int re=-1;
   while(be<=en)
   {
      int mid=(be+en)/2;
      if(func(k-mid))
      {
        re=mid;
        be=mid+1;
      }
      else en=mid-1;
   }
   if(re==-1)printf("Case %d: impossible\n",++ii );
   else printf("Case %d: %d\n",++ii,re);
    
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
