// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long
#define mod 1000000007

int ar[mx][mx];
char ch[mx];
int dp[mx][mx][mx][3];
int vis[mx][mx][mx][3];
int n,m,k,ii;

int func(int row,int col1,int col2,int opt)
{
  if(row==n && col1==m-1 && col2==m && opt==0)return 0;
  if(vis[row][col1][col2][opt]==ii)return dp[row][col1][col2][opt];
  vis[row][col1][col2][opt]=ii;
  int re=0;
  if(opt==0)
  {
    if(col1+1<col2)re=max(re,ar[row][col1+1]+func(row,col1+1,col2,0));
    re=max(re,func(row,col1,col2,1));
  }
  if(opt==1)
  {
    if(col2<m)re=max(re,ar[row][col2+1]+func(row,col1,col2+1,1));
    if(col1<col2 && row<n)re=max(re,ar[row+1][col1]+ar[row+1][col2]+func(row+1,col1,col2,0));
  }
  return dp[row][col1][col2][opt]=re;
}

void solve()
{
   
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)scanf("%d",&ar[i][j]);
    }
    ii++;
    printf("Case %d: %d\n",ii,func(1,1,1,1)+ar[1][1]);

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
