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
   map<int,int>add,rem;
   scanf("%d",&n);
   set<int>s;
   for(int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      add[x]++;
      rem[y+1]++;
      s.insert(x);
      s.insert(y+1);
   }
   int re=0;
   int tem=0;
   for(int v:s)
   {
      tem+=add[v];
      tem-=rem[v];
      re=max(re,tem);
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
