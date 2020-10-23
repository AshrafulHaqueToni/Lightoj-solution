// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 16
#define ll long long
#define mod 1000000007

pair<int,int> ar[mx];
int dp[(1<<mx)+5];
int vis[(1<<mx)+5];
char ch[mx];
int n,m,k,ii;

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}

bool chk(int N,int pos)
{
    return (bool)(N &(1<<pos));
}

int func(int mask){
   if((1<<n)-1==mask)return 0;
   if(vis[mask]==ii)return dp[mask];
   vis[mask]=ii;
   int act=0;
   for(int i=0;i<n;i++)if(!chk(mask,i))act++;
   if(act==1)return dp[mask]=1;

   int re=mx;
   for(int i=0;i<n;i++){
      if(!chk(mask,i))
      {
         for(int j=0;j<n;j++)
         {
            if(i!=j && !chk(mask,j))
            {
               int tem_mask=mask;
               /// take all the point that are staright line along with i,j point
               for(int l=0;l<n;l++)
               {
                  if(ar[i].first*(ar[j].second-ar[l].second)+ar[j].first*(ar[l].second-ar[i].second)+ar[l].first*(ar[i].second-ar[j].second)==0)tem_mask=Set(tem_mask,l);
                  /// check are they line triangle.   
               }
               re=min(re,1+func(tem_mask));
            }
         }
         
         break;
      }
   }
   return dp[mask]=re;
}
void solve()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)scanf("%d%d",&ar[i].first,&ar[i].second);
    ii++;
   printf("Case %d: %d\n",ii,func(0));
    
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
