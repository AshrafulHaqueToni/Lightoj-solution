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
   scanf("%d%d",&n,&k);
   vector<int>v;
   for(int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      v.push_back(y);
   }
   sort(v.begin(),v.end());
   int st=v[0];
   int ans=1;
   for(int u:v)
   {
      if(u-k>st)
      {
        ans++;
        st=u;
      }
   }
   printf("Case %d: %d\n",++ii,ans );
    
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
