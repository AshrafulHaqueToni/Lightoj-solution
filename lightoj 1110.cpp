// Created by ash_98
      
#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx],ch1[mx];
int n,m,k,ii;

void solve()
{
   scanf("%s%s",ch+1,ch1+1);
   n=strlen(ch+1);
   m=strlen(ch1+1);
  // cout<<n<<" "<<m<<endl;
   int dp[mx][mx];
   string re[mx][mx];
   for(int i=0;i<=n;i++)dp[i][0]=0,re[i][0]="";
   for(int i=0;i<=m;i++)dp[0][i]=0,re[0][i]="";
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
        if(ch[i]==ch1[j])
        {
          dp[i][j]=1+dp[i-1][j-1];
          re[i][j]=re[i-1][j-1]+ch[i];
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
          dp[i][j]=dp[i-1][j];
          re[i][j]=re[i-1][j];
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
          dp[i][j]=dp[i][j-1];
          re[i][j]=re[i][j-1];
        }
        else
        {
          dp[i][j]=dp[i-1][j];
          re[i][j]=min(re[i-1][j],re[i][j-1]);
        }

      }
   }

   if(dp[n][m]==0)printf("Case %d: :(\n",++ii );
   else printf("Case %d: ",++ii ),cout<<re[n][m]<<"\n";

    
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
