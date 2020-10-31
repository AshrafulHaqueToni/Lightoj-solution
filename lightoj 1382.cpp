// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 1005
#define ll long long
#define mod 1000000007

int sub[mx];
bool root[mx];
ll fact[mx];
char ch[mx];
int n,m,k,ii;
vector<int>g[mx];

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}

ll nCr(int nn,int c)
{
   ll val=fact[nn];
   ll val1=(fact[nn-c]*fact[c])%mod;
   val1=bigmod(val1,mod-2);
   return (val1*val)%mod;

}

ll func(int u)
{
   sub[u]=1;
   ll re=1;
   int tot=0;
   for(int v:g[u])
   {
      re*=func(v);
      re%=mod;
      sub[u]+=sub[v];
      tot+=sub[v];
   }
   for(int v:g[u])
   {
      re*=nCr(tot,sub[v]);
      re%=mod;
      tot-=sub[v];
   }
   return re;
}

void solve()
{
   scanf("%d",&n);
   for(int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      root[y]=true;
      
   }
   int u;
   for(int i=1;i<=n;i++){
    if(!root[i])u=i;
   }
   printf("Case %d: %lld\n",++ii,func(u));
   for(int i=1;i<=n;i++)g[i].clear(),root[i]=false,sub[i]=0;
    
}

int main()
{
  int t=1;
  fact[0]=1;
  for(int i=1;i<=1000;i++)fact[i]=(fact[i-1]*i)%mod;
  scanf("%d",&t);
  while(t--)
  {
    solve();
  }

  return 0;
}
