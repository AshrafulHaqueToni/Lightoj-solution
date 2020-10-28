// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 16
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int weapon[mx][mx];
int dp[(1<<15)+5];
int vis[(1<<15)+5];
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

int func(int mask)
{
    if(mask==(1<<n)-1)return 0;
    if(vis[mask]==ii)return dp[mask];
    vis[mask]=ii;
    int re=1e9;
    for(int i=0;i<n;i++)
    {
    	if(!chk(mask,i))
    	{
    		int opo_weapon=1;
    		for(int j=0;j<n;j++)
    		{
    			if(chk(mask,j))
    			{
    				opo_weapon=max(opo_weapon,weapon[j][i]);
    			}
    		}
    		re=min(re,(ar[i]+opo_weapon-1)/opo_weapon+func(Set(mask,i)));
    	}
    }
    return dp[mask]=re;
}

void solve()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)scanf("%d",&ar[i]);
   for(int i=0;i<n;i++)
   {
   	 scanf("%s",ch);
   	 for(int j=0;j<n;j++)weapon[i][j]=ch[j]-'0';
   }
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
