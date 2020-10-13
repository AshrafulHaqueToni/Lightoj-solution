// Created by ash_98
     
#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000007
 
ll ar[mx];
char ch[mx];
ll n,m,k,ii;
 
void solve()
{
   ll add;
   scanf("%lld%lld%lld%lld",&k,&add,&n,&ar[1]);
   for(int i=2;i<=n;i++)ar[i]=(k*ar[i-1]+add)%mod;
   sort(ar+1,ar+1+n);
   ll re=0;
   for(int i=1;i<=n;i++)
   {
   // printf("%d ",ar[i] );
      re-=(n-i)*(ll)ar[i];
      re+=(i-1)*(ll)ar[i];
   }
  // printf("\n");
   printf("Case %lld: %lld\n",++ii,re );
   
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
