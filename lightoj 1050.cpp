// Created by ash_98
     
#include<bits/stdc++.h>
using namespace std;
 
#define mx 505
#define ll double
#define mod 1000000007
 
int ar[mx];
char ch[mx];
ll dp[mx][mx];
bool vis[mx][mx];
int n,m,k,ii;
 
ll func(int a,int b)
{
    if(a==0 && b==0)return 1.00;
    if(a==0)return 1.00;
    if(b<=0)return 0.00;
    if(vis[a][b])return dp[a][b];
    vis[a][b]=true;
    ll re=0.0;
    re+=(ll)a*(func(a-1,b-1)/(ll)(a+b));
    if(b>=2)re+=(ll)b*(func(a,b-2)/(ll)(a+b));
    return dp[a][b]=re;
}

/*
 ll dp[mx][mx][3];
 bool vis[mx][mx][3];

ll func(int a,int b,int ti)
{
    if(a+b==1)
    {
        if(b==1)return 1;
        return 0;
    }
    if(vis[a][b][ti])return dp[a][b][ti];
    vis[a][b][ti]=true;
    ll re=0;
    if(ti==0)
    {
        ll tem=((ll)b)/((ll)a+(ll)b);
        if(b>0)re+=tem*func(a,b-1,1);
        tem=((ll)a)/((ll)a+(ll)b);
        if(a>0)re+=tem*func(a-1,b,1);
       
    }
    if(ti==1)
    {
        if(b>0)re+=func(a,b-1,0);
    }
    return dp[a][b][ti]=re;
}

*/
 
 
void solve()
{
   int x,y;
   scanf("%d%d",&x,&y);
   ii++;
   ll re=func(x,y);
   printf("Case %d: %lf\n",ii,re);
   
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
