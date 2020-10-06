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
   if(k>n)printf("Case %d: 0\n",++ii);
   else if(k==0)printf("Case %d: 1\n",++ii );
   else
   {
       ll re=1;
       int cnt=1;
       ll ace=n-k+1;
       for(int i=1;i<=k;i++)
       {
           re*=(ace*ace);
           re/=cnt++;
           ace++;
       }
       printf("Case %d: %lld\n",++ii,re );
   }
    
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
