// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 505
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx];
int radium[mx][mx],uraniam[mx][mx];
int row[mx][mx],col[mx][mx];
int dp[mx][mx];
int vis[mx][mx];
int n,m,k,ii;

int func(int r,int c)
{
   if(r==1 && c==1)return max(radium[1][1],uraniam[1][1]);
   if(vis[r][c]==ii)return dp[r][c];
   vis[r][c]=ii;
   int re=0;
   if(r==1)
   {
     re=max(row[r][c],radium[r][c]+func(r,c-1));
   }
   else if(c==1)
   {
      re=max(col[1][r],uraniam[r][c]+func(r-1,c));
   }
   else
   {
      re=max(col[c][r]+func(r,c-1),row[r][c]+func(r-1,c));
   }
   return dp[r][c]=re;
}

void solve()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)scanf("%d",&uraniam[i][j]);
   }
   for(int i=1;i<=n;i++)
   {
     for(int j=1;j<=m;j++)scanf("%d",&radium[i][j]);
   }
   for(int i=1;i<=n;i++)row[i][1]=uraniam[i][1];
   for(int i=1;i<=m;i++)col[i][1]=radium[1][i];
   for(int i=1;i<=n;i++)
   {
      for(int j=2;j<=m;j++)
      {
        row[i][j]=row[i][j-1]+uraniam[i][j];
      }
   }
   for(int i=1;i<=m;i++)
   {
      for(int j=2;j<=n;j++)col[i][j]=col[i][j-1]+radium[j][i];
   }
   ii++;
   printf("Case %d: %d\n",ii,func(n,m));
    
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
