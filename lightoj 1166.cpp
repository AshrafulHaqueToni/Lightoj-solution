// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int n,m,k,ii;

void solve()
{
   
    scanf("%d",&n);
    map<int,int>mp,mp1;
    for(int i=1;i<=n;i++)scanf("%d",&ar[i]),mp[ar[i]]=i,mp1[i]=ar[i];
    int re=0;
    for(int i=1;i<=n;i++)
    {
      if(mp[i]!=i)
      {
          re++;
          int val=mp1[i];
          int pos=mp[i];
          mp[i]=i;
          mp1[i]=i;
          mp[val]=pos;
          mp1[pos]=val;

      }
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
