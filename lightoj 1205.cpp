// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 19
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
ll dp[mx][mx][mx][3][3];
int vis[mx][mx][mx][3][3];
ll n,m;
int k,ii;



ll func(int len,int en,int be,int boro,int start)
{
    if(en<be){
       return  !boro || (boro && start);
    }
    ll &re=dp[len][en][be][boro][start];
    if(vis[len][en][be][boro][start]==ii)
    {
       return re;
    }
    vis[len][en][be][boro][start]=ii;
    re=0;
    int hi=ar[en];
    if(!boro)hi=9;
    for(int i=0;i<=hi;i++)
    {
      if(i==0 && en==len-1)continue;
      int isstart=start;
      if(isstart)isstart= ar[be]>=i;
      else isstart= ar[be]>i;
      re+=func(len,en-1,be+1,boro && i==hi ,isstart);
    }
    return re;
}

ll messenger(ll val)
{
  if(val<0)return 0;
  if(val==0)return 1;
  ii++;
  int len=0;
   while(val>0){
     ar[len++]=val%10;
     val/=10;
   }
  ll re=1;
  for(int i=len;i>=1;i--)
  {
    ii++;
    re+=func(i,i-1,0,len==i,1);
  }
  return re;


}
void solve()
{
   
    scanf("%lld%lld",&n,&m);
    if(n>m)swap(n,m); 
    printf("Case %d: %lld\n",++k,messenger(m)-messenger(n-1));
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
